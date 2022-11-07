# Usage:
# make        # compile all binary
# make build  # build the release binary
# make clean  # remove ALL binaries and objects

.PHONY = all clean main

RELEASE_DIR := ./release
SRC_DIRS := ./src

LIBS = -lglut -lGLU -lGL
LIBS_DIR = ./release/libs/

# FLAGS = -Wl,-rpath,$(LIBS_DIR)
LINKERFLAG = -lm

TARGET = src/main.cpp
SRCS := $(wildcard src/*.cpp)
SRCS := $(filter-out $(TARGET), $(SRCS))
HDRS = $(wildcard src/*.h)
OBJS = $(SRCS:%.cpp=%.o)


all: $(OBJS) main

%.o: %.cpp
	${CXX} -c $< -o $@ $(LIBS)
main: $(TARGET) $(SRCS) $(HDRS)
	$(CXX) -lm $(TARGET) $(OBJS) -o main $(LIBS)

# build: main.cpp
# 	@echo "Building release..."
# 	$(CXX) main.cpp -o ../release/main -L$(LIBS_DIR) $(LIBS) $(FLAGS)

clean:
	@echo "Cleaning up..."
	$(RM)  *.o src/*.o main
