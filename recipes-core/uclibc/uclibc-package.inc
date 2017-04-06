# Ensure the uclibc-dev package is processed before uclibc-staticdev to allow
# *_nonshared.a libraries to be packaged in the uclibc-dev package.
PACKAGES = "ldd uclibc-utils uclibc-gconv uclibc-thread-db uclibc-argp uclibc-backtrace ${PN}-dbg ${PN}-dev ${PN}-staticdev ${PN}-doc ${PN}"

FILES_ldd = "${bindir}/ldd"
FILES_uclibc-utils = "${bindir} ${sbindir}"
FILES_uclibc-gconv = "${libdir}/gconv"
FILES_uclibc-thread-db = "${base_libdir}/libthread_db*"
FILES_uclibc-argp = "${base_libdir}/libuargp-*.so ${base_libdir}/libuargp*.so.*"
FILES_uclibc-backtrace = "${base_libdir}/libubacktrace-*.so ${base_libdir}/libubacktrace*.so.*"

# The last line (gdb and lib1) is for uclinux-uclibc builds
uclibc_baselibs = "${base_libdir}/ld*.so.* ${base_libdir}/ld*.so \
                   ${base_libdir}/libc*.so.* ${base_libdir}/libuClibc-*.so \
                   ${libdir}/libc.gdb ${libdir}/libc ${base_libdir}/lib1.so \
                  "
FILES_SOLIBSDEV = "${libdir}/lib*${SOLIBSDEV}"
FILES_${PN}-dev += "\
        ${libdir}/lib*.so \
        ${libdir}/*_nonshared.a \
        ${libdir}/[S]*crt[1in].o \
        ${libdir}/crtreloc*.o \
        ${includedir}/*.h ${includedir}/*/*.h \
       "
FILES_${PN} = "${sysconfdir} ${uclibc_baselibs} /sbin/ldconfig \
               ${libexecdir} ${datadir}/zoneinfo ${libdir}/locale"
