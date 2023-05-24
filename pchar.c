i#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"

/**
 * pchar - prints the int at the top of the stack as char
 * @custom_stack: stack given by the main file
 * @line_count: total no of lines
 *
 * Return: void
 */
void pchar(stack_t **custom_stack, unsigned int line_count)
{
	if (!custom_stack || !(*custom_stack))
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_count);
		exit(EXIT_FAILURE);
		return;
	}
	if (isascii((*custom_stack)->n) == 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_count);
		exit(EXIT_FAILURE);
		return;
	}
	printf("%c\n", (*custom_stack)->n);
}

