

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "proj4.h"
void doAdd(NODE* Curr)
{
    /* get number of burgers ordered from input. */
    int NumBurgers = getPosInt();
    if (NumBurgers < 0)
    {
        printf("Error: Add command requires an integer value of at least 0\n");
        printf("Add command is of form: a <# burgers> <# salads> <name>\n");
        printf("  where:<# burgers> is the number of ordered burgers\n");
        printf("        <# salads> is the number of ordered salads\n");
        printf("        <name> is the name of the person putting the order\n");
        return;
    }
    
    /* get number of salads ordered from input. */
    int NumSalads = getPosInt();
    if (NumSalads < 0) 
    {
        printf("Error: Add command requires an integer value of at least 0\n");
        printf("Add command is of form: a <# burgers> <# salads> <name>\n");
        printf("  where:<# burgers> is the number of ordered burgers\n");
        printf("        <# salads> is the number of ordered salads\n");
        printf("        <name> is the name of the person putting the order\n");
        return;
    }
    
    /* get group name from input */
    char *custName = getName();
    if (NULL == custName)
    {
        printf("Error: Add command requires a name to be given\n");
        printf("Add command is of form: a <# burgers> <# salads> <name>\n");
        printf("  where:<# burgers> is the number of ordered burgers\n");
        printf("        <# salads> is the number of ordered salads\n");
        printf("        <name> is the name of the person putting the order\n");
        return;
    } 
    if(debugMode)
	{
		printf("Calling add to list function to add customer to waiting list.\n ");
	}
    printf("Adding In-restaurant order for \"%s\": %d burgers and %d salads\n", custName, NumBurgers, NumSalads);
	
    addToList(Curr , NumBurgers, NumSalads, custName, "w"); // calling function to add customer to the waiting list
	
}

void doCallAhead(NODE* Curr)
{
    // get number of burgers ordered from input.
    int NumBurgers = getPosInt();
    if (NumBurgers < 0)
    {
        printf("Error: Call-ahead command requires an integer value of at least 0\n");
        printf("Call-ahead command is of form: c <# burgers> <# salads> <name>\n");
        printf("  where:<# burgers> is the number of ordered burgers\n");
        printf("        <# salads> is the number of ordered salads\n");
        printf("        <name> is the name of the person putting the order\n");
        return;
    }
    
    // get number of salads ordered from input.
    int NumSalads = getPosInt();
    if (NumSalads < 0)
    {
        printf("Error: Call-ahead command requires an integer value of at least 0\n");
        printf("Call-ahead command is of form: c <# burgers> <# salads> <name>\n");
        printf("  where:<# burgers> is the number of ordered burgers\n");
        printf("        <# salads> is the number of ordered salads\n");
        printf("        <name> is the name of the person putting the order\n");
        return;
    }
    
    // get group name from input.
    char * custName = getName();
    if (NULL == custName)
    {
        printf("Error: Call-ahead command requires a name to be given\n");
        printf("Call-ahead command is of form: c <# burgers> <# salads> <name>\n");
        printf("  where:<# burgers> is the number of ordered burgers\n");
        printf("        <# salads> is the number of ordered salads\n");
        printf("        <name> is the name of the person putting the order\n");
        return;
    }
    
    printf("Adding Call-ahead order for \"%s\": %d burgers and %d salads\n", custName, NumBurgers, NumSalads);
    
    addToList(Curr , NumBurgers, NumSalads,custName, "c"); // calling addtolist to add customer for call ahead
}
//function for adding customer to waiting list
void doWaiting(NODE * Curr )
{
    // get group name from input.
    char *custName = getName();
    if (NULL == custName)
    {
        printf ("Error: Waiting command requires a name to be given\n");
        printf ("Waiting command is of form: w <name>\n");
        printf ("  where: <name> is the name of the group that is now waiting\n");
        return;
    }
    
    if (doesNameExist(Curr , custName) == FALSE)
    {
        printf("%s is not in line.\n", custName);
        return;
    } 
    
    if (updateStatus(Curr , custName) == FALSE)
        printf("%s is already waiting.\n", custName);
    else
        printf ("Call ahead customer \"%s\" is  waiting in the restaurant\n", custName);
}

void doRetrieve(NODE * Curr )
{
    // get info of prepared food ready on the counter from input.
    int BurgersReady = getPosInt();
    if (BurgersReady < 0)
    {
        printf("Error: Retrieve command requires an integer value of at least 0\n");
        printf("Retrieve command is of form: r <# burgers> <# salads>\n");
        printf("  where: <# burgers> is the number of burgers waiting on the counter for pick up\n");
        printf("         <# saladss> is the number of salads waiting on the counter for pick up\n");
        return;
    }
    
    int SaladsReady = getPosInt();
    if (SaladsReady < 0)
    {
        printf("Error: Retrieve command requires an integer value of at least 0\n");
        printf("Retrieve command is of form: r <# burgers> <# salads>\n");
        printf("  where: <# burgers> is the number of burgers waiting on the counter for pick up\n");
        printf("         <# saladss> is the number of salads waiting on the counter for pick up\n");
        return;
    }
    
    clearToEoln();
    printf("Retrieve (and remove) the first customer that can pick up the order of %d burgers and %d salads\n", BurgersReady, SaladsReady);
    if(debugMode)
	{
		printf("Calling retrieveAndRemove to Retrieve and remove the first order on the orderlist that is waiting");
	}
    char* customerName = retrieveAndRemove(Curr , BurgersReady,SaladsReady);
    if (customerName == NULL) 
        printf("No customer found for this order.\n");
    else
        printf("Customer %s was served the food. \n", customerName);
}

void doList(NODE * Curr )
{
    // get group name from input.
    char *custName = getName(); // getting custname from get name.
    if (NULL == custName)
    {
        printf ("Error: List command requires a name to be given\n");
        printf ("List command is of form: l <name>\n");
        printf ("  where: <name> is the name of the group to inquire about\n");
        return;
    }
    
    if (doesNameExist(Curr , custName) == FALSE)
    {
        printf("The specified customer does not exist.\n");
        return;
    }
    
    printf ("Order for \"%s\" is behind the %d orders\n", custName, countOrdersAhead(Curr , custName));
    if(debugMode)
	{ 
		printf("Calling displayOrdersAhead function to display order ahead of the customer.\n ");
	}
    // add code to perform this operation here
    displayOrdersAhead(Curr , custName);
}
void doEstimateTime(NODE* Curr){
    
    // get order name from input.
    int time =  0;
    char *custName = getName();
    if (NULL == custName){
        printf("Error: List command requires a name to be given\n");
        printf("List command is of form: t <name>\n");
        printf("  where: <name> is the name of the order to inquire about\n");
        return;
    }
    
    // add code to perform this operation here
    if (doesNameExist(Curr , custName) == FALSE){
        printf("Customer not found in the order list \n");
        return;
    }
    
    
    time = displayWaitingTime(Curr , custName);
	if(debugMode)
	{
		printf("Calling displaywaiting to get wait time for the customer.\n");
	}
    
    printf("Waiting time for customer %s is %d minutes.\n", custName, time);
    
}


void doDisplay(NODE *Curr)
{
    clearToEoln();
    printf ("Display information about all orders\n");
    
    // add code to perform this operation here
    if(debugMode)
	{
		printf("calling display list information to display information about all orders.\n");
	}
    displayListInformation(Curr);
	
}

