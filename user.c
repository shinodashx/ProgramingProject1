#include <stdio.h>
#include <stdlib.h>
#include "book_management.h"

int borrow_book(int id, BookList *BOOKLIST) {

    Book *p = BOOKLIST -> list;
    int flag = 0;
    while(p->next!=NULL){
        if(p->id == id){
            if(p->borrowed == 1){
                return 2;
            }
            flag = 1;
            p->borrowed = 1;
            return 1;
        }
    }
    if(!flag) return 0;
}


int return_book(int id,BookList *BOOKLIST) {
    Book *p = BOOKLIST -> list;
    int flag = 0;
    while(p->next!=NULL){
        if(p->id == id){
            if(p->borrowed == 0){
                return 1;
            }
            flag = 1;
            p->borrowed = 0;
            return 1;
        }
    }
    if(!flag) return 0;
}

void user_interface(BookList BOOKLIST, UserList USERLIST){
    while(1) {
        printf("Please choose your choice:(Input choice number)");
        printf("1.Find book by title.");
        printf("2.Find book by author");
        printf("3.Find book by year");
        printf("4.Borrow book");
        printf("5.Return book");
        printf("6.exit");
        int usOp;
        scanf("%d",&usOp);
        int usFlag = 1;
        while(1){
            if(usOp>=1&&usOp<=6) break;
            else {
                printf("Error choice number");
                scanf("%d", &usOp);
            }
        }
        if(usOp == 1){
            printf("Please input book title");
            char bookTitle[100];
            scanf("%s", bookTitle);
            BookList *res = find_book_by_title(bookTitle, &BOOKLIST);
            if(res == NULL){
                printf("Cannot find this book!\n");
            } else {
                printf("%d ", res->list->id);
                printf("%s ", res->list->title);
                printf("%s ", res->list->authors);
                printf("%s", res->list->year);
                printf("%d \n", res->list->copies);
            }
        }
        if(usOp == 2){
            printf("Please input book author");
            char bookAuthor[100];
            scanf("%s", bookAuthor);
            BookList *res = find_book_by_title(bookAuthor, &BOOKLIST);
            if(res == NULL){
                printf("Cannot find this book!\n");
            } else {
                printf("%d ", res->list->id);
                printf("%s ", res->list->title);
                printf("%s ", res->list->authors);
                printf("%s", res->list->year);
                printf("%d \n", res->list->copies);
            }
        }
        if(usOp == 3){
            printf("Please input book author");
            char bookAuthor[100];
            scanf("%s", bookAuthor);
            BookList *res = find_book_by_title(bookAuthor, &BOOKLIST);
            if(res == NULL){
                printf("Cannot find this book!\n");
            } else {
                printf("%d ", res->list->id);
                printf("%s ", res->list->title);
                printf("%s ", res->list->authors);
                printf("%s", res->list->year);
                printf("%d \n", res->list->copies);
            }
        }
        if(usOp == 4){
            printf("1.Borrowed by book id.\n");
            printf("2.Borrowed by book title.\n");
            printf("3.borrowed by book author.\n");
            printf("4.borrowed by book year.\n");
            int op;
            scanf("%d", &op);
            if (op == 1) {
                int id;
                scanf("%d", &id);
                borrow_book(id, &BOOKLIST);
            } else if (op == 2) {
                printf("Please input book title");
                char bookTitle[100];
                scanf("%s", bookTitle);
                BookList *res = find_book_by_title(bookTitle, &BOOKLIST);
                if (res == NULL) {
                    printf("Cannot find this book!\n");
                } else {
                    borrow_book(res->list->id, &BOOKLIST);
                }
            } else if (op == 3) {
                printf("Please input book author");
                char bookAuthor[100];
                scanf("%s", bookAuthor);
                BookList *res = find_book_by_author(bookAuthor, &BOOKLIST);
                if (res == NULL) {
                    printf("Cannot find this book!\n");
                } else {
                    borrow_book(res->list->id, &BOOKLIST);
                }
            } else if (op == 4) {

                printf("Please input book year");
                int year;
                scanf("%d", year);
                BookList *res = find_book_by_year(year, &BOOKLIST);
                if (res == NULL) {
                    printf("Cannot find this book!\n");
                } else {
                    borrow_book(res->list->id, &BOOKLIST);
                }
            }
        }
        if(usOp == 5){
            return_book();

        }

        if(usOp == 6) exit(0);

    }

}