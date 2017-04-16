#pragma once
#define boolean unsigned char
#define true 1
#define false 0
typedef int Element;
// Global queue
typedef struct stack *stack_pointer;
typedef struct stack
{
	Element item;
	stack_pointer link;
} stack;
stack_pointer top;
void push(Element e);
Element pop();
void stack_show();
boolean is_stack_empty();


int eval_postfix(char *exp);
boolean is_number(char c);
boolean is_op(char c);