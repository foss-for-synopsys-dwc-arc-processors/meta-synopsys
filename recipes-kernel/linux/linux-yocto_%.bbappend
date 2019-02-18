FILESEXTRAPATHS_prepend := "${THISDIR}/${PN}:"

COMPATIBLE_MACHINE_append = "|hsdk|nsimhs"

KERNEL_CC_append = " ${TOOLCHAIN_OPTIONS}"

SRC_URI += "\
    file://0001-devres-Align-data-to-ARCH_KMALLOC_MINALIGN.patch \
    file://0001-ARC-Explicitly-set-ARCH_SLAB_MINALIGN-8.patch \
    "
