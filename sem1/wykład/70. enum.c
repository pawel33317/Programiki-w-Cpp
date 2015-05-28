#include <stdio.h>
#include <stdlib.h>
enum Days
{
	saturday,//0
	sunday=0,//0
	monday,//1
	tuestay,//2
	wednesday,//3
	thursday,//4
	friday//5
}today;
int main()
{	
	enum Days yesterday;enum Days i;
	yesterday=monday;
	printf("dzisiaj monday: %d\n",yesterday);
	i = tuestay;
	//yesterday=(Days)1;
	printf("jutro tuesday: %d\n",i);
	system("PAUSE");	
	return 0;
}
