/*
本代码由沈睿曦完成
第一次完成：1月1日
*/

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
