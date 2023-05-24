#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"

/**
 * mod - calculates the remainder of the division
 * @custom_stack: stack given by main file
 * @line_count: the total no of files
 *
 * Return: void
 */
void mod(stack_t **custom_stack, unsigned int line_count)
{
	int results;

	if (!custom_stack || !*custom_stack || !((*custom_stack)->next))
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_count);
		exit(EXIT_FAILURE);
		return;
	}
	if (((*custom_stack)->n) == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_count);
		exit(EXIT_FAILURE);
		return;
	}

	results = ((*custom_stack)->next->n) % ((*custom_stack)->n);
	pop(stack, line_count);/*remove top node*/
	(*custom_stack)->n = results;
}

