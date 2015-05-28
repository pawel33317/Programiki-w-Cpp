funptr: funptr.o
	g++ -g -Wall $^ -o $@

funptr.o: funptr.cpp
	g++ -g -c -Wall $< -o $@

.PHONY: clean

clean:
	-rm funptr.o funptr