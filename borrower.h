

#ifndef BORROWER_H
#define BORROWER_H

typedef struct Borrower 
{
    int borrowerId;
    char name[50];
    char contact[50];
    int borrowedBookId;
    struct Borrower* next;
} Borrower;

#endif
