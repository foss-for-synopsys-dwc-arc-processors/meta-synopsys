#BINUTILS_TAG = "arc-2018.03-release"
SRC_URI[sha256sum] = "c59c2794336e92c3bfa6367ff9a38e933d901e41a1fdacda95c220b2055d1d11"
#SRCREV = "${AUTOREV}"
SRCREV ="afcc795bc21f5d2972e9bd9d5c52eb91834bf0d0"
SRC_URI = "\
	git://github.com/foss-for-synopsys-dwc-arc-processors/binutils-gdb;branch=arc-2018.09;protocol=http; \
	file://0004-Point-scripts-location-to-libdir.patch \
	file://0008-Add-the-armv5e-architecture-to-binutils.patch \
	file://0009-don-t-let-the-distro-compiler-point-to-the-wrong-ins.patch \
	file://0012-Change-default-emulation-for-mips64-linux.patch \
	file://0014-fix-the-incorrect-assembling-for-ppc-wait-mnemonic.patch \
"

S = "${WORKDIR}/git"

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
