# Usage:
# make        # compile all binary
# make clean  # remove ALL binaries and objects

.PHONY = all clean

# compiler to use
CC = g++
LINKERFLAG = -lm
FLAGS =

LIBS = -lglut -lGLU -lGL

TARGET = main.cpp
BIN = main

SRCS := $(wildcard *.cpp)
SRCS := $(filter-out $(TARGET), $(SRCS))

HDRS = $(wildcard *.h)
OBJS = $(SRCS:%.cpp=%.o)

all: $(TARGET) $(SRCS) $(HDRS) $(OBJS)
	@echo "Compiling.."
	$(CC) $(LINKERFLAG) $(TARGET) $(OBJS) -o $(BIN) $(LIBS)

%.o: %.cpp
	@echo "Creating object %..."
	${CC} -c $< -o $@ $(LIBS)

clean:
	@echo "Cleaning up..."
	$(RM) *.o $(BIN)
