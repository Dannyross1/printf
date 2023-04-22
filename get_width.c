#include "main.h"

/**
 * get_width - Calculates the width for printing
 * @format: Formatted string in which to print the arguments.
 * @i: List of arguments to be printed.
 * @list: list of arguments.
 *
 * Return: width.
 */
int get_width(const char *format, int *i, va_list list)
{
	int rr_i;
	int width = 0;

	for (rr_i = *i + 1; format[rr_i] != '\0'; rr_i++)
	{
		if (is_digit(format[rr_i]))
		{
			width *= 10;
			width += format[rr_i] - '0';
		}
		else if (format[rr_i] == '*')
		{
			rr_i++;
			width = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*i = rr_i - 1;

	return (width);
}
