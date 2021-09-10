FILESEXTRAPATHS:prepend := "${THISDIR}/${PN}:"

COMPATIBLE_MACHINE:append = "|hsdk|hapshs"

KERNEL_CC:append = " ${TOOLCHAIN_OPTIONS}"

SRC_URI += "\
    "
