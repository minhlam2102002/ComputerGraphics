# Usage:
# make        # compile all binary
# make build  # build the release binary
# make clean  # remove ALL binaries and objects

LIBS = -lglut -lGLU -lGL
LIBSPATH = ../libs
FLAGS = -Wl,-rpath,$(LIBSPATH)

all: main

main: main.cpp Point.h Line.h Circle.h Parabola.h Hyperbola.h Ellipse.h
	$(CXX) main.cpp -o main $(LIBS)

build: main.cpp
	@echo "Building release..."
	$(CXX) main.cpp -o ../release/main -L$(LIBSPATH) $(LIBS) $(FLAGS)

clean:
	@echo "Cleaning up..."
	$(RM)  *.o main
