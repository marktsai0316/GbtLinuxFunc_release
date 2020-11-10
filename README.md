# GbtLinuxFunc SDK From Gigabyte

GbtLinuxFunc SDK is a C Library for GPIO/Watchdog function control under Ubuntu environment.

# Supported Hardware :
| IPC/IOT Board | Digital IO Type | Watchdog Support|
| ------ | ---- | --- |
| GA-SBC4200 | 26-pin | Yes |
| GA-SBC5005SE | None | Yes |
| GA-IMB4100TN | 26-pin | Yes |
| GA-IMB310TN | 10-pin | Yes |
| GA-IMBLAP3450 | 26-pin | Yes |
| GA-IMBLAP3350 | 26-pin | Yes |
| GA-N3160TN | 26-pin | Yes |
| GA-H110TN | 10-pin | Yes |


# Exported Library API
```C
int GbtLinuxFuncDrv_Init();
void GbtLinuxFuncDrv_Uninit(int fd);

int DigitalIo_PinMode(int fd, int pin , int mode);
int DigitalIo_DigitalWrite(int fd, int pin,int value );
int DigitalIo_DigitalRead(int fd, int pin );

int WatchDog_Control(int fd, unsigned int interval,unsigned int AutoBeatEn); //0 : Disable  , 1~255 unit in second  
int WatchDog_Status(int fd, unsigned short *pTimeoutValue, unsigned short *pAutoBeatStatus); 
int WatchDog_KeepAlive(int fd, unsigned short *pTimeoutValue, unsigned short *pAutoBeatStatus); 


int DebugPort_Write(int fd, unsigned char value );

```
# SDK Folder
```sh
$ tree
.
├── Driver
│   ├── GbtLinuxFuncDrv.5.4.0-47-generic.ko
│   ├── GbtLinuxFuncDrv.5.4.0-48-generic.ko
│   ├── GbtLinuxFuncDrv.5.4.0-52-generic.ko
│   ├── install.sh
│   └── uninstall.sh
├── Examples
│   ├── debugporttst
│   ├── debugporttst.c
│   ├── digitalIotst
│   ├── digitalIotst.c
│   ├── GbtLinuxFunc.c
│   ├── GbtLinuxFunc.h
│   ├── GbtLinuxFunc.o
│   ├── Makefile
│   ├── readme.txt
│   ├── speakerbeeptst
│   ├── speakerbeeptst.c
│   ├── watchdogtst30
│   ├── watchdogtst30.c
│   ├── watchdogtst
│   └── watchdogtst.c
└── [Gigabyte] GbtLinuxFunc API User Guide.pdf

```
# Install GbtLinuxFuncDrv 

```sh
$ cd Driver
$ sudo ./install.sh
```
If driver install success, you will see the following like-context.

```sh
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

If driver install fail, you will see the following like-context.

```sh
Kernel 5.3.0-48-generic is not supported
Please contact Gigabyte Software RD (mark@gigabyte.com)
```
# Uninstall GbtLinuxFuncDrv 

```sh
$ cd Driver
$ sudo ./uninstall.sh
```
If driver uninstall success, you will get context like as:
```sh
[74908.137850] GbtLinuxFuncdrv: Goodbye, GIGABYTE!
```
# How to force system crash and test WDT function ?

A watchdog timer (sometimes called a computer operating properly or COP timer, or simply a watchdog) is an electronic or software timer that is used to detect and recover from computer malfunctions.

```sh
$ sudo chmod +x kernel_panic.sh
$ sudo ./watchdogtst
Current Timeout value is 0 secs, WDT is Disabled //before setting
Current Timeout value is 30 secs, WDT is Enabled //after setting
$ sudo ./kernel_panic.sh
```
After 30 secs, System will be WDT reset......
