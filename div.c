u#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"

/**
 * _div - divide  next top value by the top value
 * @custom_stack: stack given by main function
 * @line_count: the total number of lines
 *
 * Return: void
 */
void _div(stack_t **custom_stack, unsigned int line_count)
{
	int results;

	if (!custom_stack || !*custom_stack || !((*custom_stack)->next))
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_count);
		exit(EXIT_FAILURE);
	}
	if (((*custom_stack)->n) == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_count);
		exit(EXIT_FAILURE);
		;
		return;
	}

	results = ((*custom_stack)->next->n) / ((*custom_stack)->n);
	pop(custom_stack, line_count);/*remove top node*/
	(*custom_stack)->n = results;
}

