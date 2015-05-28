#include <stdio.h>
#include <stdlib.h>
struct dat{
char d;
char m;
short y;
}zmienna;

typedef struct{
char nazwisko[10];
char *adres;
int zzz;
struct dat da_ur;
}osoba;
int main()
{	
	osoba student,*st;
	struct dat d1,d2,d3={15,5,2012};//tylko d3 == {} i tak tylko przy deklaracji
	printf("d3.d = %d\n",d3.d);
	d2=d3;
	zmienna=d3;
	printf("d2.d = %d\n",d2.d);
	printf("zmienna.d = %d\n",zmienna.d);

	student.da_ur.y=1991;
	printf("student.da_ur.y=%d\n",student.da_ur.y);

	st=(struct dat*)malloc(sizeof(osoba));//(struct dat*) nie konieczne
	(*st).da_ur.y=2000; // WA¯NE === st->da_ur === &student
	printf("(*st).da_ur.y==%d\n",(*st).da_ur.y);
	st->da_ur.y=2012;
	printf("st->da_ur.y==%d\n",(*st).da_ur.y);
	(*st).nazwisko=="czubak";
	//printf("st->nazwisko==%s\n",st->nazwisko); nie dzia³a nie wiem czemu

	system("PAUSE");	
	return 0;
}
// . selektor bezpoœredni umo¿liwia dotarcie do poszczególnej zmiennej