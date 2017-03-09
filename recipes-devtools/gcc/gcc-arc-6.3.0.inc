require recipes-devtools/gcc/gcc-common.inc

SRCREV = "e18f1496a2f405188c3a0ab64bc593a7e0c422ab"
SRC_URI = "\
	git://github.com/foss-for-synopsys-dwc-arc-processors/gcc;protocol=https;branch=arc-6.x-dev \
	file://0014-optional-libstdc.patch \
	file://0032-gcc-4.8-won-t-build-with-disable-dependency-tracking.patch \
"

BINV = "6.3.0"

S = "${TMPDIR}/work-shared/gcc-${PV}-${PR}/git"
B = "${WORKDIR}/git/build.${HOST_SYS}.${TARGET_SYS}"

DEPENDS =+ "mpfr gmp libmpc zlib"
NATIVEDEPS = "mpfr-native gmp-native libmpc-native zlib-native"

JAVA = ""
FORTRAN = ""

LICENSE = "GPL-3.0-with-GCC-exception & GPLv3"
LIC_FILES_CHKSUM = "\
	file://COPYING;md5=59530bdf33659b29e73d4adb9f9f6552 \
	file://COPYING.LIB;md5=2d5025d4aa3495befef8f17206a5b0a1 \
	file://COPYING3;md5=d32239bcb673463ab874e80d47fae504 \
	file://COPYING3.LIB;md5=6a6a8e020838b23406c81b19c1d46df6 \
	file://include/COPYING;md5=59530bdf33659b29e73d4adb9f9f6552 \
	file://include/COPYING3;md5=d32239bcb673463ab874e80d47fae504 \
	file://libiberty/COPYING.LIB;md5=a916467b91076e631dd8edb7424769c7 \
"

LTO = "--enable-lto"

EXTRA_OECONF_BASE = "\
	${LTO} \
	--enable-libssp \
	--enable-libitm \
	--disable-bootstrap \
	--disable-libmudflap \
	--with-system-zlib \
	--with-linker-hash-style=${LINKER_HASH_STYLE} \
	--enable-linker-build-id \
	--with-ppl=no \
	--with-cloog=no \
	--enable-checking=release \
	--enable-cheaders=c_global \
	--without-isl \
"

EXTRA_OECONF_INITIAL = "\
	--disable-libmudflap \
	--disable-libgomp \
	--disable-libitm \
	--disable-libquadmath \
	--with-system-zlib \
	--disable-lto \
	--disable-plugin \
	--enable-decimal-float=no \
	--without-isl \
	gcc_cv_libc_provides_ssp=yes \
"

EXTRA_OECONF_append_libc-uclibc = " --disable-decimal-float "
EXTRA_OECONF_append = "--with-cpu=archs"

EXTRA_OECONF_PATHS = "\
	--with-gxx-include-dir=/not/exist{target_includedir}/c++/${BINV} \
	--with-sysroot=/not/exist \
	--with-build-sysroot=${STAGING_DIR_TARGET} \
"
