require recipes-devtools/gcc/gcc-${PV}.inc
require recipes-devtools/gcc/libgcc.inc
INSANE_SKIP_${PN} = "ldflags staticdev"
INSANE_SKIP_${PN}-dev = "ldflags staticdev"
INSANE_SKIP_${PN} = "staticdev"
INSANE_SKIP_libgcc_eh = "staticdev"
INSANE_SKIP_libgcc_eh-dev = "staticdev"
INSANE_SKIP_libgcov-dev = "staticdev"
INSANE_SKIP_libgcov = "staticdev"
