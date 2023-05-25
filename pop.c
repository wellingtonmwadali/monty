#include "monty.h"

/**
* pop - pops the top element of stack_t stack
* @custom_stack: stack
* @line_count: line number for error messages
*
* Return: void
*/
void pop(stack_t **custom_stack, unsigned int line_count)
{
	stack_t *tmp = NULL;

	if (!stack || !*custom_stack)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_count);
		exit(EXIT_FAILURE);
	}

	tmp = (*custom_stack)->next;
	free(*custom_stack);
	*custom_stack = tmp;
	if (!*custom_stack)
		return;
	(*custom_stack)->prev = NULL;
}
