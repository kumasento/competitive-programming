all: $(patsubst %.cc, %.exe, $(wildcard *.cc))

%.exe: %.cc Makefile
	g++ $< -o $@ -std=c++17
