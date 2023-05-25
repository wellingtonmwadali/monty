#include "monty.h"

/**
 * swap -  swaps data from top to previous pos
 * @custom_stack: stack given by header in main file
 * @line_count: the number of lines
 *
 * Return: void
 */
void swap(stack_t **custom_stack, unsigned int line_count)
{
	stack_t *tmp = NULL;
	int tmp_n = 0;

	if (!custom_stack || !*custom_stack || !((*custom_stack)->next))
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_count);
		exit(EXIT_FAILURE);
	}
	tmp = *custom_stack;
	tmp_n = tmp->n;
	tmp->n = tmp_n;

	tmp->n = tmp->next->n;
	tmp->next->n = tmp_n;
}
