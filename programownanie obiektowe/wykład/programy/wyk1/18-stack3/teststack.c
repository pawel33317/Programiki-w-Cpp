#include <stdio.h>
#include "stack.h"

int main()
{
	struct stack_handle * s1=init();
	struct stack_handle * s2=init();
	push(s1,1);
	push(s1,2);
	push(s1,3);
	push(s2,5);
	push(s2,6);
	printf("%d %d\n",pop(s1),pop(s2));
	printf("%d\n",pop(s1));
	finalize(s1);
	finalize(s2);
	return 0;
}
