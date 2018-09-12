TUNEVALID[bigendian] = "Enable big-endian mode"

TUNE_ARCH = "${@bb.utils.contains('TUNE_FEATURES', 'bigendian', 'arceb', 'arc', d)}"

MACHINE_FEATURES_remove = "qemu-usermode"

PREFERRED_PROVIDER_virtual/kernel = "linux-arc"
PREFERRED_VERSION_linux-arc ?= "4.18%"
