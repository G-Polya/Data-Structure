#pragma once
#define MAX_SIZE 10
#define boolean unsigned char
#define true 1
#define false 0
typedef char Element;
// Global stack
Element stack[MAX_SIZE];				//stackarray
int top = -1;		
void stack_full();
void stack_empty();
void push(Element e);
Element pop();
void stack_show();
