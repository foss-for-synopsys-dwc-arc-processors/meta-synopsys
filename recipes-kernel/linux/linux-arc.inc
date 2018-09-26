DESCRIPTION = "Kernel image for the ARC architecture"
SECTION = "kernel"

LICENSE = "GPLv2"

inherit kernel

SRC_URI = "\
    https://www.kernel.org/pub/linux/kernel/v4.x/linux-${PV}.tar.xz\
    file://0001-ARC-Get-rid-of-toolchain-check.patch\
    file://0009-UDL-add-pseudo-deferred-io-for-modeset-drive.patch \
    file://0010-UDL-defio-add-fb-lock-and-required-checks.patch \
    "

S = "${WORKDIR}/linux-${PV}"

DEPENDS += " libgcc"
KERNEL_CC_append = " ${TOOLCHAIN_OPTIONS}"

KERNEL_DEFCONFIG_axs101 = "axs101"
KERNEL_DEFCONFIG_axs103 = "axs103_smp"
KERNEL_DEFCONFIG_hsdk = "hsdk"
KERNEL_DEFCONFIG_nsim700 = "nsim_700"
KERNEL_DEFCONFIG_nsimhs = "nsim_hs"

KERNEL_CONFIG_COMMAND = "oe_runmake -C ${S} O=${B} ${KERNEL_DEFCONFIG}_defconfig"

KERNEL_CLASSES = ""
