SRCREV = "559ac142e48b812906d0498f6ada93a5662e1606"

FILESEXTRAPATHS =. "${FILE_DIRNAME}/uclibc-git:"

SRC_URI = " \
	git://git.uclibc-ng.org/git/uclibc-ng;protocol=https;branch=master \
        file://uClibc.machine \
        file://uClibc.distro \
        file://obstack.cfg \
        file://locale.cfg \
        file://0001-ldso-Troubleshoot-unresolved-symbol.patch \
"
S = "${WORKDIR}/git"

UPSTREAM_CHECK_GITTAGREGEX = "(?P<pver>\d+\.\d+(\.\d+)*)"
