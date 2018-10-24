FILESEXTRAPATHS_prepend := "${THISDIR}/mozjs:"
SRC_URI_append += "\
    file://0001-Enable-double-conversion-for-arc-in-mozjs.patch;patchdir=../../ \
    file://0001-Fix-page_size-crash-for-ARC.patch;patchdir=../../ \
"

