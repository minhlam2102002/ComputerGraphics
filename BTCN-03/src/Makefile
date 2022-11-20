# Usage:
# make        # compile all binary
# make build  # build the release binary
# make clean  # remove ALL binaries and objects

.PHONY = all clean main

RELEASE_DIR := ./release
LIBS_DIR = ./release/libs/

LIBS = -lglut -lGLU -lGL

# FLAGS = -Wl,-rpath,$(LIBS_DIR)
LINKERFLAG = -lm

TARGET = main.cpp
SRCS := $(wildcard *.cpp)
SRCS := $(filter-out $(TARGET), $(SRCS))
HDRS = $(wildcard *.h)
OBJS = $(SRCS:%.cpp=%.o)

all: $(OBJS) main

%.o: %.cpp
	${CXX} -c $< -o $@ $(LIBS)
main: $(TARGET) $(SRCS) $(HDRS)
	$(CXX) $(LINKERFLAG) $(TARGET) $(OBJS) -o main $(LIBS)

# build: main.cpp
# 	@echo "Building release..."
# 	$(CXX) main.cpp -o ../release/main -L$(LIBS_DIR) $(LIBS) $(FLAGS)

clean:
	@echo "Cleaning up..."
	$(RM) *.o main
