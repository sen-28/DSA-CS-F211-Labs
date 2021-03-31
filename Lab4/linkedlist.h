#include <stdio.h>

// structure of a linked list node. It contains an element
struct node {
int element;
struct node * next;
};

/* structure of a linked list / head. It stores the count of number of elements
in the list and also a pointer link to the first node of the list. */
struct linkedList {
int count;
struct node * first;
};