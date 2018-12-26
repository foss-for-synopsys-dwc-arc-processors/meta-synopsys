FILESEXTRAPATHS_append := "${THISDIR}/files:"
SRC_URI_append = " \
	file://0001-Disable-suspending-idle-sinks.patch \
	file://0001-Modify-daemon.conf-for-lack-of-hw-resources.patch \
"


