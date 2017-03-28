mkdir problema3
cd problema3
ext=$(cat ../$1)
f=$(ls ../$2)
for i in $ext
do
	mkdir $i
done
for i in $f
do
	for j in $ext
	do
		if [ ${i#*.} = $j ]
		then
			mv ../$2/$i $j
		fi
	done
done
mkdir otros
mv ../$2/* otros
