FILESEXTRAPATHS:prepend := "${THISDIR}/${PN}:"

# ARCv3 port is still not upstream yet
SRC_URI:arc64 = "git://github.com/foss-for-synopsys-dwc-arc-processors/libffi.git;branch=arc64;protocol=https"

S:arc64 = "${WORKDIR}/git"

LIC_FILES_CHKSUM:arc64 = "file://LICENSE;md5=05fd00eaa848fefa07df5ea3460f874e"

SRCREV:arc64 = "2a5f158887aa23dd5f3a705716b5fcd44419d74a"

EXTRA_OECONF:remove:arc64 = "--disable-exec-static-tramp"
