# Buscamos el proceso principal en la lista de procesos
pidPrincipal=$(ps aux | egrep ./principal$ | awk '{print $2}')

# Enviamos la señal de mostrar el reloj
kill -SIGALRM $pidPrincipal
