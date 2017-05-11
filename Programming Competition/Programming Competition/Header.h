#pragma once

#define boolean unsigned char
#define true 1
#define false 0

#define MAX_SIZE 100

typedef unsigned int Element;

Element Stack[MAX_SIZE];

int top = -1;

boolean stack_full();
boolean stack_empty();

void push(Element e);

Element result();

boolean is_operand(char c);

boolean is_operator(char c);
