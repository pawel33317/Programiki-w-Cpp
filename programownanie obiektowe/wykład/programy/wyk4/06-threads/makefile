all: threads1 threads2 volatile1 volatile2

threads1: threads1.o
	g++ -g -Wall -pedantic $^ -o $@ -lpthread

threads1.o: threads1.cpp
	g++ -g -c -Wall -pedantic $< -o $@

threads2: threads2.o
	g++ -g -Wall -pedantic $^ -o $@ -lpthread

threads2.o: threads2.cpp rcstring.h
	g++ -g -c -Wall -pedantic $< -o $@

volatile1: volatile1.o
	g++ -g -Wall -pedantic $^ -o $@ -lpthread

volatile1.o: volatile1.s
	g++ -g -c -Wall -pedantic $< -o $@

volatile1.s: volatile1.cpp
	g++ -O2 -S -g -c -Wall -pedantic $< -o $@


volatile2: volatile2.o
	g++ -g -Wall -pedantic $^ -o $@ -lpthread

volatile2.o: volatile2.s
	g++ -g -c -Wall -pedantic $< -o $@

volatile2.s: volatile2.cpp
	g++ -O2 -S -g -c -Wall -pedantic $< -o $@


.PHONY: clean

clean:
	-rm threads1.o threads1 threads2.o threads2 volatile1.o volatile1 volatile2.o volatile2 volatile1.s volatile2.s