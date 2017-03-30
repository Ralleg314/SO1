cd grep-experiments/
echo "Whithout line number"
egrep evil book.txt |egrep will
echo
echo "With line number:"
egrep -n evil book.txt | egrep will
echo 
echo "Formated:"
egrep -n evil book.txt | egrep will  | awk -F ":" '{print $2 " - Line number: "  $1}'
echo
echo "email lines:"
egrep "[._0-Z]*@.*\.[._0-Z]*" book.txt 
echo
echo "emails:"
egrep -on "[._0-Z]*@.*\.[._0-Z]*" book.txt 

