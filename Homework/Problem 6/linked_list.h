#pragma once

#define Element int
#define bool unsigned char
#define true 1
#define false 0

typedef struct list_node* list_pointer;

typedef struct list_node
{
	Element data;
	list_pointer link;
} list_node;




void list_insert(list_pointer head, Element e);
void list_delete(list_pointer head, Element e);
list_pointer list_search(list_pointer head, Element e);
bool list_empty(list_pointer head);
void list_show(list_pointer head);
//list_pointer merge(list_pointer head1, list_pointer head2);
//void SwapNode(list_pointer* destRef, list_pointer* sourceRef);
list_pointer merge_sort(list_pointer head);
list_pointer getMiddle(list_pointer head);
list_pointer merge(list_pointer a, list_pointer b);
