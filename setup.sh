#!/bin/sh

DIR="build"
MACHINE="nsimhs"
CONFFILE="conf/auto.conf"
BITBAKEIMAGE="core-image-minimal"

# bootstrap OE
echo "Init OE"
export BASH_SOURCE="openembedded-core/oe-init-build-env"
. ./openembedded-core/oe-init-build-env $DIR

# add the missing layers
echo "Adding layers"
bitbake-layers add-layer ../meta-openembedded/meta-oe
bitbake-layers add-layer ../meta-openembedded/meta-multimedia
bitbake-layers add-layer ../meta-openembedded/meta-python
bitbake-layers add-layer ../meta-openembedded/meta-networking
bitbake-layers add-layer ../meta-synopsys

# fix the configuration
echo "Creating auto.conf"

if [ -e $CONFFILE ]; then
    rm -rf $CONFFILE
fi
cat <<EOF > $CONFFILE
MACHINE = "${MACHINE}"
#IMAGE_FEATURES += "tools-debug"
#IMAGE_FEATURES += "tools-tweaks"
#IMAGE_FEATURES += "dbg-pkgs"
# rootfs for debugging
#IMAGE_GEN_DEBUGFS = "1"
#IMAGE_FSTYPES_DEBUGFS = "tar.gz"
# explicitly disable x11 and enable opengl
HOSTTOOLS_NONFATAL_append = " ssh"
EOF

echo "To build an image run"
echo "-------------------------------"
echo "bitbake core-image-full-cmdline"
echo "-------------------------------"
