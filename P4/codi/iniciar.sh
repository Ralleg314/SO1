# Limpia procesos que se haya podiso quedar
./limpiar.sh
# Elimina los archivos '.PID'
rm -f "*pid"

# Ejecutamos todos los ejecutables en paralelo
./principal &
./horas &
./minutos &
./segundos &
