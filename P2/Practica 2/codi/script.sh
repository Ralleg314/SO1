#!/bin/bash     

rm myprog

clear

echo "Compiling files.."
gcc -c main.c -o main.o
gcc -c counter.c -o counter.o
gcc -c calculator.c -o calculator.o
echo "Linking files.."
gcc main.o calculator.o counter.o -o myprog -lm
echo "Cleaning files"
rm -f *.o *~
echo "Executing myprog.."
./myprog
echo "Done!"
