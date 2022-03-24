TUNE_ARCH = "${@bb.utils.contains('TUNE_FEATURES', 'hs58', 'arc32', 'arc64', d)}"

TUNE_PKGARCH = "${TUNE_PKGARCH_tune-${DEFAULTTUNE}}"

TUNEVALID[hs58] = "Enable ARCv3 64-bit"
TUNE_CCARGS .= "${@bb.utils.contains('TUNE_FEATURES', 'hs58', ' -mcpu=hs5x', '', d)}"

TUNEVALID[hs68] = "Enable ARCv3 64-bit core"
TUNE_CCARGS .= "${@bb.utils.contains('TUNE_FEATURES', 'hs68', ' -mcpu=hs6x', '', d)}"

TUNEVALID[ll64] = "Enable 64-bit load/store operations"
TUNE_CCARGS .= "${@bb.utils.contains('TUNE_FEATURES', 'll64', ' -mll64', '', d)}"

TUNEVALID[ll128] = "Enable 128-bit load/store operations"
TUNE_CCARGS .= "${@bb.utils.contains('TUNE_FEATURES', 'll128', ' -m128', ' -mno-128', d)}"

TUNEVALID[div_rem] = "Enable simple divider"
TUNE_CCARGS .= "${@bb.utils.contains('TUNE_FEATURES', 'div_rem', ' -mdiv-rem', ' -mno-div-rem', d)}"

AVAILTUNES += "hs58 hs68"

TUNE_FEATURES:tune-hs58 = "hs58 div_rem"
TUNE_PKGARCH_tune-hs58 = "hs58"
PACKAGE_EXTRA_ARCHS:tune-hs58 = "hs58"

TUNE_FEATURES:tune-hs68 = "hs68 ll128 div_rem"
TUNE_PKGARCH_tune-hs68 = "hs68"
PACKAGE_EXTRA_ARCHS:tune-hs68 = "hs68"

def arc_machine_dict(machdata, d):
    machdata = {
            "elf" : {
                        "arc32" :     (255,    0,    0,          True,          32),
                        "arc64" :     (253,    0,    0,          True,          64),
                      },
            "linux" : {
                        "arc32" :     (255,    0,    0,          True,          32),
                        "arc64" :     (253,    0,    0,          True,          64),
                      },
    }
    return machdata

PACKAGEQA_EXTRA_MACHDEFFUNCS = "arc_machine_dict"
