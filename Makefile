CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17
LDLIBS = -lraylib -lm

sim: main.cpp
	$(CXX) $(CXXFLAGS) main.cpp -o sim $(LDLIBS)

clean:
	rm -f sim
