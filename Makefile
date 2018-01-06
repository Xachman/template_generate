CC = g++

all: template
	g++ main.cpp template.o -o main

template:
	g++ -c template.cpp

.PHONY: clean

clean:
	rm ./*.o

test:
	$(CC) main_test_file.o template.cpp ./*_test.cpp -o tests.exe; ./tests.exe;	

main_test:
	$(CC) main_test_file.cpp -c 