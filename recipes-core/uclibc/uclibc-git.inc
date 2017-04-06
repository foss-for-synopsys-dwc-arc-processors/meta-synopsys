SRCREV = "a3d19f43e0a2a0577b8bf659fd2ffa866234bb1a"

FILESEXTRAPATHS =. "${FILE_DIRNAME}/uclibc-git:"

SRC_URI = " \
	git://git.uclibc-ng.org/git/uclibc-ng;protocol=https;branch=master \
        file://uClibc.machine \
        file://uClibc.distro \
        file://obstack.cfg \
        file://locale.cfg \
"
S = "${WORKDIR}/git"

UPSTREAM_CHECK_GITTAGREGEX = "(?P<pver>\d+\.\d+(\.\d+)*)"
