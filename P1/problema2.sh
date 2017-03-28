if [ ! -f $1 ]
then
	echo "$1 does not exist"
	exit 1
fi
line=$(head -n 1 $1)
for i in $line
do
	for ((j=1;j<= $2;j++))
	do 
		echo -n "${i%,} "
	done
	echo ""
done

