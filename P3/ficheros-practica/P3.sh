cd grep-experiments/
#Gets all lines with evil and will
echo "Whithout line number"
egrep evil book.txt |egrep will
echo
#Gets all lines with evil and will and the line they are on
echo "With line number:"
egrep -n evil book.txt | egrep will
echo 
#Gets all lines with evil and will and formats the info,
#separing the columns by :
echo "Formated:"
egrep -n evil book.txt | egrep will  | awk -F ":" '{print $2 " - Line number: "  $1}'
echo
#Gets all lines with an email, which has to have an at and, at least, one dot
#after the at
#Characters can only be alphanumeric, ., _ or -
echo "email lines:"
egrep "[._0-Z\-]*@.*\.[._0-Z]*" book.txt 
echo
#-o gets only the word
#-n gets the line they are on
echo "emails:"
egrep -on "[._0-Z\-]*@.*\.[._0-Z]*" book.txt 

