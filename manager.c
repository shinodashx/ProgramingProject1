#include <stdio.h>
#include <stdlib.h>
#include "book_management.h"


int add_book(Book book, BookList *BOOKLIST) {
    Book *now;
    Book *last;
    last = BOOKLIST->list;
    while (last->next != NULL) last = last->next;
    now->next = NULL;
    last->next = now;
    last = now;
}

int remove_book(Book book) {

}


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

void manager_interface(BookList BOOKLIST, UserList USERLIST) {
    while (1) {
        printf("################################################################");
        printf("#      Please choose your choice:(Input choice number)         #");
        printf("#      1.Add book                                              #");
        printf("#      2.Remove book                                           #");
        printf("#      3.Find book by title.                                   #");
        printf("#      4.Find book by author                                   #");
        printf("#      5.Find book by year                                     #");
        printf("#      6.Borrow book                                           #");
        printf("#      7.Return book                                           #");
        printf("#      8.List all books in library                             #");
        printf("#      9.exit                                                  #");
        printf("################################################################");
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
            printf("");
            Book book = *(Book *) malloc(sizeof(Book));
            scanf("%s", book.title);
            scanf("%s", book.authors);
            scanf("%d", &book.year);
            scanf("%s", &book.copies);
            book.borrowed = 0;
            add_book(book, &BOOKLIST);

        }
        if (maOp == 2) {
            printf("");
            char bookTitle[100];
            char bookAuthor[100];
            int bookYear;
            scanf("%s", bookTitle);
            scanf("%s", bookAuthor);
            scanf("%d", bookYear);
        }
        if (maOp == 3) {
            printf("Please input book title");
            char bookTitle[100];
            scanf("%s", bookTitle);
            BookList *res = find_book_by_title(bookTitle, &BOOKLIST);
            if (res == NULL) {
                printf("Cannot find this book!\n");
            } else {
                printf("%d ", res->list->id);
                printf("%s ", res->list->title);
                printf("%s ", res->list->authors);
                printf("%s", res->list->year);
                printf("%d \n", res->list->copies);
            }
        }
        if (maOp == 4) {
            printf("Please input book author");
            char bookAuthor[100];
            scanf("%s", bookAuthor);
            BookList *res = find_book_by_author(bookAuthor, &BOOKLIST);
            if (res == NULL) {
                printf("Cannot find this book!\n");
            } else {
                printf("%d ", res->list->id);
                printf("%s ", res->list->title);
                printf("%s ", res->list->authors);
                printf("%s", res->list->year);
                printf("%d \n", res->list->copies);
            }
        }
        if (maOp == 5) {
            printf("Please input book year");
            int year;
            scanf("%d", year);
            BookList *res = find_book_by_year(year, &BOOKLIST);
            if (res == NULL) {
                printf("Cannot find this book!\n");
            } else {
                printf("%d ", res->list->id);
                printf("%s ", res->list->title);
                printf("%s ", res->list->authors);
                printf("%s", res->list->year);
                printf("%d \n", res->list->copies);
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
        if (maOp == 5) {

        }
        if (maOp == 6) {

        }
        if (maOp == 7) exit(0);

    }

}