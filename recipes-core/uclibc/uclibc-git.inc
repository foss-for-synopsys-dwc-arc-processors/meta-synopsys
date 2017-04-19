SRCREV = "8d21b1a47c19857daf3041d9ceff807bdf100671"

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
