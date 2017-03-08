TUNEVALID[bigendian] = "Enable big-endian mode"

TUNE_ARCH = "arc${ARC_ENDIAN}"
TUNE_PKGARCH = "arc${ARC_ENDIAN}"
TUNE_FEATURES = "arc"

PACKAGE_EXTRA_ARCHS = "arc${ARC_ENDIAN}"

ARC_ENDIAN = "${@bb.utils.contains('TUNE_FEATURES', 'bigendian', 'eb', '', d)}"
