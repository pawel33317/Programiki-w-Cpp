#include <stdio.h>
#include "stack.h"

int main()
{
        init();
	push(1);
	push(2);
	push(3);
	printf("%d %d\n",pop(),pop());
	printf("%d\n",pop());
	finalize();
	return 0;
}
