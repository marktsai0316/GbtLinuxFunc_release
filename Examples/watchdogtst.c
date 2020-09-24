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


//Example:

int main(void)
{
	unsigned short TimeoutValue,WdtStatus;
	int fd=GbtLinuxFuncDrv_Init();
	//You can enable BeatBeep to hear system's heartbeat by internal speaker
	WatchDog_BeatBeep(fd, 1);  //Enable BeatBeep

	WatchDog_Status(fd,&TimeoutValue,&WdtStatus);
	printf("Current Timeout value is %d secs, WDT is %s\n",TimeoutValue ,(WdtStatus == 0) ? "Disabled" : "Enabled" );
	WatchDog_Control(fd, 15);  //WDT Timeout Value be set as 15 secs and enable function
	WatchDog_Status(fd,&TimeoutValue,&WdtStatus);
	printf("Current Timeout value is %d secs, WDT is %s\n",TimeoutValue ,(WdtStatus == 0) ? "Disabled" : "Enabled" );
	
	usleep(1000000*5); //5 secs
	WatchDog_Control(fd, 20);  //WDT Timeout Value be set as 20 secs and enable function
	WatchDog_Status(fd,&TimeoutValue,&WdtStatus);
	printf("Current Timeout value is %d secs, WDT is %s\n",TimeoutValue ,(WdtStatus == 0) ? "Disabled" : "Enabled" );

	WatchDog_Control(fd, 0);  //Disable WDT function
	WatchDog_Status(fd,&TimeoutValue,&WdtStatus);
	printf("Current Timeout value is %d secs, WDT is %s\n",TimeoutValue ,(WdtStatus == 0) ? "Disabled" : "Enabled" );

	//If you want system to mute ,You can disable BeatBeep
	//WatchDog_BeatBeep(fd, 0);  //Disable BeatBeep

	GbtLinuxFuncDrv_Uninit(fd);
	return 0;
}


