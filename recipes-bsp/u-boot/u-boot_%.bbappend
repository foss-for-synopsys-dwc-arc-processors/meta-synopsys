FILESEXTRAPATHS_prepend := "${THISDIR}/files:"

SRC_URI += "file://uboot.env.txt"

DEPENDS += "u-boot-mkenvimage-native"

do_environment_image () {
	mkenvimage -s 0x4000 ${WORKDIR}/uboot.env.txt -o ${WORKDIR}/uboot.env
}

addtask environment_image after do_install_native-mkimage before do_deploy
