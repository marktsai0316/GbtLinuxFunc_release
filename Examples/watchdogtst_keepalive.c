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

	printf("Example for AutoBeat=Disable\n");
	printf("============================\n");	

	WatchDog_Status(fd,&TimeoutValue,&AutoBeatStatus);
	printf("before set as 10secs,Timeout value is %d secs, %s\n",TimeoutValue ,(AutoBeatStatus == 0) ? "AutoBeat is Enable" : "AutoBeat is Disable" );

//Enable WDT and set TimeoutValue=10 & AutoBeat=0
	//Set AutoBeat=0 , So you must call keepalive yourself periodly.
	WatchDog_Control(fd, 10, 0);  //WDT Timeout Value be set as 10 secs and set autobeat=0
	WatchDog_Status(fd,&TimeoutValue,&AutoBeatStatus);
	printf(" Watchdog_Status: Timeout value is %d secs, %s\n",TimeoutValue ,(AutoBeatStatus == 0) ? "AutoBeat is Enable" : "AutoBeat is Disable" );

//periodly call keepalive to avoid timeout.
	WatchDog_KeepAlive(fd,&TimeoutValue,&AutoBeatStatus);
	printf(" Watchdog_KeepAlive : Timeout value is %d secs, %s\n",TimeoutValue ,(AutoBeatStatus== 0) ? "AutoBeat is Enable" : "AutoBeat is Disable" );
	usleep(1000000*2); //2 secs
	printf("After Sleep(2), system is alive\n");
	WatchDog_KeepAlive(fd,&TimeoutValue,&AutoBeatStatus);
	printf(" Watchdog_KeepAlive : Timeout value is %d secs, %s\n",TimeoutValue ,(AutoBeatStatus == 0) ? "AutoBeat is Enable" : "AutoBeat is Disable" );
	usleep(1000000*2); //2 secs
	printf("After Sleep(2), system is alive\n");
	WatchDog_KeepAlive(fd,&TimeoutValue,&AutoBeatStatus);
	printf(" Watchdog_KeepAlive : Timeout value is %d secs, %s\n",TimeoutValue ,(AutoBeatStatus == 0) ? "AutoBeat is Enable" : "AutoBeat is Disable" );
	usleep(1000000*2); //2 secs
	printf("After Sleep(2), system is alive\n");
	WatchDog_KeepAlive(fd,&TimeoutValue,&AutoBeatStatus);
	printf(" Watchdog_KeepAlive : Timeout value is %d secs, %s\n",TimeoutValue ,(AutoBeatStatus == 0) ? "AutoBeat is Enable" : "AutoBeat is Disable" );
	usleep(1000000*2); //2 secs
	printf("After Sleep(2), system is alive\n");
	WatchDog_KeepAlive(fd,&TimeoutValue,&AutoBeatStatus);
	printf(" Watchdog_KeepAlive : Timeout value is %d secs, %s\n",TimeoutValue ,(AutoBeatStatus == 0) ? "AutoBeat is Enable" : "AutoBeat is Disable" );
	usleep(1000000*2); //2 secs
	printf("After Sleep(2), system is alive\n");
	WatchDog_KeepAlive(fd,&TimeoutValue,&AutoBeatStatus);
	printf(" Watchdog_KeepAlive : Timeout value is %d secs, %s\n",TimeoutValue ,(AutoBeatStatus == 0) ? "AutoBeat is Enable" : "AutoBeat is Disable" );
	usleep(1000000*2); //2 secs
	printf("After Sleep(2), system is alive\n");
	WatchDog_KeepAlive(fd,&TimeoutValue,&AutoBeatStatus);
	printf(" Watchdog_KeepAlive : Timeout value is %d secs, %s\n",TimeoutValue ,(AutoBeatStatus == 0) ? "AutoBeat is Enable" : "AutoBeat is Disable" );
	usleep(1000000*2); //2 secs
	printf("After Sleep(2), system is alive\n");
	WatchDog_KeepAlive(fd,&TimeoutValue,&AutoBeatStatus);
	printf(" Watchdog_KeepAlive : Timeout value is %d secs, %s\n",TimeoutValue ,(AutoBeatStatus == 0) ? "AutoBeat is Enable" : "AutoBeat is Disable" );
	usleep(1000000*2); //2 secs
	printf("After Sleep(2), system is alive\n");
	
	printf("\nYou must peroidly call keepAlive to avoid System reset\n\n");

//Disable WDT
	WatchDog_Control(fd, 0,0);  //Disable WDT function 
	WatchDog_Status(fd,&TimeoutValue,&AutoBeatStatus);
	printf(" Watchdog_Status : Timeout value is %d secs, %s\n",TimeoutValue ,(AutoBeatStatus == 0) ? "AutoBeat is Enable" : "AutoBeat is Disable" );

	GbtLinuxFuncDrv_Uninit(fd);
	return 0;
}
 

