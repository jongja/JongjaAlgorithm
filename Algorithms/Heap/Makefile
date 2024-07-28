CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17

TARGET = HeapTest.exe

SRCS = HeapTest.cpp

OBJS = $(SRCS:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

clean:
	rm $(OBJS) $(TARGET)