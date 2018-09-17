require arch-arc.inc

DEFAULTTUNE ?= "archs"
TUNE_PKGARCH = "${TUNE_PKGARCH_tune-${DEFAULTTUNE}}"

TUNEVALID[hs] = "Enable ARC HS core with 32-bit atomic ops"
TUNE_CCARGS .= "${@bb.utils.contains('TUNE_FEATURES', 'hs', ' -mcpu=hs', '', d)}"

TUNEVALID[llsc64] = "Enable 64-bit LL/SC operations"
TUNE_CCARGS .= "${@bb.utils.contains('TUNE_FEATURES', 'llsc64', ' -mll64', '', d)}"

TUNEVALID[div_rem] = "Enable simple divider"
TUNE_CCARGS .= "${@bb.utils.contains('TUNE_FEATURES', 'div_rem', ' -mdiv-rem', '', d)}"

TUNEVALID[mpy] = "Enable simple hardware multiplier"
TUNE_CCARGS .= "${@bb.utils.contains('TUNE_FEATURES', 'mpy', ' -mmpy-option=mpy', '', d)}"

TUNEVALID[plus_qmacw] = "Enable most powerful hardware multiplier"
TUNE_CCARGS .= "${@bb.utils.contains('TUNE_FEATURES', 'plus_qmacw', ' -mmpy-option=plus_qmacw', '', d)}"

TUNEVALID[fpud_all] = "Enable double-precision FPU"
TUNE_CCARGS .= "${@bb.utils.contains('TUNE_FEATURES', 'fpud_all', ' -mfpu=fpud_all', '', d)}"

AVAILTUNES += "archs hs38 hs38linux"

TUNE_FEATURES_tune-archs = "hs llsc64 mpy"
TUNE_PKGARCH_tune-archs = "archs"
PACKAGE_EXTRA_ARCHS_tune-archs = "archs hs38 hs38linux"

TUNE_FEATURES_tune-hs38 = "hs llsc64 plus_qmacw"
TUNE_PKGARCH_tune-hs38 = "hs38"
PACKAGE_EXTRA_ARCHS_tune-hs38 = "hs38 hs38linux"

TUNE_FEATURES_tune-hs38linux = "hs llsc64 plus_qmacw fpud_all"
TUNE_PKGARCH_tune-hs38linux = "hs38linux"
PACKAGE_EXTRA_ARCHS_tune-hs38linux = "hs38linux"

def arc_machine_dict(machdata, d):
    machdata = {
            "elf" : {
                        "arc" :       (195,    0,    0,          True,          32),
                        "arceb" :     (195,    0,    0,          False,         32),
                      },
            "linux" : {
                        "arc" :       (195,    0,    0,          True,          32),
                        "arceb" :     (195,    0,    0,          False,         32),
                      },
    }
    return machdata

PACKAGEQA_EXTRA_MACHDEFFUNCS = "arc_machine_dict"
