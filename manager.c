#include <stdio.h>
#include <stdlib.h>
#include "book_management.h"


int add_book(Book book){
    BookNum++;
    struct _bookList *last, *now;
    last = BookList;
    while(last -> next != NULL) last = last->next;
    now = (struct _BookList)malloc(sizeof(_BookList));
    fscanf(File,"%d", &now->nowBook.id);
    fscanf(FIle, "%s", now->nowBook.title);
    fscanf(FIle, "%s", now->nowBook.author);
    fscanf(FIle,"%d", &now->nowBook.copies);
    last->next = now;
    last = now;
}

int remove_book(Book book){

}


BookList find_book_by_title (const char *title){
    struct _BookList *p;
    p = BookHead->next;
    int flag = 0;
    while(p->next!=NUll){
        if(p->nowBook.title == title){
            flag = 1;
            _BookList res = p->next;
            return res;
        }
    }
    if(!flag) p = p->next;
    return p;
}

BookList find_book_by_author (const char *author){
    struct _BookList *p;
    p = BookHead->next;
    int flag = 0;
    while(p->next!=NUll){
        if(p->nowBook.title == author){
            flag = 1;
            struct _BookList res = p->next;
            return res;
        }
    }
    if(!flag) p = p->next;
    return p;
}


BookList find_book_by_year (unsigned int year){
    struct _BookList *p;
    p = BookHead->next;
    int flag = 0;
    while(p->next!=NUll){
        if(p->nowBook.title == year){
            flag = 1;
            _BookList res = p->next;
            return res;
        }
    }
    if(!flag) p = p->next;
    return p;
}

void borrow_book(int id){
    struct _BookList *p;
    p = BookHead->next;
    int flag = 0;
    while(p->next!=NUll){
        if(p->nowBook.id == id && p->nowBook.getatable == 1){
            p->nowBook.getatable = 0;
            flag = 1;
            struct _BookList res = p->nowBook;
            return res;
            break;
        }
    }
    if(!flag) p = p->next;
    return p;
}


void return_book(int id){
    struct _BookList *p;
    p = BookHead->next;
    int flag = 0;
    while(p->next!=NUll){
        if(p->nowBook.id == id && p->nowBook.getatable == 1){
            p->nowBook.getatable = 0;
            flag = 1;
            struct _BookList res = p->nowBook;
            return res;
            break;
        }
    }
    if(!flag) p = p->next;
    return p;
}

void userinterfscea(){
    while(1) {
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
        scanf("%d",&maOp);
        int usFlag = 1;
        while(1){
            if(maOp>=1&&maOp<=9) break;
            else {
                printf("Error choice number");
                scanf("%d", &maOp);
            }
        }
        if(maOp == 1){
            printf("");
            char bookTitle[100];
            char bookAuthor[100];
            int bookYear;
            scanf("%s", bookTitle);
            scanf("%s",bookAuthor);
            scanf("%d",bookYear);

        }
        if(maOp == 2{
            printf("");
            char bookTitle[100];
            char bookAuthor[100];
            int bookYear;
            scanf("%s", bookTitle);
            scanf("%s",bookAuthor);
            scanf("%d",bookYear);
        }
        if(maOp == 3){
            printf("Please input book title");
            char bookTitle[100];
            scanf("%s", bookTitle);
            _BookList res = find_book_by_title(bookTitle);
            if(res == NULL){
                printf("Cannot find this book!\n");
            } else {
                printf("%d ", res->nowbook.id);
                printf("%s ", res->nowbook.title);
                printf("%s ", res->nowbook.author);
                printf("%d \n", res->nowbook.copies);
            }
        }
        if(maOp == 4){
            printf("Please input book author");
            char author[100];
            scanf("%s", author);
            find_book_by_author(author);
            _BookList res = find_book_by_title(bookTitle);
            if(res == NULL){
                printf("Cannot find this book!\n");
            } else {
                printf("%d ", res->nowbook.id);
                printf("%s ", res->nowbook.title);
                printf("%s ", res->nowbook.author);
                printf("%d \n", res->nowbook.copies);
            }
        }
        if(maOp == 5){
            printf("Please input book year");
            int year;
            scanf("%d", year);
            find_book_by_year(year);
            _BookList res = find_book_by_title(bookTitle);
            if(res == NULL){
                printf("Cannot find this book!\n");
            } else {
                printf("%d ", res->nowbook.id);
                printf("%s ", res->nowbook.title);
                printf("%s ", res->nowbook.author);
                printf("%d \n", res->nowbook.copies);
            }
        }
        if(maOp == 4){
            struct _BookList res = borrow_book(id);
            if(res == NULL){

            } else {

            }
        }
        if(maOp == 5){

        }
        if(maOp == 6){

        }
        if(maOp == 7) exit(0);

    }

}