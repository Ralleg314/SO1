

# typing 'make' will invoke the first target entry in the file 
# (in this case the default target entry)

default: principal horas minutos segundos

# To create the executable file myprog we need the object files
# principal.o, horas.o, minutos.o, segundos.o:

principal: principal.o 
	gcc principal.o -o principal

horas: horas.o rw_pid.o
	gcc horas.o rw_pid.o -o horas

minutos: minutos.o rw_pid.o
	gcc minutos.o rw_pid.o -o minutos

segundos: segundos.o rw_pid.o
	gcc segundos.o rw_pid.o -o segundos

# Creating object files
principal.o: principal.c  
	gcc -c principal.c

hora.o: horas.c
	gcc -c horas.c

minutos.o: minutos.c
	gcc -c minutos.c

segundos.o:  segundos.c
	gcc -c segundos.c

rw_pid.o: rw_pid.c
	gcc -c rw_pid.c

# To start over from scratch, type 'make clean'.  This
# removes the executable file, as well as old .o object
# files and *~ backup files:
#
clean: 
	$(RM) principal horas minutos segundos *.o *~


