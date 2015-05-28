all: newhandler placementnew placement2 testvector

newhandler: newhandler.o
	g++ -g -Wall -pedantic $^ -o $@

newhandler.o: newhandler.cpp
	g++ -g -c -Wall -pedantic $< -o $@

placementnew: placementnew.o
	g++ -g -Wall -pedantic $^ -o $@

placementnew.o: placementnew.cpp
	g++ -g -c -Wall -pedantic $< -o $@

placement2: placement2.o
	g++ -g -Wall -pedantic $^ -o $@

placement2.o: placement2.cpp
	g++ -g -c -Wall -pedantic $< -o $@

testvector: testvector.o
	g++ -g -Wall -pedantic $^ -o $@


testvector.o: testvector.cpp vector.h
	g++ -g -c -Wall -pedantic $< -o $@


.PHONY: clean

clean:
	-rm newhandler.o newhandler placementnew.o placementnew placement2.o placement2 testvector.o testvector