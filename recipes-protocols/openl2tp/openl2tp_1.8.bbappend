FILESEXTRAPATHS_prepend := "${THISDIR}/${PN}-${PV}:"

SRC_URI_append_libc-uclibc = "\
           file://0001-l2tp_api-Included-needed-headers.patch \
	   file://0004-Adjust-for-linux-kernel-headers-assumptions-on-glibc.patch \
	   file://0002-user-ipv6-structures.patch \
           "

DEPENDS_append_libc-uclibc = " libtirpc"
CFLAGS_append_libc-uclibc = " -I${STAGING_INCDIR}/tirpc"
CPPFLAGS_append_libc-uclibc = " -I${STAGING_INCDIR}/tirpc"
LDFLAGS_append_libc-uclibc = " -ltirpc"

EXTRA_OEMAKE_append += 'CPPFLAGS="${CPPFLAGS}" OPT_CFLAGS="${CFLAGS}"'

do_compile_prepend() {
	sed -i -e 's:CPPFLAGS-y:CPPFLAGS:g' ${S}/Makefile
}