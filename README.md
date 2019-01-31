# This is manifest to download AGL build system with meta-synopsys layer

## Introdution
Automotive Grade Linux is a collaborative open source project that is bringing together automakers, suppliers and technology 
companies to accelerate the development and adoption of a fully open software stack for the connected car.
With Linux at its core, AGL is developing an open platform from the ground up that can serve as the de facto industry standard to enable rapid development of new features and technologies.


## Prerequisites
### Software
AGL demo image can only be built on a Linux development host, so either a Linux development host or a virtual machine with Linux installed in the client should be used.

Before building AGL demo image it's important to make sure the build machine has all required packages installed. Please refer to Automotive Grade Linux official documentation where examples for different host Linux distributions are provided:
http://docs.automotivelinux.org/master/docs/getting_started/en/dev/reference/source-code.html

### Hardware

* **Video output**.
  The HSDK board does not support HDMI so a USB-to-HDMI or USB-to-DVI adapter is required for external video output to HDMI. 
  As of today there's only one such type of devices that fully supported in the Linux kernel - 
  those based on DisplayLink USB 2.0 chips (i.e. DL-1x5, DL-1x0).
  Tested adapter is Accell J131B-001B. On manufacturer's web-site:
    [Accell J131B-001B](https://www.accellww.com/products/ultraav-usb-2-0-to-hdmi-adapter)
* **Bluetooth**.
  The HSDK board does not have onboard bluetooth adapter so a USB Bluetooth dongle is required for demonstration purposes.
  Tested adapter is ASUS USB-BT400. On amazon web-site: 
  [ASUS USB-BT400](https://www.amazon.com/Bluetooth-Receiver-Keyboards-Controllers-USB-BT400/dp/B00DJ83070/ref=sr_1_1?ie=UTF8&qid=1545843433&sr=8-1&keywords=ASUS+USB-BT400)
* **AM/FM Tuner**.
  The AGL demo application "Radio" requires a radio receiver, which is not present on HSDK board. 
  Tested adapter is GIGABYTE GT-U7300: On manufacturer's web-site: [GT-U7300](https://www.gigabyte.com/us/TV-Tuner-Dongle/U7300)
  According [AGL Wiki](https://wiki.automotivelinux.org/agl-distro/ces-2017-demo)  it is recommended to use [RTL-SDR](https://www.rtl-sdr.com/buy-rtl-sdr-dvb-t-dongles/) dongles 

## Build procedure
1. Download necessary files using [repo](https://source.android.com/setup/downloading#installing-repo) utility 
```
  repo init -u https://github.com/foss-for-synopsys-dwc-arc-processors/meta-synopsys -b snps_agl_2018.09 -m tools/agl_manifest.xml 
  repo sync -j4 
```
2. Initialize build directory by using template files
```
  source meta-agl/scripts/aglsetup.sh -m hsdk agl-demo agl-netboot agl-appfw-smack
```
3. Build image for Synopsys ARC HSDK platform (currently, the rootfs is used as initramfs)
```
  bitbake agl-demo-platform
```
## Deploy and startup procedures
In order to run this image a microSD-card with a capacity of at least 8 GB is required.
   
After build procedure have finished the artifacts are stored in **build/tmp/deploy/images/hsdk/** directory.
Deploy **agl-demo-platform-hsdk.wic.xz** file on microSD-card:
  * On Linux hosts, use dd command as follows:   
      ```xz -cd agl-demo-platform-hsdk.wic.xz | sudo dd of=/dev/mmcblkp0 bs=4M; sync```
  * On Windows hosts, use "Win32 Disk Imager" utility, available here: https://sourceforge.net/projects/win32diskimager/

Once the agl-demo-platform-hsdk.ext4 file is deployed on microSD-card, just insert it in the microSD-card slot of the HSDK and reset the board. Note DIP-switch BIM should be in 1:off, 2:on state while both BMC and BCS should be in 1: on, 2:on state.


## Running applications
After boot you will see the main menu on the screen:
<p align="center">
 <img src="https://github.com/EvgeniiDidin/agl_manifest_synopsys/blob/master/screenshots/main.png" align="center" height="480" width="320">
</p>
Currently 8 of the 9 available applications are working. POI application (Points of Interest) is not currently working due to incorrect geolocation. Tapping on round buttons will start the selectded application. Using the "Home" button on the top bar will return to main menu screen.

### Settings application
The Settings application can be used to connect the board to a smartphone via Bluetooth and to a WI-FI hotspot. Also it can show version info. Note: Changing Date&Time does not change actual onboard time.
<p align="center">
 <img src="https://github.com/EvgeniiDidin/agl_manifest_synopsys/blob/master/screenshots/settings.png" align="center" height="480" width="320">
</p>
To connect the HSDK board to smartphone using Bluetooth click on "Bluetooth" title. Then in the list of device click "Pair" button of the device you would like to connect, and on smartphone confirm connection. When the device is at the top of the list click "Connect" button. Under the name of the device MAC address and "Handsfree & AV Connection" title should appear.
<p align="center">
 <img src="https://github.com/EvgeniiDidin/agl_manifest_synopsys/blob/master/screenshots/Bluetooth.png" align="center" height="480" width="320">
</p>

### Mixer application
The Mixer application can change the sound volume of input and output audio devices.
<p align="center">
 <img src="https://github.com/EvgeniiDidin/agl_manifest_synopsys/blob/master/screenshots/mixer.png" align="center" height="480" width="320">
</p>

### Mediaplayer
The Mediaplayer is an application which can play audio files from smartphone using Bluetooth connection. Connect HSDK board to the smartphone using "Settings"->Bluetooth, then open the audio player on smartphone and play audio file. 
<p align="center">
 <img src="https://github.com/EvgeniiDidin/agl_manifest_synopsys/blob/master/screenshots/mediaplayer.png" align="center" height="480" width="320">
</p>

### Phone
The Phone application requires established Bluetooth connection with smartphone. Enter the number and press button with cellphone symbol. 
<p align="center">
 <img src="https://github.com/EvgeniiDidin/agl_manifest_synopsys/blob/master/screenshots/phone.png" align="center" height="480" width="320">
</p>

### Radio
The Radio application requires AM/FM Tuner plugged into the HSDK board. Using arrows or slider it is possible to change radio frequency to tune to a given station.
<p align="center">
 <img src="https://github.com/EvgeniiDidin/agl_manifest_synopsys/blob/master/screenshots/radio.png" align="center" height="480" width="320">
</p>

### HVAC
The HVAC application is used for automotive climate control. Currently devices like ventilator or air conditioning are not supported on HSDK board. **Note:** read *Known issues section 1*
<p align="center">
 <img src="https://github.com/EvgeniiDidin/agl_manifest_synopsys/blob/master/screenshots/hvac.png" align="center" height="480" width="320">
</p>

### Navigation
The Navigation application can simulate automotive driving on map. All movement changes are accompanied by the sound of a voice assistant. This application requires navigation data, which is not provided by AGL build system.
Download navigation data from [navi_data](http://agl.wismobi.com/data/japan_TR9/navi_data.tar.gz),
then unpack this archive and put **navi_data** directory on /root partition in **/home/** direcotory
Usage:
1) Make a log click in some place of the map (similar to finger tap).
2) When a point on the map is present, click the button on the top of right corner.
3) When the root is drawn, click the button from the paragraph "2" again.
<p align="center">
 <img src="https://github.com/EvgeniiDidin/agl_manifest_synopsys/blob/master/screenshots/navi.png" align="center" height="480" width="320">
</p>


### Dashboard
The Dashboard application is a monitor of the car's condition. Currently no sensors are supported to demonstrate capability of this application.
<p align="center">
 <img src="https://github.com/EvgeniiDidin/agl_manifest_synopsys/blob/master/screenshots/dashboard.png" align="center" height="480" width="320">
</p>

## Useful tips
1) *afm-util*  - utility, which can start application without GUI. 
```
$ afm-util list
$ afm-util run <application_id>
```
2) In case of multiple audio devices use pacmd and pactl commands:
```
$ pactl list sinks short
$ pacmd set-default-sink 1
```
3) Bluetooth:
  * Useful link: https://wiki.automotivelinux.org/bluetooth
  * To reset any known pairings just remove everything in directory /var/lib/bluetooth/{bluetooth-adapter-mac}/

## Known issues
1) Scrolling temperature in HVAC application causes crash.
2) Some crashes may be seen after running the application for several minutes (under investigation). If this happens, reboot the board to restore the system.
3) Running all 8 applications can cause lack of available RAM. Before OOM killer kills the HomeScreen application
check free memory using *free* utility. If the number of free memory is less them 10000 run:
```
sync; echo 1 > /proc/sys/vm/drop_caches 
```
