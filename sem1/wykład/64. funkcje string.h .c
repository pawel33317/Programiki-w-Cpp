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
//strlen dzia�a na etapie wykonywania programu
//sizeof dzia�a na etapie kompillacji



	system("PAUSE");	
	return 0;
}
