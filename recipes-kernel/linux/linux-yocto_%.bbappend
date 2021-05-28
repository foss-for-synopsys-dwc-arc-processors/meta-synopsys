FILESEXTRAPATHS_prepend := "${THISDIR}/${PN}:"

COMPATIBLE_MACHINE_append = "|hsdk|hapshs"

KERNEL_CC_append = " ${TOOLCHAIN_OPTIONS}"

SRC_URI += "\
    "
