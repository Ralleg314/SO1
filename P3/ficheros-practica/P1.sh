files=$(find coreutils-8.25 -type f)
scripts=$(ls $files | egrep '*\.sh')
chmod u+x $scripts
mkdir shFiles
cp $scripts shFiles
touch --date="1996-03-02"  shFiles/s*
ls -l shFiles/s*
