# Buscamos de la lista de procesos los acabados en
# el nombre de nuestros ejecutables y cogemos su PID
pPID=$(ps aux | egrep principal$ | awk '{print $2}')
hPID=$(ps aux | egrep minutos$ | awk '{print $2}')
mPID=$(ps aux | egrep segundos$ | awk '{print $2}')
sPID=$(ps aux | egrep horas$ | awk '{print $2}')


##	   MATA SEGURO, SIN QUE LO TRATEN	##
##	PORQUE ES PARA ELIMINAR LOS PROCESOS	##
##	    EN CASO DE ERRORES O CUELGUE	##

kill -SIGKILL $pPID
kill -SIGKILL $hPID
kill -SIGKILL $mPID
kill -SIGKILL $sPID


# No se si entran en los comandos permitidos
# pkill -f principal
# pkill -f segundos
# pkill -f minutos
# pkill -f horas
