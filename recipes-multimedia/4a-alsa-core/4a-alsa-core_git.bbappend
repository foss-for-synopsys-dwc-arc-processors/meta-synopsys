FILESEXTRAPATHS_prepend := "${THISDIR}/files:"
SRC_URI_append += "\
    file://0001-Set-Wno-error-maybe-uninitialized-for-ARC.patch; \
"

