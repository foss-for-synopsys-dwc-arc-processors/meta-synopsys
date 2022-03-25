DESCRIPTION = "Kernel image for the ARC architecture"
SUMMARY = "ARCv3 dev kernel recipe"
SECTION = "kernel"
LICENSE = "GPLv2"

inherit kernel

LIC_FILES_CHKSUM = "file://COPYING;md5=6bc538ed5bd9a7fc9398086aedcd7e46"
KERNEL_VERSION_SANITY_SKIP = "1"

SRCREV = "a154b5efb4abedb0244f135fe93fa727c40ef4d1"
BRANCH = "arc64"
SRC_URI = "git://github.com/foss-for-synopsys-dwc-arc-processors/linux.git;protocol=https;branch=${BRANCH}"

S = "${WORKDIR}/git"

DEPENDS += " libgcc"
KERNEL_CC:append = " ${TOOLCHAIN_OPTIONS}"

KERNEL_DEFCONFIG:hapshs5x = "haps_hs5x"
KERNEL_DEFCONFIG:hapshs6x = "haps_arc64"

KERNEL_CONFIG_COMMAND = "oe_runmake -C ${S} O=${B} ${KERNEL_DEFCONFIG}_defconfig"

KERNEL_CLASSES = ""
