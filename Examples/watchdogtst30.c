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

	WatchDog_Status(fd,&TimeoutValue,&WdtStatus);
	printf("Current Timeout value is %d secs, WDT is %s\n",TimeoutValue ,(WdtStatus == 0) ? "Disabled" : "Enabled" );
	WatchDog_Control(fd, 30);  //WDT Timeout Value be set as 15 secs and enable function
	WatchDog_Status(fd,&TimeoutValue,&WdtStatus);
	printf("Current Timeout value is %d secs, WDT is %s\n",TimeoutValue ,(WdtStatus == 0) ? "Disabled" : "Enabled" );
	

	GbtLinuxFuncDrv_Uninit(fd);
	return 0;
}


