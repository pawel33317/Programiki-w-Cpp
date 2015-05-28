testlist: testlist.o list.o
	g++ -g -Wall $^ -o $@

list.o: list.cpp list.h
	g++ -g -c -Wall $< -o $@

testlist.o: testlist.cpp list.h
	g++ -g -c -Wall $< -o $@

.PHONY: clean

clean:
	-rm list.o testlist.o testlist