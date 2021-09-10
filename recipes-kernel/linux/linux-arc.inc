DESCRIPTION = "Kernel image for the ARC architecture"
SECTION = "kernel"

LICENSE = "GPLv2"

inherit kernel

SRC_URI = "\
    https://www.kernel.org/pub/linux/kernel/v5.x/linux-${PV}.tar.xz\
    "

S = "${WORKDIR}/linux-${PV}"

DEPENDS += " libgcc"
KERNEL_CC:append = " ${TOOLCHAIN_OPTIONS}"

KERNEL_DEFCONFIG:axs101 = "axs101"
KERNEL_DEFCONFIG:axs103 = "axs103_smp"
KERNEL_DEFCONFIG:hsdk = "hsdk"
KERNEL_DEFCONFIG:nsim700 = "nsim_700"
KERNEL_DEFCONFIG:hapshs = "haps_hs"

KERNEL_CONFIG_COMMAND = "oe_runmake -C ${S} O=${B} ${KERNEL_DEFCONFIG}_defconfig"

KERNEL_CLASSES = ""
