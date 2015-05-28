testvector: testvector.o
	g++ -g -Wall $^ -o $@

testvector.o: testvector.cpp vector.h
	g++ -g -c -Wall $< -o $@

.PHONY: clean

clean:
	-rm testvector.o testvector