#Takes all files in coreutils directory
files=$(find coreutils-8.25 -type f)
#Takes the files that end with .sh
scripts=$(ls $files | egrep '*\.sh')
#Changes the permisions of the user for all those files to executable
chmod u+x $scripts
#Creates shFiles directory
mkdir shFiles
#Copies all script files into shFiles directory
cp $scripts shFiles
#Changes the date from all files that start with a s to 02/03/1996
touch --date="1996-03-02"  shFiles/s*
#Prints all files that have had its date changed
ls -l shFiles/s*
