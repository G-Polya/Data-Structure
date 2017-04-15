#pragma once

#define boolean unsigned char
#define true 1
#define false
typedef char Element;

typedef struct stack* stack_pointer;
typedef struct stack
{
	Element item;
	stack_pointer link;
} stack;

stack_pointer top;
stack_pointer head;

void push(Element e);
Element pop();
void stack_show();
boolean is_stack_full();
boolean is_stack_empty();