# Buscamos el proceso principal en la lista deprocesos
pidPrincipal=$(ps aux | egrep ./principal$ | awk '{print $2}')

# Le enviamos la señal de iniciar el contador
kill -SIGCONT $pidPrincipal
# Le enviamos la señal de mostrar el contador
kill -SIGALRM $pidPrincipal
