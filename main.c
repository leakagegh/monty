#include "monty.h"

/**
 * main - The starting point for the Monty bytecode interpreter
 * @argc: The count of command-line arguments
 * @argv: An array of command-line argument strings ^
 * Return: Returns EXIT_SUCCESS on success, EXIT_FAILURE on failure
 */

int main(int argc, char *argv[])
{
	FILE *file;
	stack_t *stack = NULL;
	char *opcode, *argument, *line = NULL;
	size_t len = 0;
	unsigned int line_number = 0;


	if (argc != 2)
	{	fprintf(stderr, "Usage: %s monty file\n", argv[0]);
		return (EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	if (!file)
	{	fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		return (EXIT_FAILURE);
	}
	while (getline(&line, &len, file) != -1)
	{	line_number++;
		opcode = strtok(line, " \t\n");
		argument = strtok(NULL, " \t\n");
		if (opcode && strcmp(opcode, "push") == 0)
		{	push(&stack, atoi(argument), line_number); }
		else if (opcode && strcmp(opcode, "pall") == 0)
		{	pall(&stack, line_number); }
		else if (opcode && strcmp(opcode, "pint") == 0)
		{	pint(&stack, line_number); }
		else if (opcode && strcmp(opcode, "pop") == 0)
		{	pop(&stack, line_number); }
		else if (opcode && strcmp(opcode, "swap") == 0)
		{	swap(&stack, line_number); }
		else if (opcode && strcmp(opcode, "add") == 0)
		{	add(&stack, line_number); }
	}
	fclose(file);
	if (line)
		free(line);
	return (EXIT_SUCCESS);

}
