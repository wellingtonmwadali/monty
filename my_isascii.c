#include "monty.h"

/**
 * my_isascii - checks ASCII chars
 * @c: char
 *
 * Return: nothing
 */

int my_isascii(int c)
{
	return (c >= 0 && c <= 127);
}
