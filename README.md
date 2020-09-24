# GbtLinuxFunc_release
GbtLinuxFunc SDK From Gigabyte



# Supported Hardware :

- GA-SBC4200
- GA-SBC5005SE
- GA-IMB4100TN
- GA-IMB310TN
- GA-IMBLAP3450
- GA-IMBLAP3350
- GA-N3160TN
- GA-H110TN


# Exported Library:

- int GbtLinuxFuncDrv_Init();
- void GbtLinuxFuncDrv_Uninit(int fd);

- int DigitalIo_PinMode(int fd, int pin , int mode);
- int DigitalIo_DigitalWrite(int fd, int pin,int value );
- int DigitalIo_DigitalRead(int fd, int pin );

- int DebugPort_Write(int fd, unsigned char value );

- int WatchDog_Control(int fd, int interval); //0 : Disable  , 1~255 unit in second
- int WatchDog_Status(int fd, unsigned short *pTimeoutValue, unsigned short *pWdtStatus); 
- int WatchDog_BeatBeep(int fd, int Enable);

- int SpeakerBeep_Control(int fd, unsigned short note,unsigned short duration);

# Install GbtLinuxFuncDrv 

```sh
$ cd Driver
$ sudo ./install.sh
filename:       /home/mark/GbtLinuxFunc/GbtLinuxFunc_release/Driver/./GbtLinuxFuncDrv.5.4.0-47-generic.ko
version:        1.0.8
license:        GPL
description:    Gigabyte Embedded Board Linux Control Driver
author:         Mark Tsai<mark@gigabyte.com><marktsai0316@gmail.com>
alias:          wmi:DEADBEEF-2001-0000-00A0-C90629100000
alias:          wmi:ABBC0F6F-8EA1-1459-00A0-C90629100000
srcversion:     5A50DD8C6A7CBD078732E94
alias:          dmi*:rn*SBC5005*:
alias:          dmi*:rn*SBC4200*:
alias:          dmi*:rn*IMB4100TN*:
alias:          dmi*:rn*IMB310TN*:
alias:          dmi*:rn*IMBLAP3450*:
alias:          dmi*:rn*IMBLAP3350*:
alias:          dmi*:rn*N3160TN*:
alias:          dmi*:rn*H110TN*:
depends:        wmi
retpoline:      Y
name:           GbtLinuxFuncDrv
vermagic:       5.4.0-47-generic SMP mod_unload 

GbtLinuxFuncDrv           16384  0

[74901.330051] GbtLinuxFuncDrv: GbtLinuxFunc module initial.
[74901.330053] Identified model 'GA-IMB310TN' ID=0xA0
[74901.330058] Force switch SIO mode from LPT to GPIO
[74901.330625] I got: 131072 bytes of memory 

245 GbtLinuxFunc

crw------- 1 root root 245, 0  7月 21 13:00 /dev/GbtLinuxFunc

```
