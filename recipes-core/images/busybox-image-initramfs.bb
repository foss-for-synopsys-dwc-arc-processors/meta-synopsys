LICENSE = "MIT"
LIC_FILES_CHKSUM = "file://${COREBASE}/meta/COPYING.MIT;md5=3da9cfbcb788c80a0384361b4de20420"

IMAGE_FSTYPES = "${INITRAMFS_FSTYPES}"
IMAGE_FEATURES = "debug-tweaks"
IMAGE_LINGUAS = ""

INITRAMFS_IMAGE = "busybox-image-initramfs"

VIRTUAL-RUNTIME_login_manager = "busybox"
VIRTUAL-RUNTIME_init_manager = "sysvinit"
VIRTUAL-RUNTIME_initscripts = "initscripts"

IMAGE_INSTALL = " \
	${VIRTUAL-RUNTIME_login_manager} \
	${VIRTUAL-RUNTIME_init_manager} \
	${VIRTUAL-RUNTIME_initscripts} \
	base-files base-passwd \
"

inherit core-image
