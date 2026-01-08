/*
本代码由李兴瑞完成
第一次完成：1月1日
*/

#ifndef BOOK_H
#define BOOK_H

typedef struct Book {
    int bookId;
    char name[50];
    char author[50];
    int quantity;
    struct Book* next;
} Book;

#endif

