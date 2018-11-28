FILESEXTRAPATHS_prepend := "${THISDIR}/qtbase:"
SRC_URI += "\
    file://0001-Add-ARC-support-in-double-conversion.patch \
    file://0002-Fix-build-for-ARC-with-glibc-due-to-lack-of-FENV.patch \
"
