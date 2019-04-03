TUNEVALID[bigendian] = "Enable big-endian mode"

TUNE_ARCH = "${@bb.utils.contains('TUNE_FEATURES', 'bigendian', 'arceb', 'arc', d)}"

MACHINE_FEATURES_BACKFILL_CONSIDERED_append = " qemu-usermode"

PREFERRED_PROVIDER_virtual/kernel ?= "linux-arc"

# Otherwise huge binaries (>32MiB) might fail to link due to
# limitation of 25-bit R_ARC_S25H_PCREL_PLT relocation
GLIBC_EXTRA_OECONF_arc += " --with-nonshared-cflags=-mlong-calls"

PREFERRED_PROVIDER_virtual/bootloader = "u-boot"
UBOOT_MACHINE = "hsdk_config"
EXTRA_IMAGEDEPENDS += "u-boot"

