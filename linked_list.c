#include <stdio.h>
#include <stdlib.h>
#include "monty.h"

/**
 * queue_node - adds  node to stack_t in queue_node
 * @custom_stack: the stack head
 * @n: number of the node
 *
 * Return: newly created node or NULL if memory allocation fails
 */

stack_t *queue_node(stack_t **custom_stack, const int n)
{
	stack_t *new = malloc(sizeof(stack_t));
	stack_t *current = *stack;

	if (!new)
	{
		free(new);
		return (NULL);
	}
	new->n = n;

	if (!*custom_stack)
	{
		new->next = NULL;
		new->prev = NULL;
		*custom_stack = new;
		return (new);
	}

	while (current)
	{
		if (!current->next)
		{
			new->next = NULL;
			new->prev = current;
			current->next = new;
			break;
		}
		current = current->next;
	}

	return (new);
}

/**
 * add_node - adds  node to start of  stack_t stack
 * @custom_stack: the stack head
 * @n: number of the new node
 *
 * Return: newly created node,or NULL if creation fails
 */

stack_t *add_node(stack_t **custom_stack, const int n)
{
	stack_t *new = malloc(sizeof(stack_t));

	if (!new)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free(new);
		return (NULL);
	}
	new->n = n;

	new->next = *custom_stack;
	new->prev = NULL;
	if (*custom_stack)
		(*custom_stack)->prev = new;

	*custom_stack = new;

	return (new);
}

/**
 * print_stack - prints the contents of a stack_t stack
 * @custom_stack: the stack head
 *
 * Return: number of elements
 */
size_t print_stack(const stack_t *custom_stack)
{
	size_t c = 0;

	while (custom_stack)
	{
		printf("%d\n", custom_stack->n);
		custom_stack = custom_stack->next;
		c++;
	}

	return (c);
}

/**
 * free_stack - frees  dlistint_t linked list
 * @custom_stack: the list head
 *
 * Return: nothing
 */
void free_stack(stack_t *custom_stack)
{
	stack_t *current = custom_stack;
	stack_t *next;

	if (custom_stack)
	{
		next = custom_stack->next;
		while (current)
		{
			free(current);
			current = next;
			if (next)
				next = next->next;
		}
	}
}
