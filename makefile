proj4: proj41.o proj42.o proj43.o
	gcc -o proj4 proj41.o proj42.o proj43.o
	
proj41.o: proj41.c  proj4.h
	gcc -c proj41.c
	
proj42.o: proj42.c proj4.h
	gcc -c proj42.c
	
proj43.o: proj43.c proj4.h
	gcc -c proj43.c



