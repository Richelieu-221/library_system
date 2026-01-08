
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

