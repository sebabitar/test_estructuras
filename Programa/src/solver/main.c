#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "stack.h"


int main()
{
	Stack *stack = stack_init();
	/* Esta linea indica que el programa termino sin errores*/
	push(stack, 1);
	push(stack, 4);

	printf("%d\n", stack->first->color);
	printf("%d\n", stack->first->next->color);

	int a = pop(stack);

	printf("%d\n", a);
	printf("%d\n", stack->size);

	int b = pop(stack);

	printf("%d\n", b);

	free(stack);

	return 0;
}
