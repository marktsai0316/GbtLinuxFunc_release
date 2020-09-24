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


/*

int ledPin = 13;                 // LED connected to digital pin 13

void setup()
{
  pinMode(ledPin, OUTPUT);      // sets the digital pin as output
}

void loop()
{
  digitalWrite(ledPin, HIGH);   // sets the LED on
  delay(1000);                  // waits for a second
  digitalWrite(ledPin, LOW);    // sets the LED off
  delay(1000);                  // waits for a second
}
*/


//Example:
int test1(void)
{

	int fd=GbtLinuxFuncDrv_Init();
	int ledPin = PIN1;

	DigitalIo_PinMode(fd, ledPin, OUTPUT);
	//sleep(1); // one second
	usleep(1000000); //one second
	DigitalIo_DigitalWrite(fd, ledPin, HIGH ); //sets the LED on
	usleep(1000000); //one second
	DigitalIo_DigitalWrite(fd, ledPin, LOW );  //sets the LED off
	usleep(1000000); //one second

	GbtLinuxFuncDrv_Uninit(fd);
	return 0;
}

int test_gpio_input(void)
{
	int value;

	int fd=GbtLinuxFuncDrv_Init();
	int ledPin = PIN1;

	DigitalIo_PinMode(fd, ledPin, INPUT);
	if(DigitalIo_DigitalRead(fd, ledPin))
	{
	
		printf("Pin Status is HIGH\n");
	}
	else
	{
		printf("Pin Status is LOW\n");
	}
	GbtLinuxFuncDrv_Uninit(fd);
	return 0;
}


void test_gpio_output(int ledPin,int level)
{

	int fd=GbtLinuxFuncDrv_Init();
	int ret_level;
	int retcode;
	printf("\n");
	retcode=DigitalIo_PinMode(fd, ledPin, OUTPUT);
	if(retcode<0)
	{
		printf("Pin%d maybe not support......\n",ledPin);
		return;
		
	}
	printf("Set Pin%d to %s\n",ledPin,(level==HIGH) ? "HIGH":"LOW");
	DigitalIo_DigitalWrite(fd, ledPin, level ); //sets the LED on
	ret_level=DigitalIo_DigitalRead(fd, ledPin);
	if(ret_level != level)
	   printf("\t");

	if(DigitalIo_DigitalRead(fd, ledPin))
	{
	
		printf("Pin%d Status is HIGH\n",ledPin);
	}
	else
	{
		
		printf("Pin%d Status is LOW\n",ledPin);
	}
	GbtLinuxFuncDrv_Uninit(fd);
	return ;
}

int main(void)
{
	int i;
	//test_gpio_input();
	//for(i=1;i<=26;i++)
	//	test_gpio_output(i,HIGH);
	for(i=1;i<=26;i++)
		test_gpio_output(i,LOW);
	return 0;
}


