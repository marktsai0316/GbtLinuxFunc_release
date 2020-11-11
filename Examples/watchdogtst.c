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
	unsigned short TimeoutValue,AutoBeatStatus;
	int fd=GbtLinuxFuncDrv_Init();
	if (fd == -1 ) 
	{
		return -1;
	}
 
////////////////////////////////////////////////////////////////////////////////////////////////////////
//Test1 :When AutoBeat=Enable

	WatchDog_Status(fd,&TimeoutValue,&AutoBeatStatus);
	printf("Old :Timeout value is %d secs, AutoBeat is %s\n",TimeoutValue ,(AutoBeatStatus == 0) ? "Enable" : "Disable" );
	WatchDog_Control(fd, 10,1);  //Set WDT Timeout Value as 10 secs , AutoBeat=Enable
	WatchDog_Status(fd,&TimeoutValue,&AutoBeatStatus);
	printf("New :Timeout value is %d secs, AutoBeat is %s\n",TimeoutValue ,(AutoBeatStatus == 0) ?  "Enable" : "Disable" );
	
	usleep(1000000*5); //5 secs
  usleep(1000000*5); //5 secs
  usleep(1000000*5); //5 secs
  usleep(1000000*5); //5 secs
  
  //You never encounter system reset,unless system crash......

////////////////////////////////////////////////////////////////////////////////////////////////////////
//Test2 :When AutoBeat=Disable
	WatchDog_Status(fd,&TimeoutValue,&AutoBeatStatus);
	printf("Old :Timeout value is %d secs, AutoBeat is %s\n",TimeoutValue ,(AutoBeatStatus == 0) ? "Enable" : "Disable" );
  WatchDog_Control(fd, 10,0);  //Set WDT Timeout Value as 10 secs , AutoBeat=Disable
	WatchDog_Status(fd,&TimeoutValue,&AutoBeatStatus);
	printf("New :Timeout value is %d secs, AutoBeat is %s\n",TimeoutValue ,(AutoBeatStatus == 0) ?  "Enable" : "Disable" );


  usleep(1000000*5); //5 secs
	WatchDog_KeepAlive(fd,&TimeoutValue,&AutoBeatStatus);
	printf(" Watchdog_KeepAlive : Timeout value is %d secs, AutoBeat is %s\n",TimeoutValue ,(AutoBeatStatus == 0) ? "Enable" : "Disable" );

	usleep(1000000*5); //5 secs
	WatchDog_KeepAlive(fd,&TimeoutValue,&AutoBeatStatus);
	printf(" Watchdog_KeepAlive : Timeout value is %d secs, AutoBeat is %s\n",TimeoutValue ,(AutoBeatStatus == 0) ? "Enable" : "Disable" );

	usleep(1000000*5); //5 secs
	WatchDog_KeepAlive(fd,&TimeoutValue,&AutoBeatStatus);
	printf(" Watchdog_KeepAlive : Timeout value is %d secs, AutoBeat is %s\n",TimeoutValue ,(AutoBeatStatus == 0) ? "Enable" : "Disable" );

  //You must peroidly call keepAlive to avoid System reset

	WatchDog_Control(fd, 0,0);  // Disable WDT function
	WatchDog_Status(fd,&TimeoutValue,&AutoBeatStatus);
	printf(" WatchDog_Status : Timeout value is %d secs, AutoBeat is %s\n",TimeoutValue ,(AutoBeatStatus == 0) ?  "Enable" : "Disable" );


	GbtLinuxFuncDrv_Uninit(fd);
	return 0;
}
