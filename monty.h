#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

extern int mode;

/* CORE */
void push(stack_t **stack, unsigned int line);
void pall(stack_t **stack, unsigned int line);
void pint(stack_t **stack, unsigned int line);
void pop(stack_t **stack, unsigned int line);
void swap(stack_t **stack, unsigned int line);
void add(stack_t **stack, unsigned int line);
void nop(stack_t **stack, unsigned int line);

/* ADVANCED */
void pchar(stack_t **stack, unsigned int line);
void pstr(stack_t **stack, unsigned int line);
void rotl(stack_t **stack, unsigned int line);
void rotr(stack_t **stack, unsigned int line);

/* MODE */
void _stack(stack_t **stack, unsigned int line);
void _queue(stack_t **stack, unsigned int line);

#endif
