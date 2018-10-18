IMAGE_LINGUAS = ""
IMAGE_FSTYPES += "${INITRAMFS_FSTYPES}"
inherit core-image

TARGET_TOOLCHAIN += "gcc gcc-symlinks \
                     g++ g++-symlinks \
                     cpp cpp-symlinks \
                     binutils \
                     autoconf \
                     automake \
                     bison \
                     flex \
                     gawk \
                     gettext \
                     libtool \
                     m4 \
                     make \
                     texinfo \
"

IMAGE_INSTALL += "${TARGET_TOOLCHAIN}"

IMAGE_FEATURES += "dev-pkgs"

