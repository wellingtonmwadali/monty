#ifndef MONTY_H
#define MONTY_H

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define INSTRUCTIONS              \
	{                           \
		{"push", push},       \
		    {"pall", pall},   \
		    {"pint", pint},   \
		    {"pop", pop},     \
		    {"swap", swap},   \
		    {"nop", nop},     \
		    {"div", _div},    \
		    {"mul", _mul},    \
		    {"add", _add},    \
		    {"sub", _sub},    \
		    {"mod", mod},     \
		    {"pchar", pchar}, \
		    {"pstr", pstr},   \
		    {"rotl", rotl},   \
		    {"rotr", rotr},   \
		{                     \
			NULL, NULL      \
		}                     \
	}

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
* struct help - used for storing argument for the current opcode
* @data_struct: integer representing stack mode
* @argument: string storing arguments for opcodes
*
* Description: global structure that  passes data around the functions
*/
typedef struct help
{
	int data_struct;
	char *argument;
} help;
help global;

/* stack utility functions to manipulate the stack */
stack_t *add_node(stack_t **custom_stack, const int n);
stack_t *queue_node(stack_t **custom_stack, const int n);
void free_stack(stack_t *custom_stack);
size_t print_stack(const stack_t *custom_stack);

void push(stack_t **custom_stack, unsigned int line_count);
void pall(stack_t **custom_stack, unsigned int line_count);
void pint(stack_t **custom_stack, unsigned int line_count);
void swap(stack_t **custom_stack, unsigned int line_count);
void pop(stack_t **custom_stack, unsigned int line_count);
void nop(stack_t **custom_stack, unsigned int line_count);

void _div(stack_t **custom_stack, unsigned int line_count);
void _add(stack_t **custom_stack, unsigned int line_count);
void _sub(stack_t **custom_stack, unsigned int line_count);
void _mul(stack_t **custom_stack, unsigned int line_count);
void mod(stack_t **custom_stack, unsigned int line_count);

void pchar(stack_t **custom_stack, unsigned int line_count);
void pstr(stack_t **custom_stack, unsigned int line_count);
void rotl(stack_t **custom_stack, unsigned int line_count);
void rotr(stack_t **custom_stack, unsigned int line_count);

/*void opcode(stack_t **custom_stack, char *str, unsigned int line_count);*/

int is_digit(char *string);
int isnumber(char *str);
int my_isascii(int c);

#endif
