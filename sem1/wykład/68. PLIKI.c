#include <stdio.h>
#include <stdlib.h>

int main()
{	
	int fcloseall(void);
	char s[20];char zn;
	FILE * st;
	st=fopen("c:/a.txt","r");//w,r,a,w+,w+,a+,rt,wb,   b-binarnie   t-tekstowo
	//_acces(name 0)   0->plik istnieje -1 nie istnieje


	printf("%c\n",getc(st));//pobiera pierwszy znak z pliku
	fgets(s,20,st);//pobiera 20 znaków z pliku i zapisuje do tablicy s
	printf("%s\n",s);
	fseek(st, 0, 0);//ustawia wskaŸnik na pocz¹tku pliku
	while(!feof(st)){zn=getc(st);printf("%c", zn);}
	fseek(st, 0, 0);//ustawia wskaŸnik na pocz¹tku pliku
	//fread(s, 20, 10, st);odczytuje z pliku size_t fread(void *ptr, size_t size, size_t nitems, FILE *stream);
	printf("%s\n\n\n",s);
	fclose(st);
	//feof(st)       ==1 gdy koniec pliku
	// ungetc( int c, FILE *stream ); Funkcja zwraca znak c z powrotem do stumienia stream. Przy najbli¿szej operacji czytania z tego strumienia znak pojawi siê ponownie, jako pierwszy.
	st=fopen("c:/a.txt","w");
	fprintf(st,"1f(%2.2f) = %13.4f",233.33,12.445);//zapisuje do pliku
	//long ftell(FILE *file); zwraca pozucjê pliku
	//fputc (1, st);
	fputs("Hello world!\n", st);//dopisuje do pliku
	fwrite(s, 20, 20, st);				//size_t fwrite(const void *ptr, size_t size, size_t nitems, FILE *stream); dopisuje tablicê do pliku
	fclose(st);
	//fputc(), która umieszcza pojedynczy znak w pliku    fputc (c, st);   c=int
	
	system("PAUSE");	
	return 0;
}
