CXX = g++
CXXFLAGS = -std=c++11 -Wall

SRCS = train.cpp model.cpp
OBJS = $(SRCS:.cpp=.o)
EXEC = train

.PHONY: all clean

all: $(EXEC)

$(EXEC): $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(EXEC)