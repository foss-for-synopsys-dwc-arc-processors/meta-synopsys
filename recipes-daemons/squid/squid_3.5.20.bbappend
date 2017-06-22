# Set the BASIC_AUTH to have NIS available only for glibc
# because there is no support for uClibc for example.
# Took this configuration from Pyro branch, 3.5.25 version recipe.
BASIC_AUTH = "DB SASL LDAP"
BASIC_AUTH_append_libc-glibc = " NIS"

# Remove the 'atomics' option because ARC does not support 8 bytes __sync function.
PACKAGECONFIG_append = "${@bb.utils.contains('TARGET_ARCH', 'arc', 'noatomics', '', d)}"
