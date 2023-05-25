#include "./monty.h"

/**
 * opcode - manage builtins
 * @custom_stack: stack
 * @str: string
 * @line_count: number of lines
 *
 * Return: nothing
 */
void opcode(stack_t **custom_stack, char *str, unsigned int line_count)
{
	int j = 0;

	instruction_t op[] = INSTRUCTIONS;

	if (!strcmp(str, "stack"))
	{
		global.data_struct = 1;
		return;
	}
	if (!strcmp(str, "queue"))
	{
		global.data_struct = 0;
		return;
	}

	while (op[j].opcode)
	{
		if (strcmp(op[j].opcode, str) == 0)
		{
			op[j].f(custom_stack, line_count);
			return;
		}
		j++;
	}
	fprintf(stderr, "L%d: unknown instruction %s\n", line_count, str);
	exit(EXIT_FAILURE);
}
