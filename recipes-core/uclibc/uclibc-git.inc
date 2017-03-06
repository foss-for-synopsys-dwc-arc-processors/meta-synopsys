SRCREV = "61afc0c37647e0736edbc577f0d2fc1668269c64"

FILESEXTRAPATHS =. "${FILE_DIRNAME}/uclibc-git:"

SRC_URI = " \
	git://github.com/foss-for-synopsys-dwc-arc-processors/uClibc;protocol=https;branch=arc-2016.09 \
        file://uClibc.machine \
        file://uClibc.distro \
        file://obstack.cfg \
        file://locale.cfg \
"
S = "${WORKDIR}/git"

UPSTREAM_CHECK_GITTAGREGEX = "(?P<pver>\d+\.\d+(\.\d+)*)"
