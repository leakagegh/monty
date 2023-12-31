#include "monty.h"

/**
 * pint - function that displays the value at the start of the stack
 * @stack: The pointer to the start of the stack
 * @line_number: The line numer where pint the 'pint' opcode is encountered
 */

void pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	else
	{
		printf("%d\n", (*stack)->n);
	}
}
