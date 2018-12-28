LICENSE = "GPLv2 & GPLv3 & LGPLv2 & LGPLv3"
LIC_FILES_CHKSUM = "file://COPYING;md5=59530bdf33659b29e73d4adb9f9f6552 \
		    file://COPYING3;md5=d32239bcb673463ab874e80d47fae504 \
		    file://COPYING3.LIB;md5=6a6a8e020838b23406c81b19c1d46df6 \
		    file://COPYING.LIB;md5=9f604d8a4f8e74f4f5140845a21b6674"

SRCREV ?= "arc-2018.09-release-gdb"

SRC_URI = "git://github.com/foss-for-synopsys-dwc-arc-processors/binutils-gdb;protocol=https;branch=arc-2018.09-gdb \
           file://0002-make-man-install-relative-to-DESTDIR.patch \
           file://0006-Dont-disable-libreadline.a-when-using-disable-static.patch \
           file://0008-Use-exorted-definitions-of-SIGRTMIN.patch \
           file://0009-Change-order-of-CFLAGS.patch \
           file://0010-resolve-restrict-keyword-conflict.patch \
           file://package_devel_gdb_patches_120-sigprocmask-invalid-call.patch \
           file://gdb-Fix-ia64-defining-TRAP_HWBKPT-before-including-g.patch \
"

S = "${WORKDIR}/git"

# Currently ARC GCC generates invalid CFA information for instructions in
# delay-slot which is used in run-time for stack unwinding
# which in its turn is used for exception handling.
#
# See https://github.com/foss-for-synopsys-dwc-arc-processors/gcc/issues/69
# for more technical details.
#
# For now we're working this around compiling GDB with "-Os"
# which fortunately generates a bit different code and so we at least
# don't get segfault of GDB left and right.
CFLAGS_append = " -Os"
CXXFLAGS_append = " -Os"
