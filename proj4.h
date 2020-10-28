#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef enum {FALSE = 0, TRUE, NO = 0, YES} boolean;

typedef struct group{
    
    char* CustomerName;
	int NumOfSalads;
    int NumOfBurgers;
    char Status;
    struct group * Next;
} Group; 

typedef struct nodestruct{
    
    Group* Front;
    int numberOfCustomer;
}NODE;


extern int debugMode;

void clearToEoln();
int getNextNWSChar();
int getPosInt();
char *getName();
void printCommands();
void doAdd(NODE * Curr );
void doCallAhead(NODE * Curr );
void doWaiting(NODE * Curr );
void doRetrieve(NODE * Curr );
void doList(NODE * Curr );
void doDisplay(NODE * Curr );
void doEstimateTime(NODE * Curr );
void addToList(NODE * Curr , int NumOfBurgers, int NumOfSalads, char* customerName, char * Status);
int doesNameExist(NODE * Curr , char* CustomerName);
int updateStatus(NODE * Curr , char* CustomerName);
char* retrieveAndRemove(NODE * Curr , int, int);
int countOrdersAhead(NODE * Curr , char* CustomerName);
int displayWaitingTime(NODE * Curr , char* CustomerName);
void displayOrdersAhead(NODE * Curr , char* CustomerName);
void displayListInformation(NODE * Curr );
