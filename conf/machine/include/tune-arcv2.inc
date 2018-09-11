require arch-arc.inc

DEFAULTTUNE ?= "archs"
TUNE_FEATURES += "arcv2"

TUNEVALID[hs] = "Enable ARC HS with atomic instructions"
TUNEVALID[hs34] = "Enable ARC HS with atomic and h/w multiplier instructions"
TUNEVALID[archs] = "Enable ARC HS generic CPU support"
TUNEVALID[hs38] = "Enable ARC HS full feature instructions"
TUNEVALID[hs38linux] = "Enable ARC HS full feature instructions and double-precision FPU"

TUNE_CCARGS_tune-hs = "-mcpu=hs"
TUNE_CCARGS_tune-hs34 = "-mcpu=hs34"
TUNE_CCARGS_tune-archs = "-mcpu=archs"
TUNE_CCARGS_tune-hs38 = "-mcpu=hs38"
TUNE_CCARGS_tune-hs38linux = "-mcpu=hs38_linux"

TUNE_FEATURES_tune-hs += "hs"
TUNE_FEATURES_tune-hs34 += "hs34"
TUNE_FEATURES_tune-archs += "archs"
TUNE_FEATURES_tune-hs38 += "hs38"
TUNE_FEATURES_tune-hs38linux += "hs38-fpu"
