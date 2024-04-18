# Music Machine


## Description
Music Machine is a program that runs on a MSP430. Each button on the
microcontroller playes a song and each has a unique LED sequence.

## How To Use
When the  music machine is in idle state, the red led is flashing. Depending
on the button pushed, a song will be played along with a unique LED
sequence. To go back to idle  state press the reset button.

## Compilation Instructions
To build all necessary files, go to the project directory and input the
command **make all**. After building all the files, to load the program onto
the MSP430, use **make load** in the toy directory. To clean both directories,
go to project directory and input the command **make clean**.

```bash
make all
cd toy/
make load
cd..
make clean
```
