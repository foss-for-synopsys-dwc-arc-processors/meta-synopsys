TUNEVALID[bigendian] = "Enable big-endian mode"

TUNE_ARCH = "${@bb.utils.contains('TUNE_FEATURES', 'bigendian', 'arceb', 'arc', d)}"

def arc_siteinfo_data(archinfo, osinfo, targetinfo, d):
    archinfo["arc"] = "endian-little bit-32"
    archinfo["arceb"] = "big-endian bit-32"
    return archinfo, osinfo, targetinfo

SITEINFO_EXTRA_DATAFUNCS = "arc_siteinfo_data"
