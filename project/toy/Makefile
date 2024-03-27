# makfile configuration
COMMON_OBJECTS  =
CPU             = msp430g2553
CFLAGS          = -mmcu=${CPU} -I../h -L/opt/ti/msp430_gcc/include


#switch the compiler (for the internal make rules)
CC              = msp430-elf-gcc
AS              = msp430-elf-as


all: buzzer.elf


#additional rules for files
buzzer.elf: ${COMMON_OBJECTS} buzzer.o led.o main.o wdInterruptHandler.o stateMachines.o ../lib/libTimer.a
	${CC} ${CFLAGS} -o $@ $^


load: buzzer.elf
	msp430loader.sh  $^

clean: $^
	rm -f *.o *.elf *~


buzzer.o: buzzer.h
main.o: buzzer.h led.h 
led.o: led.c led.h
stateMachines.o: stateMachines.c stateMachines.h led.h
wdInterruptHandler.o: stateMachines.h
