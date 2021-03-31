#include <stdio.h>
#include <stdlib.h>
#include "cycle.h"

// Hare - Tortoise algorithm 
// returns 1 if a cycle is present and 0 if it is not present

int testCyclic (struct linkedList * Ls){
    if (Ls -> count < 2)
    {
        if ((Ls -> first) -> next == Ls -> first)
        {
            return 1;
        }
        return 0;
    }
		
    struct node * hare, *tort;
	tort = Ls-> first;
	hare = Ls-> first;

	while(hare!=tort || hare!=NULL)
    {
		if(tort->next == NULL || (hare->next == NULL) || (hare -> next) -> next == NULL)
        {
			return 0;	
		}
		tort = tort -> next;
		hare = (hare -> next) -> next;
			
		if(hare == tort && hare!=NULL && tort!=NULL)
        {
		    return 1; // cycle found
		}
	}
    
	printf("Fallback");
	return 0;
}



