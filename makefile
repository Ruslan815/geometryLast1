.PHONY: all clean
CC = gcc
CFLAGS= -Wall -Werror
EXECUTABLE = geometry
all: bin/$(EXECUTABLE)

bin/$(EXECUTABLE):build/my_prog.o build/perimetr.o build/square.o
	$(CC) $(CFLAGS) build/my_prog.o build/perimetr.o build/square.o -lm -o bin/$(EXECUTABLE)
build/my_prog.o: src/my_prog.c
	$(CC) $(CFLAGS) src/my_prog.c -o build/my_prog.o -c -lm 

build/perimetr.o: src/perimetr.c
	$(CC) $(CFLAGS) src/perimetr.c -o build/perimetr.o -c -lm 

build/square.o: src/square.c
	$(CC) $(CFLAGS) src/square.c -o build/square.o -c -lm 

clean:
	rm -rf build/*.o bin/*.exe 
