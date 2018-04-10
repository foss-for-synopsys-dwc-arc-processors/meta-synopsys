require gcc-${PV}.inc
require recipes-devtools/gcc/libgcc.inc
INSANE_SKIP_${PN} = "ldflags staticdev"
INSANE_SKIP_${PN}-dev = "ldflags staticdev"
