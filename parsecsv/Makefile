CC = g++
CFLAGS = -std=c++14 

main: main.o readcsv.o
	$(CC) $(CFLAGS) -o readcsv main.o readcsv.o 

main.o: main.cpp readcsv.h
	$(CC) $(CFLAGS) -c main.cpp

readcsv.o: readcsv.h

clean:
	\rm -f *.o readcsv *~ *#