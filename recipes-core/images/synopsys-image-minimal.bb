require recipes-core/images/core-image-minimal.bb

IMAGE_FSTYPES = "${INITRAMFS_FSTYPES}"

IMAGE_FEATURES += "package-management"
