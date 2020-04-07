FILESEXTRAPATHS_prepend := "${THISDIR}/files:"
SRC_URI += "file://0031-Add-ARC-architecture.patch \
"
CFLAGS_append += " -Wno-error"
EXTRA_OECONF += " --disable-werror"
