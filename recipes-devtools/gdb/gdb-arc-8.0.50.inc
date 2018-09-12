GDB_TAG = "arc-2018.03-release-gdb"
SRC_URI[sha256sum] = "02e0b3ba623500dda9d729d2342bf0b5b75aafe232ce271baa4342b8884cb0b2"
SRC_URI = " \
	https://github.com/foss-for-synopsys-dwc-arc-processors/binutils-gdb/archive/${GDB_TAG}.tar.gz;downloadfilename=gdb-${PV}.tar.gz \
	file://0002-make-man-install-relative-to-DESTDIR.patch \
	file://0003-mips-linux-nat-Define-_ABIO32-if-not-defined.patch \
	file://0004-ppc-ptrace-Define-pt_regs-uapi_pt_regs-on-GLIBC-syst.patch \
	file://0006-Dont-disable-libreadline.a-when-using-disable-static.patch \
	file://0007-use-asm-sgidefs.h.patch \
	file://0008-Use-exorted-definitions-of-SIGRTMIN.patch \
	file://0010-resolve-restrict-keyword-conflict.patch \
"

S = "${WORKDIR}/binutils-gdb-${GDB_TAG}"

LICENSE = "GPLv2 & GPLv3 & LGPLv2 & LGPLv3"
LIC_FILES_CHKSUM = " \
	file://COPYING;md5=59530bdf33659b29e73d4adb9f9f6552 \
	file://COPYING.LIB;md5=9f604d8a4f8e74f4f5140845a21b6674 \
	file://COPYING3;md5=d32239bcb673463ab874e80d47fae504 \
	file://COPYING3.LIB;md5=6a6a8e020838b23406c81b19c1d46df6 \
"
