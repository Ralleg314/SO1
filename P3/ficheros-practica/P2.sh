#Takes all .txt files
files=$(find base_dades -name '*\.txt')
#Takes all files in all directories named etextxx, where xx are two numbers
#from 0 to 9
etext=$(ls $files | egrep 'etext??/*')
#Counts the words, lines and number of chars of all given files
#and stores this data into table.txt
wc $etext > table.txt
#Sorts the file by the values of the 3rd column greatest to lowest
sort -nk3 -r table.txt > tmp.txt 
#Shows the files with less and more words
echo "El numero de ficheros analizados es $(cat table.txt | wc -l)" > score.txt
echo "Los 10 ficheros con mayos palabras"
head -n 10 tmp.txt
echo "Los 10 ficheros con menos palabras"
tail -n 10 tmp.txt
