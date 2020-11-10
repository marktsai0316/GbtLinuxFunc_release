
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

//Defining Digital Pins ID : D0~D9
#define D0 	0
#define D1 	1
#define D2 	2
#define D3 	3
#define D4 	4
#define D5 	5
#define D6 	6
#define D7 	7
#define D8 	8
#define D9 	9

//Defining Digital Pins ID : PIN1~PIN26
#define PIN1 	1
#define PIN2 	2
#define PIN3 	3
#define PIN4 	4
#define PIN5 	5
#define PIN6 	6
#define PIN7 	7
#define PIN8 	8
#define PIN9 	9
#define PIN10 	10
#define PIN11 	11
#define PIN12 	12
#define PIN13 	13
#define PIN14	14
#define PIN15 	15
#define PIN16 	16
#define PIN17 	17
#define PIN18 	18
#define PIN19	19
#define PIN20 	20
#define PIN21 	21
#define PIN22 	22
#define PIN23 	23
#define PIN24	24
#define PIN25 	25
#define PIN26	26


//Defining Digital Pins modes: INPUT, INPUT_PULLUP, and OUTPUT

#define INPUT 		0
#define INPUT_PULLUP 	1
#define OUTPUT 		2

//Defining Pin Levels: HIGH and LOW
#define HIGH 		1
#define LOW 		0



int GbtLinuxFuncDrv_Init();
void GbtLinuxFuncDrv_Uninit(int fd);

int DigitalIo_PinMode(int fd, int pin , int mode);
int DigitalIo_DigitalWrite(int fd, int pin,int value );
int DigitalIo_DigitalRead(int fd, int pin );

int DebugPort_Write(int fd, unsigned char value );

int WatchDog_Control(int fd, unsigned int interval,unsigned int AutoBeatEn); //0 : Disable  , 1~255 unit in second
int WatchDog_Status(int fd, unsigned short *pTimeoutValue, unsigned short *pAutoBeatStatus); 
int WatchDog_AutoBeat(int fd, int Enable);
int WatchDog_KeepAlive(int fd, unsigned short *pTimeoutValue, unsigned short *pWdtStatus); 
int WatchDog_BeatBeep(int fd, int Enable);

int SpeakerBeep_Control(int fd, unsigned short note,unsigned short duration);

typedef struct _DIGITALIO {
	int pinnumber;
	union {
		int mode;
		int value;
	}u;
} DIGITALIO,*PDIGITALIO;



#define GBTLINUXFUNC_DIGITALIO_PINMODE		_IOW(0xbb, 0x20, DIGITALIO)
#define GBTLINUXFUNC_DIGITALIO_DIGITALWRITE	_IOW(0xbb, 0x21, DIGITALIO)
#define GBTLINUXFUNC_DIGITALIO_DIGITALREAD	_IOR(0xbb, 0x22, DIGITALIO)

#define GBTLINUXFUNC_DEBUGPORT_WRITE		_IOW(0xbb, 0x23, unsigned char)

#define GBTLINUXFUNC_WATCHDOG_CONTROL	_IOW(0xbb, 0x25, unsigned int)
#define GBTLINUXFUNC_WATCHDOG_STATUS	_IOR(0xbb, 0x26, unsigned int)
#define GBTLINUXFUNC_WATCHDOG_AUTOBEAT	_IOW(0xbb, 0x27, unsigned int)
#define GBTLINUXFUNC_WATCHDOG_KEEPALIVE	_IOR(0xbb, 0x28, unsigned int)
#define GBTLINUXFUNC_WATCHDOG_BEATBEEP	_IOW(0xbb, 0x29, unsigned int)

typedef struct _SPEAKERBEEPIO {
	unsigned short type;
	unsigned short note;
	unsigned short duration;
} SPEAKERBEEPIO,*PSPEAKERBEEPIO;

#define GBTLINUXFUNC_SPEAKERBEEP_CONTROL _IOW(0xbb, 0x28,SPEAKERBEEPIO)


