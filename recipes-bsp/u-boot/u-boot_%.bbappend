FILESEXTRAPATHS_prepend := "${THISDIR}/files:"

SRC_URI += " file://uboot.env"

do_deploy_append() {
	install -m 0644 ${WORKDIR}/uboot.env ${DEPLOYDIR}/uboot.env
}
