#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "book_management.h"
#include "utils.h"


int add_book(Book book, BookList *BOOKLIST) {
    Book *now;
    Book *last;
    now = &book;
    last = BOOKLIST->list;
    while (last->next != NULL) last = last->next;
    now->id = last->id+1;
    now->next = NULL;
    last->next = now;
    last = now;
    return 1;
}

int remove_book(Book book) {

    return 1;
}




int manager_interface(int userid, BookList *BOOKLIST, UserList *USERLIST) {
    while (1) {
        printf("================================================================\n");
        printf("################################################################\n");
        printf("#    Please choose your choice:(Input choice number)           #\n");
        printf("#    1.Add book                                                #\n");
        printf("#    2.Remove book                                             #\n");
        printf("#    3.Find book by title.                                     #\n");
        printf("#    4.Find book by author                                     #\n");
        printf("#    5.Find book by year                                       #\n");
        printf("#    6.Borrow book                                             #\n");
        printf("#    7.Return book                                             #\n");
        printf("#    8.List all books in library                               #\n");
        printf("#    9.exit                                                    #\n");
        printf("################################################################\n");
        int maOp;
        scanf("%d", &maOp);
        int usFlag = 1;
        while (1) {
            if (maOp >= 1 && maOp <= 9) break;
            else {
                printf("Error choice number");
                scanf("%d", &maOp);
            }
        }
        if (maOp == 1) {
            printf("1");
            Book *book = (Book *) malloc(sizeof(Book));
            printf("Please input book title:");

            char *title = malloc(sizeof(1024));
            scanf("%s",title);
            book->title = malloc(sizeof(strlen(title)+1));
            book->title = title;

            char *author = malloc(sizeof(1024));
            scanf("%s",author);
            book->authors = malloc(sizeof(strlen(author)+1));
            book->authors = author;
            scanf("%d", &book->year);
            scanf("%d", &book->copies);
            book->borrowed = 0;
            add_book(*book, BOOKLIST);

        }
        if (maOp == 2) {
            printf("");
            char bookTitle[100];
            char bookAuthor[100];
            int bookYear;
            scanf("%s", bookTitle);
            scanf("%s", bookAuthor);
            scanf("%d", &bookYear);
        }
        if (maOp == 3) {
            printf("Please input book title");
            char bookTitle[100];
            scanf("%s", bookTitle);
            BookList res = find_book_by_title(bookTitle, BOOKLIST);
            if(res.list == NULL){
                printf("Cannot find this book!\n");
            } else {
                printf("%d ", res.list->id);
                printf("%s ", res.list->title);
                printf("%s ", res.list->authors);
                printf("%d", res.list->year);
                printf("%d \n", res.list->copies);
            }
        }
        if (maOp == 4) {
            printf("Please input book author");
            char bookAuthor[100];
            scanf("%s", bookAuthor);
            BookList res = find_book_by_title(bookAuthor, BOOKLIST);
            if(res.list== NULL){
                printf("Cannot find this book!\n");
            } else {
                printf("%d ", res.list->id);
                printf("%s ", res.list->title);
                printf("%s ", res.list->authors);
                printf("%d", res.list->year);
                printf("%d \n", res.list->copies);
            }
        }
        if (maOp == 5) {
            printf("Please input book author");
            char bookAuthor[100];
            scanf("%s", bookAuthor);
            BookList res = find_book_by_title(bookAuthor, BOOKLIST);
            if(res.list == NULL){
                printf("Cannot find this book!\n");
            } else {
                printf("%d ", res.list->id);
                printf("%s ", res.list->title);
                printf("%s ", res.list->authors);
                printf("%d", res.list->year);
                printf("%d \n", res.list->copies);
            }
        }
        if (maOp == 4) {
            printf("1.Borrowed by book id.\n");
            printf("2.Borrowed by book title.\n");
            printf("3.borrowed by book author.\n");
            printf("4.borrowed by book year.\n");
            int op;
            scanf("%d", &op);
            if (op == 1) {
                int id;
                scanf("%d", &id);
                borrow_book(id, userid, BOOKLIST, USERLIST);
            } else if (op == 2) {
                printf("Please input book title");
                char bookTitle[100];
                scanf("%s", bookTitle);
                BookList res = find_book_by_title(bookTitle, BOOKLIST);
                if (res.list == NULL) {
                    printf("Cannot find this book!\n");
                } else {
                    borrow_book(res.list->id, userid, BOOKLIST, USERLIST);
                }
            } else if (op == 3) {
                printf("Please input book author");
                char bookAuthor[100];
                scanf("%s", bookAuthor);
                BookList res = find_book_by_author(bookAuthor, BOOKLIST);
                if (res.list == NULL) {
                    printf("Cannot find this book!\n");
                } else {
                    borrow_book(res.list->id, userid, BOOKLIST, USERLIST);
                }
            } else if (op == 4) {

                printf("Please input book year");
                int year;
                scanf("%d", &year);
                BookList res = find_book_by_year(year, BOOKLIST);
                if (res.list == NULL) {
                    printf("Cannot find this book!\n");
                } else {
                    borrow_book(res.list->id, userid, BOOKLIST, USERLIST);
                }
            }
        }
        if (maOp == 5) {

        }
        if (maOp == 6) {

        }
        if (maOp == 7) return 0;

    }

}