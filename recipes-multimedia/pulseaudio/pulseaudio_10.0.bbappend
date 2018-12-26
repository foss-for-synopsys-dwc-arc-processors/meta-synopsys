FILESEXTRAPATHS_append := "${THISDIR}/files:"
SRC_URI_append = " \
	file://default.pa \
	file://daemon.conf \
"

do_install_append(){

    install -m 0644 ${WORKDIR}/daemon.conf ${D}/etc/pulse/daemon.conf
    install -m 0644 ${WORKDIR}/default.pa ${D}/etc/pulse/default.pa
}


