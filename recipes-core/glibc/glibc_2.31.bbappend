CFLAGS_append += " -Wno-error"
EXTRA_OECONF += " --disable-werror --disable-multilib"
SRCBRANCH = "vineet/arc-port-latest"
SRCREV_glibc = "9cd814f16dc973edd10a72a2929708eaee7dc74b"
SRC_URI =  "${GLIBC_GIT_URI};branch=${SRCBRANCH};name=glibc \
           file://etc/ld.so.conf \
           file://generate-supported.mk \
           file://makedbs.sh \
           \
           ${NATIVESDKFIXES} \
           file://0008-fsl-e500-e5500-e6500-603e-fsqrt-implementation.patch \
           file://0009-readlib-Add-OECORE_KNOWN_INTERPRETER_NAMES-to-known-.patch \
           file://0010-ppc-sqrt-Fix-undefined-reference-to-__sqrt_finite.patch \
           file://0011-__ieee754_sqrt-f-are-now-inline-functions-and-call-o.patch \
           file://0012-Quote-from-bug-1443-which-explains-what-the-patch-do.patch \
           file://0013-eglibc-run-libm-err-tab.pl-with-specific-dirs-in-S.patch \
           file://0014-__ieee754_sqrt-f-are-now-inline-functions-and-call-o.patch \
           file://0015-sysdeps-gnu-configure.ac-handle-correctly-libc_cv_ro.patch \
           file://0016-Add-unused-attribute.patch \
           file://0017-yes-within-the-path-sets-wrong-config-variables.patch \
           file://0018-timezone-re-written-tzselect-as-posix-sh.patch \
           file://0019-Remove-bash-dependency-for-nscd-init-script.patch \
           file://0020-eglibc-Cross-building-and-testing-instructions.patch \
           file://0021-eglibc-Help-bootstrap-cross-toolchain.patch \
           file://0022-eglibc-Resolve-__fpscr_values-on-SH4.patch \
           file://0023-eglibc-Forward-port-cross-locale-generation-support.patch \
           file://0024-Define-DUMMY_LOCALE_T-if-not-defined.patch \
           file://0025-localedef-add-to-archive-uses-a-hard-coded-locale-pa.patch \
           file://0026-elf-dl-deps.c-Make-_dl_build_local_scope-breadth-fir.patch \
           file://0027-intl-Emit-no-lines-in-bison-generated-files.patch \
           file://0028-inject-file-assembly-directives.patch \
           file://0029-locale-prevent-maybe-uninitialized-errors-with-Os-BZ.patch \
           "


