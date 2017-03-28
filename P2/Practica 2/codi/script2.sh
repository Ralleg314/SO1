gcc -c -fPIC main2.c counter.c calculator.c
gcc main2.o calculator.o counter.o -o myprog2 -lm
