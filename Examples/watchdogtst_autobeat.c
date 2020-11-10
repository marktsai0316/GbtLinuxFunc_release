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

	printf("Example for AutoBeat=Enable \n");
	printf("============================\n");	
	WatchDog_Status(fd,&TimeoutValue,&AutoBeatStatus);
	printf("before set as 10secs,Timeout value is %d secs, %s\n",TimeoutValue ,(AutoBeatStatus == 0) ? "AutoBeat is Enable" : "AutoBeat is Disable" );


//Enable WDT , Set Timeout=10 and AutoBeat=Enable
	WatchDog_Control(fd, 10, 1);  //WDT Timeout Value be set as 10 secs and set autobeat=1
	WatchDog_Status(fd,&TimeoutValue,&AutoBeatStatus);
	printf("after set as 10secs, Timeout value is %d secs, %s\n",TimeoutValue ,(AutoBeatStatus == 0) ? "AutoBeat is Enable" : "AutoBeat is Disable" );

	usleep(1000000*2); //2 secs
//	WatchDog_Status(fd,&TimeoutValue,&AutoBeatStatus);
//	printf(" Watchdog_Status : Timeout value is %d secs, %s\n",TimeoutValue ,(AutoBeatStatus == 0) ? "AutoBeat is Enable" : "AutoBeat is Disable" );
	printf("After Sleep(2), system is alive\n");

	usleep(1000000*2); //2 secs
//	WatchDog_Status(fd,&TimeoutValue,&AutoBeatStatus);
//	printf(" Watchdog_Status : Timeout value is %d secs, %s\n",TimeoutValue ,(AutoBeatStatus == 0) ? "AutoBeat is Enable" : "AutoBeat is Disable" );
	printf("After Sleep(2), system is alive\n");

	usleep(1000000*2); //2 secs
//	WatchDog_Status(fd,&TimeoutValue,&AutoBeatStatus);
//	printf(" Watchdog_Status : Timeout value is %d secs, %s\n",TimeoutValue ,(AutoBeatStatus == 0) ? "AutoBeat is Enable" : "AutoBeat is Disable" );
	printf("After Sleep(2), system is alive\n");

	usleep(1000000*2); //2 secs
//	WatchDog_Status(fd,&TimeoutValue,&AutoBeatStatus);
//	printf(" Watchdog_Status : Timeout value is %d secs, %s\n",TimeoutValue ,(AutoBeatStatus == 0) ? "AutoBeat is Enable" : "AutoBeat is Disable" );
	printf("After Sleep(2), system is alive\n");

	usleep(1000000*2); //2 secs
//	WatchDog_Status(fd,&TimeoutValue,&AutoBeatStatus);
//	printf(" Watchdog_Status : Timeout value is %d secs, %s\n",TimeoutValue ,(AutoBeatStatus == 0) ? "AutoBeat is Enable" : "AutoBeat is Disable" );
	printf("After Sleep(2), system is alive\n");

	usleep(1000000*2); //2 secs
//	WatchDog_Status(fd,&TimeoutValue,&AutoBeatStatus);
//	printf(" Watchdog_Status : Timeout value is %d secs, %s\n",TimeoutValue ,(AutoBeatStatus == 0) ? "AutoBeat is Enable" : "AutoBeat is Disable" );
	printf("After Sleep(2), system is alive\n");

	printf("\nYou never encounter system reset,unless system crash......\n\n");

	
//Disable WDT	
	WatchDog_Control(fd, 0,0);  //Disable WDT function 
//	WatchDog_Status(fd,&TimeoutValue,&AutoBeatStatus);
//	printf(" Watchdog_Status : Timeout value is %d secs, %s\n",TimeoutValue ,(AutoBeatStatus == 0) ? "AutoBeat is Enable" : "AutoBeat is Disable" );


	GbtLinuxFuncDrv_Uninit(fd);
	return 0;
}


