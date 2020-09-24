all : WATCHDOG WATCHDOG30 DIGITALIO DEBUGPORT SPEAKERBEEP
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

WATCHDOG30:	GbtLinuxFunc.o watchdogtst30.o 
	$(g) -o watchdogtst30 watchdogtst30.o GbtLinuxFunc.o -lpthread

watchdogtst30.o:	watchdogtst30.c GbtLinuxFunc.h
	$(g) $(CFLAGS) -c watchdogtst30.c

DEBUGPORT:	GbtLinuxFunc.o debugporttst.o 
	$(g) -o debugporttst debugporttst.o GbtLinuxFunc.o -lpthread

debugporttst.o:	debugporttst.c GbtLinuxFunc.h
	$(g) $(CFLAGS) -c debugporttst.c

SPEAKERBEEP:	GbtLinuxFunc.o speakerbeeptst.o 
	$(g) -o speakerbeeptst speakerbeeptst.o GbtLinuxFunc.o -lpthread

speakerbeeptst.o:	speakerbeeptst.c GbtLinuxFunc.h
	$(g) $(CFLAGS) -c speakerbeeptst.c

clean:
	rm -f *.o *~ core watchdogtst digitalIotst debugporttst speakerbeeptst
