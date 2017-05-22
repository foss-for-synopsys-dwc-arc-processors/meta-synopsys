DEPENDS_append_libc-uclibc = " libtirpc "

CFLAGS_append_libc-uclibc = " -I${STAGING_INCDIR}/tirpc "
LDFLAGS_append_libc-uclibc = " -ltirpc "
