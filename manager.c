#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "book_management.h"
#include "utils.h"


void admin_option(BookList *BOOKLIST, UserList *USERLIST) {
    printf("================================================================\n");
    printf("################################################################\n");
    printf("#    Please choose your choice:(Input choice number)           #\n");
    printf("#    1.Add book                                                #\n");
    printf("#    2.Remove book                                             #\n");
    printf("#    3.List user by borrowed book                              #\n");
    printf("#    4.edit book                                               #\n");
    printf("#    5.exit                                                   #\n");
    printf("################################################################\n");
    int op = get_op();
    switch (op) {
        case 1: {
            //Read in and store the book information to be added
            Book *book = (Book *) malloc(sizeof(Book));
            printf("Please input book title:\n");
            char *title = NULL;
            size_t len = 0;
            getline(&title, &len, stdin);
            book->title = malloc(sizeof(strlen(title) - 1));
            title[strlen(title) - 1] = '\0';
            book->title = title;
            printf("Please input book author:\n");
            char *author = NULL;
            len = 0;
            getline(&author, &len, stdin);
            book->authors = malloc(sizeof(strlen(author) - 1));
            author[strlen(author) - 1] = '\0';
            book->authors = author;
            printf("Please input book year:\n");
            int year = get_op();
            if (year == -1) {
                printf("Error year!\n");
                return;
            }
            printf("Please input book copies:\n");
            int copies = get_op();
            if (copies == -1) {
                printf("Error copies!\n");
                return;
            }
            book->year = year;
            book->copies = copies;
            book->borrowed = 0;
            int res = add_book(*book, BOOKLIST);
            if (res == 0) printf("Successfully added!\n");
            if (res == 1) printf("Invalid year(year > 2022)!\n");
            return;
        }
        case 2: {
            //Delete books by book id, and handle error messages.
            printf("Please input book id:\n");
            int id = get_op();
            if (id == -1) {
                printf("================================================================\n");
                printf("Invalid id!\n");
                return;
            }
            Book book;
            BookList res = find_book_by_id(id, BOOKLIST);
            if (res.length == 0) {
                book.id = -1;
            } else {
                book.id = res.list->next->id;
                book.year = res.list->next->year;
                book.title = res.list->next->title;
                book.authors = res.list->next->authors;
                book.borrowed = res.list->next->borrowed;
            }
            int resr = remove_book(book, BOOKLIST);
            if (resr == -1) printf("The book is not in the library\n");
            if (resr == 1) printf("The book is borrowed\n");
            if (resr == 0) printf("Successfully!\n");
            return;
        }
        case 3: {
            printf("================================================================\n");
            printf("Please input book id\n");
            int bookid = get_op();
            if (bookid == -1) {
                printf("Invalid id!\n");
                return;
            }
            who_borrow(bookid, BOOKLIST, USERLIST);
            return;
        }
        case 4: {
            edit_book(BOOKLIST);
            return;
        }
        case 5: {
            return;
        }
        default: {
            printf("================================================================\n");
            printf("Error choice, please choose your choice:(Input choice number)\n");
            return;
        }
    }
}

int manager_interface(int userid, BookList *BOOKLIST, UserList *USERLIST) {
    while (1) {
        printf("================================================================\n");
        printf("################################################################\n");
        printf("#    Please choose your choice:(Input choice number)           #\n");
        printf("#    1.Admin option                                            #\n");
        printf("#    2.Find book by title.                                     #\n");
        printf("#    3.Find book by author                                     #\n");
        printf("#    4.Find book by year                                       #\n");
        printf("#    5.Borrow book                                             #\n");
        printf("#    6.Return book                                             #\n");
        printf("#    7.List my borrowed books                                  #\n");
        printf("#    8.List all books                                          #\n");
        printf("#    9.exit                                                    #\n");
        printf("################################################################\n");
        int maOp = get_op();
        switch (maOp) {
            case 1: {
                admin_option(BOOKLIST, USERLIST);
                continue;
            }
            case 2: {
                find_book(maOp - 1, BOOKLIST);
                continue;
            }
            case 3: {
                find_book(maOp - 1, BOOKLIST);
                continue;
            }
            case 4: {
                find_book(maOp - 1, BOOKLIST);
                continue;
            }
            case 5: {
                borrow(userid, BOOKLIST, USERLIST);
                continue;
            }
            case 6: {
                return_(userid, BOOKLIST, USERLIST);
                continue;
            }
            case 7: {
                printf("================================================================\n");
                int res = list_my_borrowedbook(userid, BOOKLIST, USERLIST);
                if (res == 1) printf("You don't have borrowed books.\n");
                continue;
            }
            case 8: {
                listBook(BOOKLIST);
                continue;
            }
            case 9:
                return 0;
            default: {
                printf("================================================================\n");
                printf("Error choice, please choose your choice:(Input choice number)\n");
                continue;
            }
        }
    }
}