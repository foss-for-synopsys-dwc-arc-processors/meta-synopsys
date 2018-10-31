FILESEXTRAPATHS_prepend := "${THISDIR}/linux-arc:"
DESCRIPTION = "Kernel image for the ARC architecture"
SECTION = "kernel"

LICENSE = "GPLv2"

inherit kernel

SRC_URI = "https://www.kernel.org/pub/linux/kernel/v4.x/linux-${PV}.tar.xz \
	file://0001-Disable-IOC.patch \
	file://0001-ETHNAVIV-don-t-print-command-dump.patch \
	file://0002-drm-fb-helper-Reject-all-pixel-format-changing-reque.patch \
	file://0002-etnaviv-Make-archtecture-and-platform-agnostic.patch \
	file://0003-etnaviv-setup-dma_mask.patch \
	file://0004-devres-Really-align-data-field-to-unsigned-long-long.patch \
	file://0005-Add-support-of-Vivante-GPU.patch \
	file://0006-Use-dev-mmcblk0p2-as-rootfs-storage.patch \
	file://0007-Enable-drivers-for-AGL-image-in-hsdk_defconfig.patch \
	file://0008-Disable-optimizations-for-security-keys-ARC-tls-tool.patch \
"
S = "${WORKDIR}/linux-${PV}"

DEPENDS += " libgcc"
KERNEL_CC_append = " ${TOOLCHAIN_OPTIONS}"

KERNEL_DEFCONFIG_hsdk = "hsdk"
KERNEL_DEFCONFIG_nsimhs = "nsim_hs"
KERNEL_CONFIG_COMMAND = "oe_runmake -C ${S} O=${B} ${KERNEL_DEFCONFIG}_defconfig"

KERNEL_CLASSES = ""

do_configure_append() {
	echo 'CONFIG_INITRAMFS_SOURCE=""' >> ${B}/.config
}
