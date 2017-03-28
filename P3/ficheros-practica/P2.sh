files=$(find base_dades -name '*\.txt')
etext=$(ls $files | egrep 'etext??/*')
wc $etext > table.txt
sort -nk3 -r table.txt > tmp.txt 
echo "El numero de ficheros analizados es $(cat table.txt | wc -l)" > score.txt
echo "Los 10 ficheros con mayos palabras"
head -n 10 tmp.txt
echo "Los 10 ficheros con menos palabras"
tail -n 10 tmp.txt
