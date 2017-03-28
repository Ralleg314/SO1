if [ ! -f $1 ]
then
	echo "$1 does not exist";
	exit 1
fi

if [ ! -d $2 ]
then
	mkdir $2
fi

cp $1 $2
exit 0
