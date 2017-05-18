BINUTILS_TAG = "arc-2017.03-rc2"
SRC_URI[sha256sum] = "09535f0dea6829a45323e91393ea8484afde9cf578c80e9b5cc96fc0e63d6cf7"
SRC_URI = "\
	https://github.com/foss-for-synopsys-dwc-arc-processors/binutils-gdb/archive/${BINUTILS_TAG}.tar.gz;downloadfilename=binutils-${PV}.tar.gz \
	file://0003-gprof-add-uclibc-support-to-configure.patch \
	file://0004-Point-scripts-location-to-libdir.patch \
	file://0006-Explicitly-link-with-libm-on-uclibc.patch \
	file://0007-Use-libtool-2.4.patch \
	file://0008-Add-the-armv5e-architecture-to-binutils.patch \
	file://0009-don-t-let-the-distro-compiler-point-to-the-wrong-ins.patch \
	file://0010-warn-for-uses-of-system-directories-when-cross-linki.patch \
	file://0011-Fix-rpath-in-libtool-when-sysroot-is-enabled.patch \
	file://0012-Change-default-emulation-for-mips64-linux.patch \
	file://0013-Add-support-for-Netlogic-XLP.patch \
	file://0014-fix-the-incorrect-assembling-for-ppc-wait-mnemonic.patch \
	file://0015-sync-with-OE-libtool-changes.patch \
	file://0016-Put-soname-in-the-version-definition-section.patch \
"

S = "${WORKDIR}/binutils-gdb-${BINUTILS_TAG}"

LIC_FILES_CHKSUM = "\
	file://COPYING;md5=59530bdf33659b29e73d4adb9f9f6552 \
	file://COPYING.LIB;md5=9f604d8a4f8e74f4f5140845a21b6674 \
	file://COPYING3;md5=d32239bcb673463ab874e80d47fae504 \
	file://COPYING3.LIB;md5=6a6a8e020838b23406c81b19c1d46df6 \
	file://gas/COPYING;md5=d32239bcb673463ab874e80d47fae504 \
	file://include/COPYING;md5=59530bdf33659b29e73d4adb9f9f6552 \
	file://include/COPYING3;md5=d32239bcb673463ab874e80d47fae504 \
	file://libiberty/COPYING.LIB;md5=a916467b91076e631dd8edb7424769c7 \
	file://bfd/COPYING;md5=d32239bcb673463ab874e80d47fae504 \
"

do_configure_prepend() {
	rm -rf ${S}/gdb ${S}/libdecnumber ${S}/readline ${S}/sim
}
