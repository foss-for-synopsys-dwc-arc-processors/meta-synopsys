require arch-arc.inc

DEFAULTTUNE ?= "arc770"
TUNE_PKGARCH = "${TUNE_PKGARCH_tune-${DEFAULTTUNE}}"

TUNEVALID[arc750] = "Standard ARComact ARC750 core"
TUNE_CCARGS .= "${@bb.utils.contains('TUNE_FEATURES', 'arc700', ' -mcpu=arc700', '', d)}"

TUNEVALID[llsc] = "Use load-locked/store-conditional instructions"
TUNE_CCARGS .= "${@bb.utils.contains('TUNE_FEATURES', 'llsc', ' -matomic', '', d)}"

TUNEVALID[swape] = "Use endian swap instruction"
TUNE_CCARGS .= "${@bb.utils.contains('TUNE_FEATURES', 'swape', ' -mswape', '', d)}"

AVAILTUNES += "arc750 arc770"

TUNE_FEATURES_tune-arc750 = "arc750"
TUNE_PKGARCH_tune-arc750 = "arc750"
PACKAGE_EXTRA_ARCHS_tune-arc750 = "arc750 arc770"

TUNE_FEATURES_tune-arc770 = "arc750 llsc swape"
TUNE_PKGARCH_tune-arc770 = "arc770"
PACKAGE_EXTRA_ARCHS_tune-arc770 = "arc770"

def arc_machine_dict(machdata, d):
    machdata["linux-uclibc"] = {
                                 "arc" :   ( 93, 0, 0, True,  32),
                                 "arceb" : ( 93, 0, 0, False, 32),
                               }
    return machdata

PACKAGEQA_EXTRA_MACHDEFFUNCS = "arc_machine_dict"
