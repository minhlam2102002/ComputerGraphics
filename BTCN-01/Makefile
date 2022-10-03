# Usage:
# make        # compile all binary
# make clean  # remove ALL binaries and objects

.PHONY = all main clean

LIBS = -lglut -lGLU -lGL

all: main

main: main.o
	@echo "Linking main"
	$(CXX) $(LIBS) main.o -o main

main.o: main.cpp
	@echo "Creating object.."
	$(CXX) $(CFLAGS) -c main.cpp

clean:
	@echo "Cleaning up..."
	$(RM)  *.o main
