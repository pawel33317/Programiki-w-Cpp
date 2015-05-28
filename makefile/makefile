#CEL: SKLADNIKI
#	KOMENDA

#< - aktualnie przetwarzany plik z listy składników (patrz przykład)
#@ - nazwa pliku docelowego
#^ - składniki

#####ZMIENNE


CXX=g++			#nazwa kompilatora


CXXLAGS=-Wall -c -O2		
#opcje kompilatora 
#-c compile and assembly not link
#-Wall wyswietla blecy
#-O2 optymalizacja
#-L polozenie biblioteki wskazanej

LFLAGS=			#opcje linkera
OBJS=main.o exampleClas.o class2.o


#####LINKOWANIE


prog: $(OBJS)
	$(CXX) $(LFLAGS) $^ -o $@


#####KOMPILACJA

$(OBJS): %.o: %.cpp	#petla
	$(CXX) $(CXXLAGS) $< -o $@

clean:
	rm -f $(OBJS)

.PHONY: clean
