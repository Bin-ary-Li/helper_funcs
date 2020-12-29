CC = g++
CFLAGS = -std=c++14 

main: main.o readcsv.o
	$(CC) $(CFLAGS) -o main.out main.o readcsv.o 

main.o: main.cpp readcsv.h
	$(CC) $(CFLAGS) -c main.cpp

readcsv.o: readcsv.h

clean:
	\rm -f *.o main.out