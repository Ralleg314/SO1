cd grep-experiments/
echo "Whithout line number"
egrep 'evil.*will | will.*evil' *
echo
echo "With line number:"
egrep -n 'evil.*will | will.*evil' *

