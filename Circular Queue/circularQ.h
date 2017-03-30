#pragma once

#define Q_size 8
#define boolean unsigned char
#define true 1
#define false 0
char QueueArray[Q_size];

void AddQ(char item);
char DeleteQ();
void Q_isFull();
void Q_isEmpty();
void Queue_show();

int rear = -1;
int front = -1;
