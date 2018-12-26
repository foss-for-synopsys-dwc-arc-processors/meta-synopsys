FILESEXTRAPATHS_prepend := "${THISDIR}/linux-arc:"
DESCRIPTION = "Kernel image for the ARC architecture"
SECTION = "kernel"

LICENSE = "GPLv2"

inherit kernel

SRC_URI = "https://www.kernel.org/pub/linux/kernel/v4.x/linux-${PV}.tar.xz \
	file://0002-etnaviv-Make-archtecture-and-platform-agnostic.patch \
	file://0004-ARC-plat-hsdk-Add-support-of-Vivante-GPU.patch \
	file://0006-devres-Really-align-data-field-to-unsigned-long-long.patch \
	file://0007-ETHNAVIV-don-t-print-command-dump.patch \
	file://1001-Agl-hsdk-defconfig.patch \
	file://0006-Use-dev-mmcblk0p2-as-rootfs-storage.patch \
	file://0001-DRM-UDL-get-rid-of-useless-vblank-initialization.patch \
	file://3003-Experimental-ARC-increase-memory-to-1.5GB.patch \
"
#file://2001-ARC-prevent-showing-irrelevant-exception-info-in-sig.patch 
#file://2002-ARC-split-show_faulting_vma-for-logic-and-representa.patch 
#file://2003-ARC-ARCv2-Introduce-SmaRT-support.patch 
#file://3003-Experimental-ARC-increase-memory-to-1.5GB.patch 

#        file://4001-HSDK-add-highmem-zone.patch 
#        file://4002-ARC-temporary-disable-IOC.patch 
#        file://4003-ARC-cache-ops-add-assertions.patch 


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
