CC = g++

all: template
	g++ main.cpp template.o -o main

template:
	g++ -c template.cpp

.PHONY: clean

clean:
	rm ./*.o

test:
	$(CC) ./*_test.cpp -o tests.exe; ./tests.exe;	