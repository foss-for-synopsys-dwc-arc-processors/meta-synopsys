FILESEXTRAPATHS_prepend := "${THISDIR}/mozjs:"
SRC_URI_append += "\
    file://0001-Add-ARC-CPU-support.patch; \
    file://0001-arc-Disable-atomic-operations.patch; \
"

