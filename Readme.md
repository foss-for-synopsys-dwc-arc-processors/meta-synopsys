# Building basic images for ARC boards with OpenEmbedded

## Preparation

### Checkout OpenEmbedded sources
```
mkdir oe
cd oe
repo init -u https://github.com/foss-for-synopsys-dwc-arc-processors/meta-synopsys -b master -m tools/manifests/synopsys-oe.xml
repo sync
```

### Setup environment
```
. ./openembedded-core/oe-init-build-env
bitbake-layers add-layer ../meta-openembedded/meta-oe
bitbake-layers add-layer ../meta-synopsys
```

### Start building
 * `vmlinux` usable with nSIM simulator
    - for ARC700: `MACHINE=nsim700 bitbake virtual/kernel`
    - for ARCHS38: `MACHINE=hapshs bitbake virtual/kernel`

 * SD-card image
    - for AXS101: `MACHINE=axs101 bitbake core-image-base`
    - for AXS103: `MACHINE=ax103 bitbake core-image-base`
    - for HSDK: `MACHINE=hsdk bitbake core-image-base`
