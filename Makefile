<<<<<<< HEAD
lab_3: huvud.o driv.o strang.o
=======
lab3: huvud.o driv.o strang.o
>>>>>>> 5545ab0ee5c3f32f26680f4028801f626fbc32fa
	gcc -Wall -o lab3 huvud.o driv.o strang.o
huvud.o: huvud.c driv.h
	gcc -c huvud.c
driv.o: driv.c driv.h strang.h
	gcc -c driv.c
strang.o: strang.c strang.h 
	gcc -c strang.c

clean:
	rm *.o