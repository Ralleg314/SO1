rm myprog_dynamic

clear

echo "Compiling files.."
gcc -c -fPIC main.c calculator.c counter.c
echo "Creating library.."
gcc -shared -o libmyutils.so counter.o calculator.o
echo "Linking files.."
gcc main.o -o myprog_dynamic ./libmyutils.so -lm
echo "Cleaning files"
rm -f *.o *~
echo "Executing myprog.."
./myprog_dynamic
echo "Done!"
