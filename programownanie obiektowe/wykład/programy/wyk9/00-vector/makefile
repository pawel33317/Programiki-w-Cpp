all: vector1 vector2 vector3

vector1: vector1.o
	g++ -g -Wall -pedantic $^ -o $@

vector1.o: vector1.cpp
	g++ -g -c -Wall -pedantic $< -o $@

vector2: vector2.o
	g++ -g -Wall -pedantic $^ -o $@

vector2.o: vector2.cpp
	g++ -g -c -Wall -pedantic $< -o $@

vector3: vector3.o
	g++ -g -Wall -pedantic $^ -o $@

vector3.o: vector3.cpp
	g++ -g -c -Wall -pedantic $< -o $@


.PHONY: clean

clean:
	-rm vector1.o vector1 vector2.o vector2 vector3.o vector3