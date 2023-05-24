#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"

/**
 * pint - print the value at the top of stack
 * @custom_stack: stack given by main in the header file
 * @line_count: the number of lines
 *
 * Return: void
 */
void pint(stack_t **custom_stack, unsigned int line_count)
{
	if (!custom_stack || !(*custom_stack))
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_count);
		exit(EXIT_FAILURE);

	}
	printf("%d\n", (*custom_stack)->n);
}
