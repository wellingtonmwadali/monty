#include "monty.h"

/**
* rotl - rotates the first element of the stack to last
* @custom_stack: stack in the main file
* @line_count: totl no of lines
*
* Return: nothing
*/
void rotl(stack_t **custom_stack, unsigned int line_count)
{
	stack_t *left;
	stack_t *right;

	(void) line_count;
	if (!custom_stack || !*custom_stack || !(*custom_stack)->next)
		return;

	left = right = *custom_stack;

	while (right->next) /* move the right ptr to last node */
		right = right->next;
	right->next = left; /* circular  infinite linked list loop */
	left->prev = right;
	*custom_stack = left->next; /*cut the link between the 0 and 1 element */
	(*custom_stack)->prev->next = NULL;
	(*custom_stack)->prev = NULL;
}

