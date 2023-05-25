#include "monty.h"

/**
 * pstr - prints the contents of a stack_t as a string
 * @custom_stack: stack
 * @line_count: number of lines
 *
 * Return: nothing
 */
void pstr(stack_t **custom_stack, unsigned int
		line_count __attribute__((unused)))
{
	stack_t *current = *custom_stack;

	while (current)
	{
		if (current->n <= 0 || current->n > 127)
			break;
		putchar((char) current->n);
		current = current->next;
	}
	putchar('\n');
}
