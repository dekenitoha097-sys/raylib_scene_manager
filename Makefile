CXX = g++

CXXFLAGS = -Wall -Wextra -std=c++17
INCLUDES = -Iinclude

CFLAGS = $(shell pkg-config --cflags raylib)
LIBS = $(shell pkg-config --libs raylib)

TARGET = sim

SRC = $(wildcard src/*.cpp)

all:
	$(CXX) $(SRC) -o $(TARGET) $(CXXFLAGS) $(INCLUDES) $(CFLAGS) $(LIBS)

run: all
	./$(TARGET)

clean:
	rm -f $(TARGET)