#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{	
	char tab[99]="abc";
	char tab2[99]="abc";
	strcat(tab,tab2);//��czy �a�cuchy
	printf("strcat = %s\n",tab);
	strcpy(tab,"abc");strcpy(tab2,"def");
	printf("strcmp = %d\n",strcmp(tab,tab2));//potuwnuje �a�cuchy 0 jak takie same -1 jak r�ne
	strcpy(tab,"abc");strcpy(tab2,"def");
	printf("strchr = %d\n",strchr(tab,"b"));//zwraca adres pierwszej litery b strrchr ostatniej
	strset(tab,'x');//wype�nia znekiem x ca�� tablic� lib od kt�rego� jej momentu
	printf("strset = %s\n",tab);
	strcpy(tab,"abc");
	strupr(tab);//na du�e
	printf("strupr = %s\n",tab);
	strlwr(tab);//na ma�e
	printf("strlwr = %s\n",tab);



	//i wiele wiele innych




	system("PAUSE");	
	return 0;
}
