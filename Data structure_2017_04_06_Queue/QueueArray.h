#pragma once

#define Q_size 10
#define boolean unsigned char
#define true 1
#define false 0

typedef char Element;

Element QueueArray[Q_size];

int rear = -1;
int front = -1;


void AddQ(char item);
Element deleteQ();
void Q_isFull();
void Q_isEmpty();
void Queue_show();

