# Usage:
# make        # compile all binary
# make build  # build the release binary
# make clean  # remove ALL binaries and objects

.PHONY = all clean

RELEASE_DIR := ./release
SRC_DIRS := ./src


LIBS = -lglut -lGLU -lGL
LIBS_DIR = ./release/libs/

FLAGS = -Wl,-rpath,$(LIBS_DIR)

SRCS = $(wildcard src/views/*.cpp src/geometry/*.cpp)
HEADERS = $(wildcard src/views/*.h src/geometry/*.h src/geometry/basic/*.h)
OBJS = $(SRCS:%.cpp=%.o)

TARGET = src/main.cpp

LINKERFLAG = -lm

all: $(OBJS) main

%.o: %.cpp
	${CXX} -c $< -o $@ $(LIBS)
main: $(TARGET) $(SRCS) $(HEADERS)
	$(CXX) -lm $(TARGET) $(OBJS) -o main $(LIBS)

# release: main.cpp
# 	@echo "Building release..."
# 	$(CXX) main.cpp -o ../release/main -L$(LIBS_DIR) $(LIBS) $(FLAGS)

clean:
	@echo "Cleaning up..."
	$(RM)  *.o src/views/*.o src/geometry/*.o main
