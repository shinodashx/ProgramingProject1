#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "book_management.h"
#include "utils.h"


void user_interface(BookList *BOOKLIST, UserList *USERLIST){
    while(1) {
        printf("================================================================\n");
        printf("################################################################\n");
        printf("#    Please choose your choice:(Input choice number)           #\n");
        printf("#    1.Find book by title.                                     #\n");
        printf("#    2.Find book by author                                     #\n");
        printf("#    3.Find book by year                                       #\n");
        printf("#    4.Borrow book                                             #\n");
        printf("#    5.Return book                                             #\n");
        printf("#    6.List Borrowed books                                     #\n");
        printf("#    7.exit                                                    #\n");
        printf("################################################################\n");

        int usOp;
        scanf("%d",&usOp);
        int usFlag = 1;
        while(1){
            if(usOp>=1&&usOp<=6) break;
            else {
                printf("================================================================\n");
                printf("Error choice number\n");
                printf("Please input your choice:\n");
                scanf("%d", &usOp);
            }
        }
        if(usOp == 1){
            printf("================================================================\n");
            printf("Please input book title\n");
            char bookTitle[100];
//            getc(stdin);
//            fgets(bookTitle,100,stdin);
//            bookTitle[strlen(bookTitle)-1] = '\0';
            scanf("%s", bookTitle);
            BookList res = find_book_by_title(bookTitle, BOOKLIST);
            if(res.length== 0){
                printf("================================================================\n");
                printf("Cannot find this book:!\n");
            } else {
                printf("================================================================\n");
                printf("%d\t", res.list->next->id);
                printf("%s\t", res.list->next->title);
                printf("%s\t", res.list->next->authors);
                printf("%d\t", res.list->next->year);
                printf("%d\n", res.list->next->copies);
            }
        }
        if(usOp == 2){
            printf("================================================================\n");
            printf("Please input book author\n");
            char bookAuthor[100];
//            getc(stdin);
//            fgets(bookTitle,100,stdin);
//            bookTitle[strlen(bookTitle)-1] = '\0';
            scanf("%s", bookAuthor);
            BookList res = find_book_by_author(bookAuthor, BOOKLIST);
            if(res.length== 0){
                printf("================================================================\n");
                printf("Cannot find this book:!\n");
            } else {
                printf("================================================================\n");
                printf("%d\t", res.list->next->id);
                printf("%s\t", res.list->next->title);
                printf("%s\t", res.list->next->authors);
                printf("%d\t", res.list->next->year);
                printf("%d\n", res.list->next->copies);
            }
        }
        if(usOp == 3){
            printf("================================================================\n");
            printf("Please input book year:\n");
            int year;
            scanf("%d", &year);
            BookList res = find_book_by_year(year, BOOKLIST);
            if(res.length == 0){
                printf("================================================================\n");
                printf("Cannot find this book:!\n");
            } else {
                printf("================================================================\n");
                printf("%d\t", res.list->next->id);
                printf("%s\t", res.list->next->title);
                printf("%s\t", res.list->next->authors);
                printf("%d\t", res.list->next->year);
                printf("%d\n", res.list->next->copies);
            }
        }
        if(usOp == 4){
            printf("================================================================\n");
            printf("1.Borrowed by book id.\n");
            printf("2.Borrowed by book title.\n");
            printf("3.borrowed by book author.\n");
            printf("4.borrowed by book year.\n");
            int op;
            scanf("%d", &op);
            if (op == 1) {
                int id;
                scanf("%d", &id);
                borrow_book(id, BOOKLIST);
            } else if (op == 2) {
                printf("================================================================\n");
                printf("Please input book title");
                char bookTitle[100];
                scanf("%s", bookTitle);
                BookList res = find_book_by_title(bookTitle, BOOKLIST);
                if (res.list == NULL) {
                    printf("================================================================\n");
                    printf("Cannot find this book!\n");
                } else {
                    borrow_book(res.list->id, BOOKLIST);
                }
            } else if (op == 3) {
                printf("================================================================\n");
                printf("Please input book author");
                char bookAuthor[100];
                scanf("%s", bookAuthor);
                BookList res = find_book_by_author(bookAuthor, BOOKLIST);
                if (res.list == NULL) {
                    printf("================================================================\n");
                    printf("Cannot find this book!\n");
                } else {
                    borrow_book(res.list->id, BOOKLIST);
                }
            } else if (op == 4) {
                printf("================================================================\n");
                printf("Please input book year");
                int year;
                scanf("%d", &year);
                BookList res = find_book_by_year(year, BOOKLIST);
                if (res.list == NULL) {
                    printf("================================================================\n");
                    printf("Cannot find this book!\n");
                } else {
                    borrow_book(res.list->id, BOOKLIST);
                }
            }
        }
        if(usOp == 5){
//            return_book();

        }

        if(usOp == 6) exit(0);

    }

}