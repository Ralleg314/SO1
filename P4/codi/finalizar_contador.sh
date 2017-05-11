# Busco el proceso principal en la lista de procesos
pidPrincipal=$(ps aux | egrep principal$ | awk '{print $2}')

# Envio la señal de mostrar el reloj
kill -SIGALRM $pidPrincipal
# Envio la señal de finalizar el reloj
kill -SIGTERM $pidPrincipal
