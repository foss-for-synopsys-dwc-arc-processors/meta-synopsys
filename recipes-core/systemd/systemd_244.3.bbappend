FILESEXTRAPATHS_prepend := "${THISDIR}/files:"
SRC_URI_append += "\
    file://0001-network-fix-static-assertion-on-IPPROTO_MAX-range.patch; \
"
