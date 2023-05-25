#include "monty.h"

/**
 * my_isascii - checks for isascii
 * @c: character
 *
 * Return: nothing
 */

int my_isascii(int c)
{
	return (c >= 0 && c <= 127);
}
