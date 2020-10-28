


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "proj4.h"


void addToList(NODE * cur, int burger, int salad, char* customerName, char* status){
    
    Group *newNode = (Group*)malloc(sizeof(Group));// making new node of size struct 
    newNode->CustomerName = customerName;         // de-referencing CustomerName to customerName
    newNode->NumOfBurgers = burger;               
    newNode->NumOfSalads = salad;
    newNode->Status = *status;
    
    // when the node is empty
    if (cur->Front == NULL){
        cur->Front = newNode;
        (cur->Front)->Next = NULL;
    }
    
    // else add to the queue
    else{
        Group * temp = cur->Front;
        while (temp->Next != NULL) {
            temp = temp->Next;
        }
        temp->Next = newNode;
        (temp->Next)->Next = NULL;
    }
    cur->numberOfCustomer++;
}
// function to update the status of the customer 
int updateStatus(NODE *cur, char* name){
    
    Group * temp = cur->Front;
    while (temp != NULL)
    {
        if (debugMode == 1)
            printf("DEBUG: Customer %s with %d burger and %d salad status %s", temp->CustomerName, temp->NumOfBurgers, temp->NumOfSalads, (temp->Status == 'w')?"waiting.\n":"callahead.\n");
        if (strcmp(temp->CustomerName, name) == 0)
        {
            if (temp->Status == 'c')
            {
                temp->Status = 'w';
                return TRUE;
            }
            else
                return FALSE;
        }
        temp = temp->Next;
    }
   
    return TRUE;
}
int doesNameExist(NODE * cur, char* name){
    
    Group * temp =  cur->Front;
    
    if(temp == NULL){
        return 0;
    }
    
    while (temp != NULL){
        if (strcmp(temp->CustomerName, name) == 0){
            return 1;
        }
        temp = temp->Next;
    }
    return 0;
}


int countOrdersAhead(NODE* cur, char* name){
    int aheadOfCurrent = 0;
    Group * temp = cur->Front;
    while (temp != NULL){
        if (strcmp(temp->CustomerName, name) == 0){
            return aheadOfCurrent;
        }
        aheadOfCurrent++;
        temp = temp->Next;
    }
    return aheadOfCurrent;
}

// Retrieve and remove the first orderon the orderlist that is waiting
//  in the restaurant and contains less than or equal to number of prepared burgers and salads.
char * retrieveAndRemove(NODE * cur, int burger, int salad){
    char * Custname = NULL;
    Group *ptemp = cur->Front;
	Group *previous = NULL;
    
    while(ptemp != NULL)
    {
        if (debugMode){
            if(ptemp->Status == 'w'){
                printf("Customer %s is waiting.\n", ptemp->CustomerName);
				printf("Customer order is % d burgers and % d salads.\n", ptemp->NumOfBurgers,ptemp->NumOfSalads);
			}
            
            if(ptemp->Status == 'c'){
                printf("Customer %s has called ahead.\n", ptemp->CustomerName);
				printf("Customer order is % d burgers and % d salads.\n", ptemp->NumOfBurgers,ptemp->NumOfSalads);
			}
        }
        
       if ((ptemp->NumOfBurgers <= burger && ptemp->NumOfSalads <= salad) && ptemp->Status == 'w')
       {
           Custname = ptemp->CustomerName;  
           if (cur->Front == ptemp){
              cur->Front = ptemp->Next;
               ptemp->Next = NULL;
               free(ptemp);
           }
           else{
               previous->Next = ptemp->Next;
               free(ptemp);  // freeing
           }
           cur->numberOfCustomer--;
           break;
       }
     
       previous = ptemp;
       ptemp = ptemp->Next;
		
    }
    return Custname;
}

// function to display waiting time for the customer 
int displayWaitingTime(NODE* cur, char* name) {
    
    int minutes = 0;
    int totalProdcuts = 0;
    Group * temp = cur->Front;
    while (temp != NULL) {
        if (strcmp(temp->CustomerName, name) == 0) {
            minutes =  (temp->NumOfBurgers * 10) + (temp->NumOfSalads * 5);  // count to minutes of wait Time
            return minutes;
        }
        temp = temp->Next;
    }
    return minutes;
}
// to display customer status info
void displayListInformation(NODE* cur)
{
    int counter = 0;
	Group * ptemp = cur->Front;
    
    while (ptemp != NULL)
    {
        counter++;
        printf("%d. ", counter);
        if(ptemp->Status == 'w'){
			 printf("Customer %s is waiting.\n", ptemp->CustomerName);
            printf("Customer order is  %d burgers and %d salads.\n", ptemp->NumOfBurgers, ptemp->NumOfSalads);
        }
        
        if(ptemp->Status == 'c'){
			printf("Customer %s has called ahead.\n", ptemp->CustomerName);
            printf("Customer order is %d burgers and %d.\n", ptemp->NumOfBurgers, ptemp->NumOfSalads);
        }
        
        ptemp = ptemp->Next;
    }
}
// for printing order ahead of customer 
void displayOrdersAhead(NODE* cur, char * name){
    Group * ptemp = cur->Front;
    while (ptemp != NULL){
        
        if (debugMode){
            if(ptemp->Status == 'w'){
		 printf("Customer %s has called ahead.\n", ptemp->CustomerName);
		 printf("Customer order is %d burgers and %d .\n", ptemp->NumOfBurgers, ptemp->NumOfSalads);
				
            }
            
            if(ptemp->Status == 'c'){
                printf("Customer %s has %d burgers and %d salads status they called ahead.\n", ptemp->CustomerName, ptemp->NumOfBurgers, ptemp->NumOfSalads);
            }
        }
        
        if (strcmp(ptemp->CustomerName, name) == 0){  // comparing the string
            break;
        }
        
        printf("Customer %s is waiting ahead with order of %d burger and %d salad.\n", ptemp->CustomerName, ptemp->NumOfBurgers, ptemp->NumOfSalads);
        ptemp = ptemp->Next;
    }
}


