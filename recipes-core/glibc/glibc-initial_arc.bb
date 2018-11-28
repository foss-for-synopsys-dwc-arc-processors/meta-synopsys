require glibc_${PV}.bb
require recipes-core/glibc/glibc-initial.inc

INSANE_SKIP_${PN} = "file-rdeps"
INSANE_SKIP_${PN}-dev = "file-rdeps"



# main glibc recipes muck with TARGET_CPPFLAGS to point into
# final target sysroot but we
# are not there when building glibc-initial
# so reset it here

TARGET_CPPFLAGS = ""
