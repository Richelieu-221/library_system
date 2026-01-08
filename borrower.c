// borrower.c
#include <stdio.h>
#include <stdlib.h>
#include "borrower.h"

// 添加借书人
// 参数：head - 指向借书人链表头指针的指针（二级指针）
// 功能：在链表末尾添加新的借书人节点
void addBorrower(Borrower** head)
{
    // 动态分配内存创建新的借书人节点
    Borrower* newBorrower = (Borrower*)malloc(sizeof(Borrower));

    // 输入借书人信息
    printf("请输入借书人ID: ");
    scanf("%d", &newBorrower->borrowerId);
    printf("请输入姓名: ");
    scanf("%s", newBorrower->name);
    printf("请输入联系方式: ");
    scanf("%s", newBorrower->contact);

    // 初始化借阅状态：-1表示当前未借阅任何图书
    newBorrower->borrowedBookId = -1;

    // 新节点作为链表末尾，next指针置为NULL
    newBorrower->next = NULL;

    // 处理链表插入
    if (*head == NULL)
    {
        // 如果链表为空，新节点成为头节点
        *head = newBorrower;
    }
    else
    {
        // 链表不为空，遍历到链表末尾
        Borrower* current = *head;
        while (current->next != NULL)
        {
            current = current->next;
        }
        // 在末尾插入新节点
        current->next = newBorrower;
    }
}

// 显示所有借书人信息
// 参数：head - 借书人链表的头指针
// 功能：遍历链表并打印所有借书人的详细信息
void displayBorrowers(Borrower* head)
{
    // 检查链表是否为空
    if (head == NULL) {
        printf("没有借书人记录\n");
        return;
    }

    // 遍历链表并打印每个节点的信息
    Borrower* current = head;
    while (current != NULL)
    {
        printf("借书人ID: %d\n", current->borrowerId);
        printf("姓名: %s\n", current->name);
        printf("联系方式: %s\n", current->contact);
        printf("借阅的图书ID: %d\n", current->borrowedBookId);
        printf("------------------------\n");

        // 移动到下一个节点
        current = current->next;
    }
}

// 根据ID搜索借书人
// 参数：head - 借书人链表的头指针
//        borrowerId - 要搜索的借书人ID
// 返回值：找到的借书人节点指针，未找到返回NULL
// 功能：线性搜索链表，查找指定ID的借书人
Borrower* searchBorrower(Borrower* head, int borrowerId)
{
    Borrower* current = head;

    // 遍历链表
    while (current != NULL) 
    {
        // 比较当前节点的ID与目标ID
        if (current->borrowerId == borrowerId) 
        {
            return current;  // 找到目标节点
        }
        current = current->next;
    }

    return NULL;  // 未找到目标节点
}

// 删除指定ID的借书人
// 参数：head - 指向借书人链表头指针的指针（二级指针）
//        borrowerId - 要删除的借书人ID
// 功能：从链表中删除指定节点并释放内存
void deleteBorrower(Borrower** head, int borrowerId) 
{
    // 检查链表是否为空
    if (*head == NULL) 
    {
        printf("链表为空\n");
        return;
    }

    // 处理删除头节点的特殊情况
    if ((*head)->borrowerId == borrowerId)
    {
        Borrower* temp = *head;      // 保存原头节点
        *head = (*head)->next;       // 头指针指向下一个节点
        free(temp);                  // 释放原头节点内存
        return;
    }

    // 遍历链表查找要删除的节点
    Borrower* current = *head;
    while (current->next != NULL)
    {
        // 检查下一个节点是否为要删除的节点
        if (current->next->borrowerId == borrowerId)
        {
            Borrower* temp = current->next;      // 保存要删除的节点
            current->next = current->next->next; // 跳过要删除的节点
            free(temp);                          // 释放内存
            return;
        }
        current = current->next;
    }

    // 未找到要删除的节点
    printf("未找到该借书人\n");
}
