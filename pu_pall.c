#include "monty.h"

/**
 * push - push element into the top of the stack
 * @custom_stack: stack to push to
 * @line_count: number of lines
 *
 * Return: void
 */
void push(stack_t **custom_stack, unsigned int line_count)
{
	char *n = global.argument;

	if ((is_digit(n)) == 0)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_count);
		exit(EXIT_FAILURE);
	}

	if (global.data_struct == 1)
	{
		if (!add_node(custom_stack, atoi(global.argument)))
		{
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		if (!queue_node(custom_stack, atoi(global.argument)))
		{
			exit(EXIT_FAILURE);
		}
	}
}

/**
 * pall - prints the stacks present
 * @custom_stack: stack
 * @line_cnt: number of lines
 *
 * Return: void
 */
void pall(stack_t **custom_stack,
		unsigned int line_cnt __attribute__((unused)))
{
	print_stack(*custom_stack);
}
