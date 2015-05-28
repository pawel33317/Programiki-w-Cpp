#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{	
char s[]="abc";
printf("%d\n",strlen(s));	//3
printf("%d\n",sizeof(s));	//4
printf("%d\n",strlen("AB"));//2
printf("%d\n",sizeof("AB"));//3
//strlen dzia³a na etapie wykonywania programu
//sizeof dzia³a na etapie kompillacji



	system("PAUSE");	
	return 0;
}
