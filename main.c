/*
本代码为张知行于一月3日完成

*/
#include <stdio.h>
#include "book.h"
#include "borrower.h"


int main() {
    Book* bookHead = NULL;
    Borrower* borrowerHead = NULL;

    int choice;
    while (1) {
        printf("\n图书管理系统\n");
        printf("1. 添加图书\n");
        printf("2. 显示所有图书\n");
        printf("3. 删除图书\n");
        printf("4. 添加借书人\n");
        printf("5. 显示所有借书人\n");
        printf("6. 删除借书人\n");
        printf("7. 借书\n");
        printf("8. 还书\n");
        printf("0. 退出\n");
        printf("请输入选择: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            addBook(&bookHead);
            break;
        case 2:
            displayBooks(bookHead);
            break;
        case 3:
            int bookId;
            printf("请输入要删除的图书ID: ");
            scanf("%d", &bookId);
            deleteBook(&bookHead, bookId);
            break;
        case 4:
            addBorrower(&borrowerHead);
            break;
        case 5:
            displayBorrowers(borrowerHead);
            break;
        case 6:
            int borrowerId;
            printf("请输入要删除的借书人ID: ");
            scanf("%d", &borrowerId);
            deleteBorrower(&borrowerHead, borrowerId);
            break;
        case 7:
            // 借书逻辑
            int borrowBookId, borrowBorrowerId;
            printf("请输入借书人ID: ");
            scanf("%d", &borrowBorrowerId);
            Borrower* borrower = searchBorrower(borrowerHead, borrowBorrowerId);
            if (borrower != NULL) {
                printf("请输入要借阅的图书ID: ");
                scanf("%d", &borrowBookId);
                Book* book = searchBook(bookHead, borrowBookId);
                if (book != NULL && book->quantity > 0) {
                    book->quantity--;
                    borrower->borrowedBookId = borrowBookId;
                    printf("借书成功\n");
                }
                else {
                    printf("图书不存在或数量不足\n");
                }
            }
            else {
                printf("借书人不存在\n");
            }
            break;
        case 8:   

            // 还书逻辑
            int returnBorrowerId;
            printf("请输入借书人ID: ");
            scanf("%d", &returnBorrowerId);
            Borrower* returnBorrower = searchBorrower(borrowerHead, returnBorrowerId);
            if (returnBorrower != NULL && returnBorrower->borrowedBookId != -1) {
                Book* returnBook = searchBook(bookHead, returnBorrower->borrowedBookId);
                if (returnBook != NULL) {
                    returnBook->quantity++;
                    returnBorrower->borrowedBookId = -1;
                    printf("还书成功\n");
                }
                else {
                    printf("图书不存在\n");
                }
            }
            else {
                printf("借书人未借书\n");
            }
            break;
        case 0:
            return 0;
        default:
            printf("无效选择\n");
        }
    }
}