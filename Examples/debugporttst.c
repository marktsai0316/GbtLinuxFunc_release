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
	int fd=GbtLinuxFuncDrv_Init();
	DebugPort_Write(fd, 0xAA );
	usleep(1000000*1); //one second
	DebugPort_Write(fd, 0x55 );
	usleep(1000000*1); //one second
	DebugPort_Write(fd, 0xAA );
	usleep(1000000*1); //one second
	DebugPort_Write(fd, 0x55 );
	usleep(1000000*1); //one second
	GbtLinuxFuncDrv_Uninit(fd);
	return 0;
}


