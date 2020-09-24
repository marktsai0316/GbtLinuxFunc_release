#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#include "GbtLinuxFunc.h"

int GbtLinuxFuncDrv_Init()
{
	int fd;

	fd = open("/dev/GbtLinuxFunc", O_RDWR);
	if (fd == -1 ) 
	{
		perror("open \"/dev/GbtLinuxFunc\" failed.");
		return -1;
	}
	return fd;
}

void GbtLinuxFuncDrv_Uninit(int fd)
{
	if (fd != -1 ) 
	{
		close(fd);
	}
}




int DigitalIo_PinMode(int fd, int pin , int mode)
{
	DIGITALIO data;
	data.pinnumber = pin;
	data.u.mode=mode;
	if (ioctl(fd, GBTLINUXFUNC_DIGITALIO_PINMODE, &data)) {
		perror("GBTLINUXFUNC_DIGITALIO_PINMODE failed,Maybe have Invalid argument");
		return -1;
	}
	return 0;
}

int DigitalIo_DigitalWrite(int fd, int pin,int value )
{

	DIGITALIO data;
	data.pinnumber = pin;
	data.u.value=value;
	if (ioctl(fd, GBTLINUXFUNC_DIGITALIO_DIGITALWRITE, &data)) {
		perror("GBTLINUXFUNC_DIGITALIO_DIGITALWRITE failed,Maybe have Invalid argument");
		return -1;
	}
	return 0;
}

int DigitalIo_DigitalRead(int fd, int pin )
{
	DIGITALIO data;
	data.pinnumber = pin;
	if (ioctl(fd, GBTLINUXFUNC_DIGITALIO_DIGITALREAD, &data)) {
		perror("GBTLINUXFUNC_DIGITALIO_DIGITALREAD failed,Maybe have Invalid argument");
		return -1;
	}
	return data.u.value;
}

int WatchDog_Control(int fd, int interval)
{
	int data=interval;
	if (ioctl(fd, GBTLINUXFUNC_WATCHDOG_CONTROL, &data)) {
		perror("GBTLINUXFUNC_WATCHDOG_CONTROL failed,Maybe have Invalid argument");
		return -1;
	}
	return 0;
}

int WatchDog_Status(int fd, unsigned short *pTimeoutValue, unsigned short *pWdtStatus)
{
	int Value;
	if (ioctl(fd, GBTLINUXFUNC_WATCHDOG_STATUS, &Value)) {
		perror("GBTLINUXFUNC_WATCHDOG_STATUS failed,Maybe have Invalid argument");
		return -1;
	}
	
	*pTimeoutValue = (unsigned short)(Value);
	*pWdtStatus = (unsigned short)(Value>>16);
	return 0;
}

int WatchDog_BeatBeep(int fd, int Enable)
{
	int data=Enable;
	if (ioctl(fd, GBTLINUXFUNC_WATCHDOG_BEATBEEP, &data)) {
		perror("GBTLINUXFUNC_WATCHDOG_BEATBEEP failed,Maybe have Invalid argument");
		return -1;
	}
	return 0;
}

int DebugPort_Write(int fd, unsigned char value )
{
	if (ioctl(fd, GBTLINUXFUNC_DEBUGPORT_WRITE, &value)) {
		perror("GBTLINUXFUNC_DEBUGPORT_WRITE failed");
		return -1;
	}
	return 0;
}

int SpeakerBeep_Control(int fd, unsigned short note,unsigned short duration)
{

	SPEAKERBEEPIO data;
	data.type = 3;
	data.note = note;
	data.duration=duration;
	if (ioctl(fd, GBTLINUXFUNC_SPEAKERBEEP_CONTROL, &data)) {
		perror("GBTLINUXFUNC_SPEAKERBEEP_CONTROL failed,Maybe have Invalid argument");
		return -1;
	}
	return 0;
}

