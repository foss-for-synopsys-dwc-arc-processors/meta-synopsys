require gcc-${PV}.inc
require recipes-devtools/gcc/gcc-runtime.inc

RUNTIMELIBITM_arc = ""

FILES_libgomp-dev += "\
	${libdir}/gcc/${TARGET_SYS}/${BINV}/include/openacc.h \
"
