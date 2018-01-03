

all: template
	g++ main.cpp template.o -o main

template:
	g++ -c template.cpp

.PHONY: clean

clean:
	rm ./*.o