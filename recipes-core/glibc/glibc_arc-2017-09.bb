require recipes-core/glibc/glibc.inc

INSANE_SKIP_${PN} = "file-rdeps"
INSANE_SKIP_${PN}-dev = "file-rdeps"
INSANE_SKIP_nscd = "file-rdeps"
INSANE_SKIP_tzcode = "file-rdeps"



LIC_FILES_CHKSUM = "file://LICENSES;md5=e9a558e243b36d3209f380deb394b213 \
		    file://COPYING;md5=b234ee4d69f5fce4486a80fdaf4a4263 \
		    file://posix/rxspencer/COPYRIGHT;md5=dc5485bb394a13b2332ec1c785f5d83a \
		    file://COPYING.LIB;md5=4fbd65380cdd255951079008b364516c \
"

DEPENDS += "gperf-native"

RELEASE = "2017.09-release"
SRC_URI[sha256sum] = "5aa9adeac09727db0b8a52794186563771e74d70410e9fd86431e339953fd4bb"
SRC_URI = "https://github.com/foss-for-synopsys-dwc-arc-processors/glibc/archive/arc-${RELEASE}.tar.gz \
           file://etc/ld.so.conf \
           file://generate-supported.mk \
	   ${NATIVESDKFIXES} \
"

NATIVESDKFIXES ?= ""
NATIVESDKFIXES_class-nativesdk = "\
           file://0001-nativesdk-glibc-Look-for-host-system-ld.so.cache-as-.patch \
           file://0002-nativesdk-glibc-Fix-buffer-overrun-with-a-relocated-.patch \
           file://0003-nativesdk-glibc-Raise-the-size-of-arrays-containing-.patch \
           file://0004-nativesdk-glibc-Allow-64-bit-atomics-for-x86.patch \
"

S = "${WORKDIR}/glibc-arc-${RELEASE}"
B = "${WORKDIR}/build-${TARGET_SYS}"

PACKAGES_DYNAMIC = ""

# the -isystem in bitbake.conf screws up glibc do_stage
BUILD_CPPFLAGS = "-I${STAGING_INCDIR_NATIVE}"
TARGET_CPPFLAGS = "-I${STAGING_DIR_TARGET}${includedir}"

GLIBC_BROKEN_LOCALES = ""
#
# We will skip parsing glibc when target system C library selection is not glibc
# this helps in easing out parsing for non-glibc system libraries
#
COMPATIBLE_HOST_libc-musl_class-target = "null"
COMPATIBLE_HOST_libc-uclibc_class-target = "null"

EXTRA_OECONF = "--enable-kernel=${OLDEST_KERNEL} \
                --without-cvs --disable-profile \
                --disable-debug --without-gd \
                --enable-clocale=gnu \
                --enable-add-ons \
                --with-headers=${STAGING_INCDIR} \
                --without-selinux \
                --enable-obsolete-rpc \
                ${GLIBC_EXTRA_OECONF}"

EXTRA_OECONF += "${@get_libc_fpu_setting(bb, d)}"
EXTRA_OECONF += "${@bb.utils.contains('DISTRO_FEATURES', 'libc-inet-anl', '--enable-nscd', '--disable-nscd', d)}"


do_patch_append() {
    bb.build.exec_func('do_fix_readlib_c', d)
}

do_fix_readlib_c () {
	sed -i -e 's#OECORE_KNOWN_INTERPRETER_NAMES#${EGLIBC_KNOWN_INTERPRETER_NAMES}#' ${S}/elf/readlib.c
}

do_configure () {
# override this function to avoid the autoconf/automake/aclocal/autoheader
# calls for now
# don't pass CPPFLAGS into configure, since it upsets the kernel-headers
# version check and doesn't really help with anything
        (cd ${S} && gnu-configize) || die "failure in running gnu-configize"
        find ${S} -name "configure" | xargs touch
        CPPFLAGS="" oe_runconf
}

rpcsvc = "bootparam_prot.x nlm_prot.x rstat.x \
	  yppasswd.x klm_prot.x rex.x sm_inter.x mount.x \
	  rusers.x spray.x nfs_prot.x rquota.x key_prot.x"

do_compile () {
	# -Wl,-rpath-link <staging>/lib in LDFLAGS can cause breakage if another glibc is in staging
	unset LDFLAGS
	base_do_compile
	(
		cd ${S}/sunrpc/rpcsvc
		for r in ${rpcsvc}; do
			h=`echo $r|sed -e's,\.x$,.h,'`
			rm -f $h
			${B}/sunrpc/cross-rpcgen -h $r -o $h || bbwarn "${PN}: unable to generate header for $r"
		done
	)
	echo "Adjust ldd script"
	if [ -n "${RTLDLIST}" ]
	then
		prevrtld=`cat ${B}/elf/ldd | grep "^RTLDLIST=" | sed 's#^RTLDLIST="\?\([^"]*\)"\?$#\1#'`
		if [ "${prevrtld}" != "${RTLDLIST}" ]
		then
			sed -i ${B}/elf/ldd -e "s#^RTLDLIST=.*\$#RTLDLIST=\"${prevrtld} ${RTLDLIST}\"#"
		fi
	fi

}

# Use the host locale archive when built for nativesdk so that we don't need to
# ship a complete (100MB) locale set.
do_compile_prepend_class-nativesdk() {
    echo "complocaledir=/usr/lib/locale" >> ${S}/configparms
}

require recipes-core/glibc/glibc-package.inc

BBCLASSEXTEND = "nativesdk"

