TUNEVALID[littleendian] = "Enable little-endian mode"
TUNEVALID[bigendian] = "Enable big-endian mode"

TUNE_ARCH = "arc${ARC_ENDIAN}"
TUNE_PKGARCH = "arc${ARC_ENDIAN}"
TUNE_FEATURES = "arc"

PACKAGE_EXTRA_ARCHS = "arc${ARC_ENDIAN}"

ARC_ENDIAN = "${@bb.utils.contains('TUNE_FEATURES', 'bigendian', 'eb', '', d)}"

def arc_siteinfo_data(archinfo, osinfo, targetinfo, d):
    archinfo["arc"] = "endian-little bit-32"
    archinfo["arceb"] = "big-endian bit-32"
    return archinfo, osinfo, targetinfo

SITEINFO_EXTRA_DATAFUNCS = "arc_siteinfo_data"
PREFERRED_PROVIDER_virtual/bootloader = "u-boot"
UBOOT_MACHINE = "hsdk_config"
EXTRA_IMAGEDEPENDS += "u-boot"
