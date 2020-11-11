 all : WATCHDOG WATCHDOG_AUTOBEAT WATCHDOG_KEEPALIVE DIGITALIO DEBUGPORT SPEAKERBEEP
#Which compiler
g = g++

#Where are include files kept
INCLUDE = .

#Options for development
CFLAGS = -g -D_REENTRANT

#Optioms for release
#CFLAGS = -o -D_REENTRANT

GbtLinuxFunc.o:	GbtLinuxFunc.c GbtLinuxFunc.h
	$(g) $(CFLAGS) -c GbtLinuxFunc.c

DIGITALIO:	GbtLinuxFunc.o digitalIotst.o 
	$(g) -o digitalIotst digitalIotst.o GbtLinuxFunc.o -lpthread

digitalIotst.o:	digitalIotst.c GbtLinuxFunc.h
	$(g) $(CFLAGS) -c digitalIotst.c

WATCHDOG:	GbtLinuxFunc.o watchdogtst.o 
	$(g) -o watchdogtst watchdogtst.o GbtLinuxFunc.o -lpthread

watchdogtst.o:	watchdogtst.c GbtLinuxFunc.h
	$(g) $(CFLAGS) -c watchdogtst.c

WATCHDOG_AUTOBEAT:	GbtLinuxFunc.o watchdogtst_autobeat.o 
	$(g) -o watchdogtst_autobeat watchdogtst_autobeat.o GbtLinuxFunc.o -lpthread

watchdogtst_autobeat.o:	watchdogtst_autobeat.c GbtLinuxFunc.h
	$(g) $(CFLAGS) -c watchdogtst_autobeat.c

WATCHDOG_KEEPALIVE:	GbtLinuxFunc.o watchdogtst_keepalive.o 
	$(g) -o watchdogtst_keepalive watchdogtst_keepalive.o GbtLinuxFunc.o -lpthread

watchdogtst_keepalive.o:	watchdogtst_keepalive.c GbtLinuxFunc.h
	$(g) $(CFLAGS) -c watchdogtst_keepalive.c

DEBUGPORT:	GbtLinuxFunc.o debugporttst.o 
	$(g) -o debugporttst debugporttst.o GbtLinuxFunc.o -lpthread

debugporttst.o:	debugporttst.c GbtLinuxFunc.h
	$(g) $(CFLAGS) -c debugporttst.c

SPEAKERBEEP:	GbtLinuxFunc.o speakerbeeptst.o 
	$(g) -o speakerbeeptst speakerbeeptst.o GbtLinuxFunc.o -lpthread

speakerbeeptst.o:	speakerbeeptst.c GbtLinuxFunc.h
	$(g) $(CFLAGS) -c speakerbeeptst.c

clean:
	rm -f *.o *~ core watchdogtst watchdogtst_autobeat watchdogtst_keepalive  digitalIotst debugporttst speakerbeeptst
