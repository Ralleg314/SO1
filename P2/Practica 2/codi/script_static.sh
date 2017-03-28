rm myprog_static

clear

echo "Compiling files.."
gcc -c main.c -o main.o
echo "Creating library.."
ar rcs libmyutils.a counter.c calculator.c
echo "Linking files.."
gcc main.o -o myprog_static libmyutils.a -lm
echo "Cleaning files"
rm -f *.o *~
echo "Executing myprog_static.."
./myprog_static
echo "Done!"
