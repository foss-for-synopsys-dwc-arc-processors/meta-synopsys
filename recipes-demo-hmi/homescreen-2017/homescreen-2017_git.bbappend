do_aglwgt_deploy_append() {
echo "updating homescreen-2017 service generator script"
echo 'sed -i "/SystemCallFilter=/a Restart=always" /var/local/lib/systemd/system/afm-appli-homescreen-2017--0.1--main@.service' >> ${D}/${sysconfdir}/agl-postinsts/${POST_INSTALL_SCRIPT}
}

