mkdir problema1
cp $1 problema1/fichero.txt
cd problema1/
for ((i=1;i<= $2; i++))
do
	mkdir "subdir-$i"
	head -n $i fichero.txt > "subdir-$i/$i.txt"
done
cd ..
rm -rf problema1
