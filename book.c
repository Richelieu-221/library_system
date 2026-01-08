#include <stdio.h>
#include <stdlib.h>
#include "book.h"

// 添加图书
void addBook(Book** head) 
{
    Book* b = (Book*)malloc(sizeof(Book));
    printf("请输入图书ID: ");
    scanf("%d", &b->bookId);
    printf("请输入图书名称: ");
    scanf("%s", b->name);
    printf("请输入作者: ");
    scanf("%s", b->author);
    printf("请输入数量: ");
    scanf("%d", &b->quantity);
    b->next = NULL;

    if (*head == NULL) {
        *head = b;
    } else {
        Book* p = *head;
        while (p->next != NULL) {
            p = p->next;
        }
        p->next = b;
    }
}

// 显示所有图书
void displayBooks(Book* head) 
{
    if (head == NULL) {
        printf("当前系统内没有图书\n");
        return;
    }
    Book* p = head;
    while (p != NULL) {
        printf("图书ID: %d\n", p->bookId);
        printf("名称: %s\n", p->name);
        printf("作者: %s\n", p->author);
        printf("数量: %d\n", p->quantity);
        printf("------------------------\n");
        p = p->next;
    }
}
/*
本部分代码由李兴瑞完成
第一次完成：1月1日
*/
// 搜索图书
Book* searchBook(Book* head, int id) {
    Book* p = head;
    while (p != NULL) {
        if (p->bookId == id) {
            return p;
        }
        p = p->next;
    }
    return NULL;
}

// 删除图书
void deleteBook(Book** head, int id) {
    if (*head == NULL) {
        printf("当前还没有图书被加入系统\n");
        return;
    }
    if ((*head)->bookId == id) {
        Book* t = *head;
        *head = (*head)->next;
        free(t);
        return;
    }
    Book* p = *head;
    while (p->next != NULL) {
        if (p->next->bookId == id) {
            Book* t = p->next;
            p->next = p->next->next;
            free(t);
            return;
        }
        p = p->next;
    }
    printf("未找到该图书\n");
}
/*
本部分代码由李兴瑞完成
第二次完成：1月2日
*/