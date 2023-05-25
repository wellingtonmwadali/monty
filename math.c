#include "monty.h"

/**
 * _add -  adds the first two integers in the stack
 * @custom_stack: stack
 * @line_count: number of lines
 *
 * Return: void
 */
void _add(stack_t **custom_stack, unsigned int line_count)
{
	int result;

	if (!custom_stack || !*custom_stack || !((*custom_stack)->next))
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_count);
		exit(EXIT_FAILURE);
	}

	result = ((*custom_stack)->next->n) + ((*custom_stack)->n);
	pop(custom_stack, line_count);
	(*custom_stack)->n = result;
}

/**
 * _sub -  substracts the first two ints in the stack
 * @custom_stack: stack
 * @line_count: number of lines
 *
 * Return: void
 */
void _sub(stack_t **custom_stack, unsigned int line_count)
{
	int result;

	if (!stack || !*custom_stack || !((*custom_stack)->next))
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_count);
		exit(EXIT_FAILURE);
	}

	result = ((*custom_stack)->next->n) - ((*custom_stack)->n);
	pop(custom_stack, line_count);
	(*custom_stack)->n = result;
}

/**
 * _mul - multiplies the next value by the top value
 * @custom_stack: stack
 * @line_count: number of lines
 *
 * Return: void
 */
void _mul(stack_t **custom_stack, unsigned int line_count)
{
	int result;

	if (!stack || !*custom_stack || !((*custom_stack)->next))
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_count);
		exit(EXIT_FAILURE);
		return;
	}

	result = ((*custom_stack)->next->n) * ((*custom_stack)->n);
	pop(custom_stack, line_count);
	(*custom_stack)->n = result;
}

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
