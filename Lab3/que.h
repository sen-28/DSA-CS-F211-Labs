/*que.h*/

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct Element {
    int data;
    struct Element * next;
} Element;

typedef struct Queue {
    int count;
    Element * front;
    Element * rear;
} Queue;

Queue newQ(); // returns an empty Queue

bool isEmptyQ(Queue q); // tests whether q is empty

Queue delQ(Queue q); // deletes the element from the front of the Queue; returns the modified Queue

Element front(Queue q); // returns the element from the front of the Queue

Queue addQ(Queue q , Element e); // adds e to the rear of the Queue; returns the modified Queue

int lengthQ(Queue q); // returns the length of the Queue