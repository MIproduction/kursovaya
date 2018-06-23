CXX = g++
CFLAGS = $(CXX) -c -Wall -Werror
OBJECTS = build/main.o build/ninja.o build/textinit.o build/results.o
.PHONY: all clean

all: bin build bin/prog

bin/prog: $(OBJECTS)
	$(CXX) $(OBJECTS) -o bin/prog

build/main.o: src/main.cpp src/head.h
	$(CFLAGS) src/main.cpp -o build/main.o

build/ninja.o: src/ninja.cpp src/head.h
	$(CFLAGS) src/ninja.cpp -o build/ninja.o

build/textinit.o: src/textinit.cpp src/head.h
	$(CFLAGS) src/textinit.cpp -o build/textinit.o

build/results.o: src/results.cpp src/head.h
	$(CFLAGS) src/results.cpp -o build/results.o

bin:
	mkdir bin
build:
	mkdir build
clean:
	-rm -rf build/*.o bin/*.exe