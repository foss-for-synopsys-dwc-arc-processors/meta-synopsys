BINUTILS_TAG = "arc-2017.09-release"
SRC_URI[sha256sum] = "2ea086fd5521e942926dd6ff6922ce31c29ee7ffc754fca3d06385e0f27600f8"
SRC_URI = "\
	https://github.com/foss-for-synopsys-dwc-arc-processors/binutils-gdb/archive/${BINUTILS_TAG}.tar.gz;downloadfilename=binutils-${PV}.tar.gz \
	file://0004-Point-scripts-location-to-libdir.patch \
	file://0008-Add-the-armv5e-architecture-to-binutils.patch \
	file://0009-don-t-let-the-distro-compiler-point-to-the-wrong-ins.patch \
	file://0012-Change-default-emulation-for-mips64-linux.patch \
	file://0014-fix-the-incorrect-assembling-for-ppc-wait-mnemonic.patch \
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
