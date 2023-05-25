#include <stdio.h>
#include "monty.h"

void file_error(char *argv);
void error_usage(void);
int status = 0;

/**
 * main - entry point
 * @argv: list of arguments passed to our program
 * @argc: number of args
 *
 * Return: nothing
 */
int main(int argc, char **argv)
{
	FILE *file;
	size_t buf_len = 0;
	char *buffer = NULL;
	char *str = NULL;
	stack_t *custom_stack = NULL;
	unsigned int line_count = 1;

	global.data_struct = 1;
	if (argc != 2)
		error_usage();
	file = fopen(argv[1], "r");

	if (!file)
		file_error(argv[1]);

	while (1)
	{
		buffer = (char *)malloc(buf_len);
		if (!buffer)
		{
			fprintf(stderr, "Memory allocation failed\n");
			exit(EXIT_FAILURE);
		}
		if (fgets(buffer, buf_len, file) == NULL)
		{
			free(buffer);
			break;
		}
		if (status)
			break;
		if (*buffer == '\n')
		{
			line_count++;
			continue;
		}
		str = strtok(buffer, " \t\n");
		if (!str || *str == '#')
		{
			line_count++;
			continue;
		}
		global.argument = strtok(NULL, " \t\n");
		opcode(&custom_stack, str, line_count);
		line_count++;
	}
	free(buffer);
	free_stack(custom_stack);
	fclose(file);
	exit(EXIT_SUCCESS);
}

/**
 * file_error - file error message and exits
 * @argv: arguments passed to program
 *
 * Desc: print message if  not possible to open the file
 * Return: nothing
 */
void file_error(char *argv)
{
	fprintf(stderr, "Error: Can't open file %s\n", argv);
	exit(EXIT_FAILURE);
}

/**
 * error_usage - prints usage message and exits
 *
 * Desc: if user does not give any file or more than
 * one argument to your program
 *
 * Return: nothing
 */
void error_usage(void)
{
	fprintf(stderr, "USAGE: monty file\n");
	exit(EXIT_FAILURE);
}
