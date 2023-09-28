#include "monty.h"

/**
 * pop - function that eliminates the start element of the stack
 * @stack: Pointer to the start of the stack
 * @line_number: The current line number
 *
 */

void pop(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	else
	{
		stack_t *temp = *stack;
		*stack = (*stack)->next;
		if (*stack)
		{
			(*stack)->prev = NULL;
		}
		free(temp);
	}
}
