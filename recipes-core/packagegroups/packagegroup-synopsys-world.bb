SUMMARY = "Synopsys Packagegroup"
PR = "r1"

inherit packagegroup

PACKAGES = "\
	 packagegroup-meta-apps \
	 packagegroup-meta-oe-apps \
	 packagegroup-meta-networking-apps \
	 packagegroup-meta-webserver-apps \
         "

# We just want to build package for the moment, not install them
RDEPENDS_packagegroup-meta-apps += "\
	    avahi alsa-tools alsa-utils aspell at \
	    base-files base-passwd bash bash-completion \
	    bc bind bluez5 btrfs-tools busybox bzip2 \
	    ca-certificates chrpath connman console-tools coreutils cpio curl \
	    dhcp dosfstools dropbear \
	    e2fsprogs ed ethtool file gawk grep gzip \
	    hostap-conf hostap-utils \
	    i2c-tools ifupdown init-ifupdown iproute2 iptables iputils irda-utils \
	    keymaps less lighttpd logrotate lrzsz lsof lzo \
	    man man-pages mc mdadm minicom mktemp \
	    ncurses neard netbase net-tools nfs-utils \
	    openssh openssl parted patch perf perl ppp procps pseudo psplash python python3 \
	    quota readline rpcbind rsync ruby \
	    screen sed setserial socat sqlite3 stat strace subversion sudo sysfsutils sysvinit \
	    tar tcl time tzdata \
	    unzip usbutils util-linux \
	    watchdog wget which wireless-tools wpa-supplicant zip \
	    "

RDEPENDS_packagegroup-meta-oe-apps += "tslib"

RDEPENDS_packagegroup-meta-networking-apps += " \
	    arptables atftp bridge-utils \
	    cifs-utils conntrack-tools curlpp cyrus-sasl \
	    dhcpcd dnsmasq dnssec-conf dovecot ebtables esmtp \
	    fetchmail fping inetutils ipsec-tools ipvsadm \
	    lftp mtr ncftp netcat netcf net-snmp nftables ntp \
	    openl2tp openvpn postfix pptp-linux proftpd ptpd pure-ftpd \
	    quagga rp-pppoe squid strongswan stunnel \
	    tcpdump traceroute tunctl \
	    vlan vsftpd \
	    zeroconf \
	    "

RDEPENDS_packagegroup-meta-webserver-apps += " \
	    apache2 nginx \
	    "
