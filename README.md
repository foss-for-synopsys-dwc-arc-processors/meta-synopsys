# This layer provides support for Synopsys / ARC CPU

## Build procedure

1. Download necessary files using [repo](https://source.android.com/setup/downloading#installing-repo) utility

	repo init -u https://github.com/foss-for-synopsys-dwc-arc-processors/synopsys-oe-manifest

2. Enter the openembedded-core directory

	cd oe

3. Initialize build directory by using template files
```
export TEMPLATECONF=../meta-synopsys/conf
source oe-init-build-env build
```
4. For creating image for HSDK open ./conf/local.conf file in your favourite text editor and replace line:

```
MACHINE = "nsimhs"
```
	to
```
MACHINE = "hsdk"
```

5. Build synopsys image (currently, the rootfs is used as initramfs)
```
bitbake virtual/kernel
```
