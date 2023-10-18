# Variables
CXX = g++
CXXFLAGS = -Wall -Wextra -lboost_system
TARGET = server
SRCS = server.cpp
OBJS = $(SRCS:.cpp=.o)

# Default rule
all: $(TARGET)

# Rule to link the program
$(TARGET): $(OBJS)
	$(CXX) -o $@ $^ $(LDFLAGS)

# Rule to compile source files
%.o: %.cpp
	$(CXX) -c $(CXXFLAGS) $< -o $@

# Rule to clean intermediate files and executables
clean:
	rm -f $(OBJS) $(TARGET)

run: $(TARGET)
	./$(TARGET) $(PORT)

# Phony targets (do not represent files)
.PHONY: all clean run

