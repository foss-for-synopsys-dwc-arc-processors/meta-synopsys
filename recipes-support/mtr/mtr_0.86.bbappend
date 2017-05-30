FILESEXTRAPATHS_prepend := "${THISDIR}/${PN}-${PV}:"

SRC_URI += "file://0001-dns-Fix-res_ninit-to-use-mkquery.patch"
