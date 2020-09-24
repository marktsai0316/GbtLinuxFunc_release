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


int main1(void)
{
	int fd=GbtLinuxFuncDrv_Init();
	int i;
	for(i=1;i<=21;i++)
	{
		SpeakerBeep_Control(fd,i,500); //set duration == 500 milisecond
	}

	GbtLinuxFuncDrv_Uninit(fd);
	return 0;
}

//Example:
/*
ref to http://www.ic.unicamp.br/~celio/mc404s102/pcspeaker/InternalSpeaker.htm
*/

int main(void)
{
	int fd=GbtLinuxFuncDrv_Init();
	SpeakerBeep_Control(fd,1+7,500);
	SpeakerBeep_Control(fd,1+7,500);
	SpeakerBeep_Control(fd,5+7,500);
	SpeakerBeep_Control(fd,5+7,500);
	SpeakerBeep_Control(fd,6+7,500);
	SpeakerBeep_Control(fd,6+7,500);
	SpeakerBeep_Control(fd,5+7,1000);
	SpeakerBeep_Control(fd,4+7,500);
	SpeakerBeep_Control(fd,4+7,500);
	SpeakerBeep_Control(fd,3+7,500);
	SpeakerBeep_Control(fd,3+7,500);
	SpeakerBeep_Control(fd,2+7,500);
	SpeakerBeep_Control(fd,2+7,500);
	SpeakerBeep_Control(fd,1+7,1000);
	SpeakerBeep_Control(fd,5+7,500);
	SpeakerBeep_Control(fd,5+7,500);
	SpeakerBeep_Control(fd,4+7,500);
	SpeakerBeep_Control(fd,4+7,500);
	SpeakerBeep_Control(fd,3+7,500);
	SpeakerBeep_Control(fd,3+7,500);
	SpeakerBeep_Control(fd,2+7,1000);
	SpeakerBeep_Control(fd,5+7,500);
	SpeakerBeep_Control(fd,5+7,500);
	SpeakerBeep_Control(fd,4+7,500);
	SpeakerBeep_Control(fd,4+7,500);
	SpeakerBeep_Control(fd,3+7,500);
	SpeakerBeep_Control(fd,3+7,500);
	SpeakerBeep_Control(fd,2+7,1000);
	SpeakerBeep_Control(fd,1+7,500);
	SpeakerBeep_Control(fd,1+7,500);
	SpeakerBeep_Control(fd,5+7,500);
	SpeakerBeep_Control(fd,5+7,500);
	SpeakerBeep_Control(fd,6+7,500);
	SpeakerBeep_Control(fd,6+7,500);
	SpeakerBeep_Control(fd,5+7,1000);
	SpeakerBeep_Control(fd,4+7,500);
	SpeakerBeep_Control(fd,4+7,500);
	SpeakerBeep_Control(fd,3+7,500);
	SpeakerBeep_Control(fd,3+7,500);
	SpeakerBeep_Control(fd,2+7,500);
	SpeakerBeep_Control(fd,2+7,500);
	SpeakerBeep_Control(fd,1+7,1000);
	GbtLinuxFuncDrv_Uninit(fd);
	return 0;
}


