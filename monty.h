#ifndef MONTY_H
#define MONTY_H

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <ctype.h>
#include <stdbool.h>
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
} my_stack_t;

/**
 * struct instruction_s - opcode and its function
 * @f: function to handle the opcode
 * @opcode: the opcode
 *
 * Description: opcode and its function for
 * stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(my_stack_t **stack, unsigned int line_number);
} instruction_t;

extern my_stack_t *temp;
extern int data;

char *split_string(char *str, const char *delim);
void add(my_stack_t **stack, unsigned int line_number);
void sub(my_stack_t **stack, unsigned int line_number);
void mod(my_stack_t **stack, unsigned int line_number);
void pall(my_stack_t **stack, unsigned int line_number);
void divide(my_stack_t **stack, unsigned int line_number);
void mul(my_stack_t **stack, unsigned int line_number);
void pint(my_stack_t **stack, unsigned int line_number);
void pop(my_stack_t **stack, unsigned int line_number);
int parser(char **trimmed_line, unsigned int *count, my_stack_t **stack);
char *trim_whitespace(char *str);
ssize_t getlines(char **lineptr, size_t *n, FILE *stream);
int read_file(char *filename, my_stack_t **stack);
void push(my_stack_t **head, unsigned int line_number, char *data);
void nop(my_stack_t **head, unsigned int line_number);
void swap(my_stack_t **stack, unsigned int line_number);
void free_stack(my_stack_t **stack);
void pchar(my_stack_t **head, unsigned int line_number);
void pstr(my_stack_t **stack, unsigned int line_number);
bool isinteger(const char *str);

#endif
