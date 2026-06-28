CXX = g++
CXXFLAGS = -O3 -s -fvisibility=hidden -shared -fPIC -Wall -Wextra
INCLUDES = -I./include -I./src

TARGET = libjdat.so
SRCS = src/api.cpp src/parser.cpp src/crypto.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)