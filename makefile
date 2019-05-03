.PHONY: all clean
CC = gcc
CFLAGS= -Wall -Werror
HEADER= -I thirdparty -I src
EXECUTABLE = geometry
EXECUTABLETEST = geometry-test
all: bin/$(EXECUTABLE) bin/$(EXECUTABLETEST)

bin/$(EXECUTABLE):build/my_prog.o build/perimetr.o build/square.o
	$(CC) $(CFLAGS) build/my_prog.o build/perimetr.o build/square.o -lm -o bin/$(EXECUTABLE)
build/my_prog.o: src/my_prog.c
	$(CC) $(CFLAGS) src/my_prog.c -o build/my_prog.o -c -lm 

build/perimetr.o: src/perimetr.c
	$(CC) $(CFLAGS) src/perimetr.c -o build/perimetr.o -c -lm 

build/square.o: src/square.c
	$(CC) $(CFLAGS) src/square.c -o build/square.o -c -lm 

bin/$(EXECUTABLETEST):build/main.o 
	$(CC) $(CFLAGS) build/main.o -lm -o bin/$(EXECUTABLETEST)
	
build/main.o: test/main.c
	$(CC) $(CFLAGS) -c $(HEADER) test/main.c -o build/main.o 

clean:
	rm -rf build/*.o bin/geometry bin/geometry-test 
