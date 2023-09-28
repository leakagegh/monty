#ifndef MONTY_H
#define MONTY_H
#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <fcntl.h>
#include <unistd.h>

/**
 * struct stack_s - Represents a doubly linked list node structure
 *for a stack (or queue)
 * @n: integer data
 * @prev: Points to the previous element of the stack (or queue)
 * @next: Points to the next element of the stack (or queue)
 *
 * Description: This structure defines a node for a doubly linked list
 *which can be used
 *for implementing both stack (LIFO) and queue (FIFO) data structures
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - Represents an opcode and its corresponding function
 * @opcode: the opcode
 * @f: The function to handle the opcode
 * Description: This structure associates an opcode with its respective funct
 *for stack and queue operations, implementing both LIFO and FIFO behaviors
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;


void push(stack_t **stack, int value, unsigned int line_number);
int check_if_numeric(const char *str);
void pall(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);
void add(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);


#endif /*MONTY_H*/
