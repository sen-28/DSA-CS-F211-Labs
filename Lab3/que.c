/*que.c*/

#include "que.h"

// returns an empty Queue
Queue newQ(){
    Queue q;
    q.count = 0;
    q.front = NULL;
    q.rear = NULL;
    return q;
}

// tests whether q is empty
bool isEmptyQ(Queue q){
    if (q.count == 0)
    {
        return true;
    }
    return false;
}

// deletes the element from the front of the Queue; returns the modified Queue
Queue delQ(Queue q){

    //queue is empty
    if (isEmptyQ(q)){
        return q;
    }

    //queue contins single element; deletion generates empty queue
    else if (q.count == 1){
        q.front = NULL;
        q.rear = NULL;
        q.count = 0;
        return q;
    }

    //other cases
    q.front = q.front -> next;
    q.count --;
    return q;
}

// returns the element from the front of the Queue
Element front(Queue q){
    return *(q.front);
}

// adds e to the rear of the Queue; returns the modified Queue
Queue addQ(Queue q , Element e){
    Element *new = (Element *) malloc(sizeof(Element));
    new->data = e.data;
    new->next = e.next;

    if (isEmptyQ(q)){
        q.front = q.rear = new;
    }
    else {
    (q.rear)->next = new;
    q.rear = new;
    }

    q.count ++;
    return q;   
}

// returns the length of the Queue
int lengthQ(Queue q){
    return q.count;
} 








