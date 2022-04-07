#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "book_management.h"
#include "utils.h"


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
        printf("#    8.List my borrowed books                                  #\n");
        printf("#    9.List user by borrowed book                              #\n");
        printf("#    10.List all books                                         #\n");
        printf("#    11.exit                                                   #\n");
        printf("################################################################\n");
        int maOp = get_op();
        if (maOp == -1 || maOp > 11 || maOp < 1) {
            printf("================================================================\n");
            printf("Error choice, please choose your choice:(Input choice number)\n");
            continue;
        }
        if (maOp == 1) {
            //Read in and store the book information to be added
            Book *book = (Book *) malloc(sizeof(Book));
            printf("Please input book title:\n");
            char *title = malloc(sizeof(40960));
            fgets(title, 40960, stdin);
            book->title = malloc(sizeof(strlen(title) - 1));
            title[strlen(title) - 1] = '\0';
            book->title = title;
            char *author = malloc(sizeof(40960));
            printf("Please input book author:\n");
            fgets(author, 40960, stdin);
            book->authors = malloc(sizeof(strlen(author) - 1));
            author[strlen(author) - 1] = '\0';
            book->authors = author;
            printf("Please input book year:\n");
            int year = get_op();
            if (year == -1) {
                printf("Error year!\n");
                continue;
            }
            printf("Please input book copies:\n");
            int copies = get_op();
            if (copies == -1) {
                printf("Error copies!\n");
                continue;
            }
            book->year = year;
            book->copies = copies;
            printf("%d\n", copies);
            book->borrowed = 0;
            int res = add_book(*book, BOOKLIST);
            if (res == 0) printf("Successfully added!\n");
            if (res == 1) printf("Invalid year(year > 2022)!\n");
        }
        if (maOp == 2) {
            //Delete books by book id, and handle error messages.
            printf("Please input book id:\n");
            int id = get_op();
            if (id == -1) {
                printf("================================================================\n");
                printf("Invalid id!\n");
                continue;
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
        }
        if (maOp == 3) {
            find_book(maOp - 2, BOOKLIST);
        }
        if (maOp == 4) {
            find_book(maOp - 2, BOOKLIST);
        }
        if (maOp == 5) {
            find_book(maOp - 2, BOOKLIST);
        }
        if (maOp == 6) {
            borrow(userid, BOOKLIST, USERLIST);
        }
        if (maOp == 7) {
            return_(userid, BOOKLIST, USERLIST);
        }
        if (maOp == 8) {
            printf("================================================================\n");
            int res = list_my_borrowedbook(userid, BOOKLIST, USERLIST);
            if (res == 1) printf("You don't have borrowed books.\n");
        }
        if (maOp == 9) {
            printf("================================================================\n");
            printf("Please input book id\n");
            int bookid = get_op();
            if (bookid == -1) {
                printf("Invalid id!\n");
                continue;
            }
            who_borrow(bookid, BOOKLIST, USERLIST);
        }
        if (maOp == 10) {
            listBook(BOOKLIST);
        }
        if (maOp == 11) {
            return 0;
        }
    }
}