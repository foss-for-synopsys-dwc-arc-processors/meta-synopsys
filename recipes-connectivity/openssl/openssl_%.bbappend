# Using 64-bit atomics requires libatomic on arc32
CFLAGS:append:arc32 = " -latomic"
