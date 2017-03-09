require gcc-${PV}.inc
require recipes-devtools/gcc/libgcc.inc

EXTRA_OEMAKE_append = "${TUNE_CCARGS}"
