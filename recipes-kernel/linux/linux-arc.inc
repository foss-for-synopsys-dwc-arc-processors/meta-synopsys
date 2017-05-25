DESCRIPTION = "Kernel image for the ARC architecture"
SECTION = "kernel"

LICENSE = "GPLv2"

inherit kernel

SRC_URI = "https://www.kernel.org/pub/linux/kernel/v4.x/linux-${PV}.tar.xz \
	file://0001-arc-Remove-sometimes-misleading-toolchain-check.patch \
"
S = "${WORKDIR}/linux-${PV}"

DEPENDS += " libgcc"
KERNEL_CC_append = " ${TOOLCHAIN_OPTIONS}"

KERNEL_DEFCONFIG_axs103 = "axs103_smp"
KERNEL_DEFCONFIG_nsimhs = "nsim_hs"
KERNEL_DEFCONFIG_nsimoscihs = "nsimosci_hs"
KERNEL_CONFIG_COMMAND = "oe_runmake -C ${S} O=${B} ${KERNEL_DEFCONFIG}_defconfig"

KERNEL_IMAGETYPE = "vmlinux"
KERNEL_OUTPUT_DIR = "."
KERNEL_CLASSES = ""

do_configure_append() {
	echo 'CONFIG_INITRAMFS_SOURCE=""' >> ${B}/.config
}
