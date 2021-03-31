#include <stdio.h>
#include "cycle.h"
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>

size_t space;
void * myalloc (size_t size);
void myfree (void * ptr, size_t size);
struct linkedList * createList(int N);
struct linkedList * createCycle(struct linkedList * Ls);

int main()
{
    struct timeval t1, t2;
	double elapsedTime;
    // start timer
    gettimeofday(&t1, NULL);
	srand(time(NULL));
    int n = 1000000 + rand();
    struct linkedList * l = createList(n);
    l = createCycle(l);
    printf("%d\n", testCyclic(l));
    // stop timer
    gettimeofday(&t2, NULL);
    // compute and print the elapsed time in millisec
    elapsedTime = (t2.tv_sec - t1.tv_sec) * 1000.0;
    elapsedTime += (t2.tv_usec - t1.tv_usec) / 1000.0;
    // printf("Total time: %lf ms.\n", elapsedTime);

    FILE *fptr = fopen("res.txt", "a");
    fprintf(fptr, "%d,%lf,%zu\n", n, elapsedTime, space);
    fclose(fptr);
    return 0;
}

void * myalloc (size_t size){
    // printf("Space before allocation: %zu\n", space);
    void * temp = malloc(size);
    space += size;
    // printf("Space after allocation: %zu\n", space);
    return temp;
}

void myfree (void * ptr, size_t size){
    // printf("Space before freeing: %zu\n", space);
    free (ptr);
    space -= size;
    // printf("Space after freeing: %zu\n", space);
}

struct linkedList * createList(int N){

    // allocating memory to list
    struct linkedList * Ls = (struct linkedList *)myalloc(sizeof(struct linkedList));
    struct node * f = (struct node *)myalloc(sizeof(struct node));
    f = NULL;
    // checking if allocation successful
   /* if (Ls = NULL)
    {
        printf("Memory alloaction was unsuccessful. List could not be created.\n");
    }
    */
    // initialsing list
    Ls -> count = 0;
    Ls -> first = f;

    // adding N random numbers to the list
    for (int i = 0; i < N; i++)
    {      
        struct node *link = (struct node*) myalloc (sizeof(struct node));
       /* if (link == NULL)
        {
            printf("Memory alloaction was unsuccessful. Node could not be created.\n");
            break;
        }        
        */
        link->element = rand();
	    link->next = NULL;
        //point it to old first node
        link -> next = Ls -> first;

        //point first to new first node
        Ls -> first = link;
        Ls -> count ++;
    }
    return Ls;
}

struct linkedList * createCycle(struct linkedList * Ls){
    if(Ls -> count < 2 || Ls == NULL)
    {
	    printf("Empty LinkedList or LinkedList with 1 element received.");
	    return NULL;
	}

    int toss = rand() % 2;
    if (toss == 0)
    {
        // printf("Toss: %d. Ls must be Cyclic.\n", toss);

        int r = rand() % (Ls -> count);
        struct node * temp = Ls -> first;
        struct node *newHead = NULL;

        while (temp -> next != NULL){
            if (r == 0)
            {
                newHead = temp;
                break;
            }

            temp = temp -> next;
            if (--r == 0)
            {
                newHead = temp;
                break;
            }
        }
        temp -> next = newHead;
    }
    else{
        // printf("Toss: %d. Ls must be Linear.\n", toss);
    }
    return Ls;
}


