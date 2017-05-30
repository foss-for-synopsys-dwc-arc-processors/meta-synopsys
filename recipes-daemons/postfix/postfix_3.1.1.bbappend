FILESEXTRAPATHS_prepend := "${THISDIR}/${PN}-${PV}:"

SRC_URI += "file://0001-postfix-Add-NO_RES_SEND-in-case-res_send-unavailable.patch"

CFLAGS_append_libc-uclibc = " -DNO_NIS -DNO_NISPLUS -DNO_RES_SEND"
