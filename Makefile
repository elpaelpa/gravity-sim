CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17
LDLIBS = -lraylib -lm

sim: main.cpp physics.cpp physics.h
	$(CXX) $(CXXFLAGS) main.cpp physics.cpp -o sim $(LDLIBS)

clean:
	rm -f sim
