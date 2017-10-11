require gcc-${PV}.inc
require recipes-devtools/gcc/gcc-runtime.inc

RUNTIMELIBITM_arc = ""

FILES_libgomp-dev += "\
	${libdir}/gcc/${TARGET_SYS}/${BINV}/include/openacc.h \
"

do_configure () {
	export CXX="${CXX} -nostdinc++"

	for d in libgcc ${RUNTIMETARGET}; do
		echo "Configuring $d"
		rm -rf ${B}/${TARGET_SYS}/$d/
		mkdir -p ${B}/${TARGET_SYS}/$d/
		cd ${B}/${TARGET_SYS}/$d/
		chmod a+x ${S}/$d/configure
		relpath=${@os.path.relpath("${S}/$d", "${B}/${TARGET_SYS}/$d")}
		$relpath/configure ${CONFIGUREOPTS} ${EXTRA_OECONF}
	done
}
