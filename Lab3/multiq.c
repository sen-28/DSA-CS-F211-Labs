/*multiq.c*/

#include"multiq.h"

// creates a list of num Queues, each of which is empty.
MultiQ createMQ(int num){
    MultiQ mq;
        mq.qarr = (Queue *)malloc(num * sizeof(Queue));
    
    for (int i = 0; i < num; i++)
    {
        mq.qarr[i] = newQ();
    }

    mq.size = num;
    return mq;
}

// adds t to the Queue corresponding to priority p in mq. Task includes a TaskID tid and a priority p.
MultiQ addMQ(MultiQ mq, Task t){
    
    //creating a new element corresponding to task
    Element new;
    new.data = t.tid;
    new.next = NULL;

    //Queue corresponding to priority p is located at p - 1 in mq; adding new to this queue
    mq.qarr[t.p - 1] = addQ(mq.qarr[t.p - 1], new);
    return mq;
}

// returns the front of the non-empty Queue in mq with the highest priority.
Task nextMQ(MultiQ mq){
    
    //all queues in mq are empty
    if (isEmptyMQ(mq)){
        Task nullTask;
        nullTask.tid = -1;
        nullTask.p = -1;
        return nullTask;
    }

    for (int i = (mq.size - 1); i >= 0; i--)
    {
        if (isEmptyQ(mq.qarr[i]))
        {
            continue;
        }
        
        //return type task; converting front of queue to task 
        Task taskP;
        taskP.p = (i + 1);
        taskP.tid = (((mq.qarr[i]).front) -> data);
        return taskP;
    }
}

// deletes the front of the non-empty Queue in mq with the highest priority; returns the modified MultiQ
MultiQ delNextMQ(MultiQ mq){
    for (int i = (mq.size - 1); i >= 0; i--)
    {
        if (isEmptyQ(mq.qarr[i]) == false)
        {
            mq.qarr[i] = delQ(mq.qarr[i]);
            return mq;
        }
        return mq;
    }
}

// tests whether all the Queues in mq are empty
bool isEmptyMQ(MultiQ mq){
    for (int i = 0; i < MAX; i++)
    {
        if (isEmptyQ(mq.qarr[i]) == false)
        {
            return false;
        }
    }
    return true;
}

// returns the total number of items in the MultiQ
int sizeMQ(MultiQ mq){
    int size = 0;
    for (int i = 0; i < MAX; i++)
    {
        size += lengthQ(mq.qarr[i]);
    }
    return size;
}

// returns the number of items in mq with the priority p.
int sizeMQbyPriority(MultiQ mq, Priority p){
    return lengthQ(mq.qarr[p - 1]);
}

// returns the Queue with priority p.
Queue getQueueFromMQ(MultiQ mq, Priority p){
    return mq.qarr[p - 1];
}


