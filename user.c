#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "book_management.h"
#include "utils.h"


int user_interface(int userid, BookList *BOOKLIST, UserList *USERLIST) {
    while (1) {
        printf("================================================================\n");
        printf("################################################################\n");
        printf("#    Please choose your choice:(Input choice number)           #\n");
        printf("#    1.Find book by title.                                     #\n");
        printf("#    2.Find book by author                                     #\n");
        printf("#    3.Find book by year                                       #\n");
        printf("#    4.Borrow book                                             #\n");
        printf("#    5.Return book                                             #\n");
        printf("#    6.List my borrowed books                                  #\n");
        printf("#    7.exit                                                    #\n");
        printf("################################################################\n");
        printf("================================================================\n");

        char OP[100];
        scanf("%s", OP);
        int OP_flag = 1;
        for (int i = 0; i < (int) strlen(OP); ++i) {
            if (OP[i] < '0' || OP[i] > '7') {
                OP_flag = 0;
                break;
            }
        }
        if (!OP_flag) {
            printf("================================================================\n");
            printf("Error choice, please choose your choice:(Input choice number)\n");
            continue;
        }


        int usOp = (int) atoi(OP);
        if (usOp > 9 || usOp < 1) {
            printf("================================================================\n");
            printf("Error choice, please choose your choice:(Input choice number)\n");
            continue;
        }
        if (usOp == 1) {
            printf("================================================================\n");
            printf("Please input book title\n");
            char bookTitle[100];
//            getc(stdin);
//            fgets(bookTitle,100,stdin);
//            bookTitle[strlen(bookTitle)-1] = '\0';
            scanf("%s", bookTitle);
            BookList res = find_book_by_title(bookTitle, BOOKLIST);
            if (res.length == 0) {
                printf("================================================================\n");
                printf("Cannot find this book:!\n");
            } else {
                printf("================================================================\n");
                printf("book id: %d\t", res.list->next->id);
                printf("title: %s\t", res.list->next->title);
                printf("author: %s\t", res.list->next->authors);
                printf("year: %d\t", res.list->next->year);
                printf("copies: %d\n", res.list->next->copies);
            }
        }
        if (usOp == 2) {
            printf("================================================================\n");
            printf("Please input book author\n");
            char bookAuthor[100];
//            getc(stdin);
//            fgets(bookTitle,100,stdin);
//            bookTitle[strlen(bookTitle)-1] = '\0';
            scanf("%s", bookAuthor);
            BookList res = find_book_by_author(bookAuthor, BOOKLIST);
            if (res.length == 0) {
                printf("================================================================\n");
                printf("Cannot find this book:!\n");
            } else {
                printf("================================================================\n");
                printf("book id: %d\t", res.list->next->id);
                printf("title: %s\t", res.list->next->title);
                printf("author: %s\t", res.list->next->authors);
                printf("year: %d\t", res.list->next->year);
                printf("copies: %d\n", res.list->next->copies);
            }
        }
        if (usOp == 3) {
            printf("================================================================\n");
            printf("Please input book year:\n");
            int year;
            scanf("%d", &year);
            BookList res = find_book_by_year(year, BOOKLIST);
            if (res.length == 0) {
                printf("================================================================\n");
                printf("Cannot find this book:!\n");
            } else {
                printf("================================================================\n");
                printf("book id: %d\t", res.list->next->id);
                printf("title: %s\t", res.list->next->title);
                printf("author: %s\t", res.list->next->authors);
                printf("year: %d\t", res.list->next->year);
                printf("copies: %d\n", res.list->next->copies);
            }
        }
        if (usOp == 4) {
            printf("================================================================\n");
            User *p = USERLIST->list->next;
            int flag = 1;
            while(p!=NULL){
                if(p->id == userid) {
                    if(p->borrowednumber == 8) flag = 0;
                    break;
                }
                p = p->next;
            }
            if(!flag) {
                printf("================================================================\n");
                printf("You have borrowed 8 books, please return books.\n");
                continue;
            }

            printf("1.Borrowed by book id.\n");
            printf("2.Borrowed by book title.\n");
            printf("3.borrowed by book author.\n");
            printf("4.borrowed by book year.\n");
            char OP[100];
            scanf("%s", OP);
            int OP_flag = 1;
            for (int i = 0; i < (int) strlen(OP); ++i) {
                if (OP[i] < '0' || OP[i] > '9') {
                    OP_flag = 0;
                    break;
                }
            }
            if(!OP_flag){
                printf("Invalid choice!\n");
                continue;
            }
            int op = (int)atoi(OP);
            if(op>4||op<1){
                printf("Invalid choice!\n");
                continue;
            }
            if (op == 1) {
                char idc[110];
                printf("Please input book id:\n");
                scanf("%s", idc);
                int idcflag = 1;
                for(int i = 0;i<(int)strlen(idc);++i){
                    if(idc[i] > '9' || idc[i]<'0') {
                        idcflag = 0;
                        break;
                    }
                }
                if(!idcflag ) {
                    printf("Invalid id!\n");
                    break;
                }
                int id = (int)atoi(idc);
                int resb = borrow_book(id, userid, BOOKLIST, USERLIST);
                if (resb == 1) {
                    printf("Successfully\n");
                } else if (resb == 2) {
                    printf("Be borrowed\n");
                } else {
                    printf("Cannot find this book");
                }
            } else if (op == 2) {
                printf("================================================================\n");
                printf("Please input book title\n");
                char bookTitle[100];
                scanf("%s", bookTitle);
                BookList res = find_book_by_title(bookTitle, BOOKLIST);
                if (res.length == 0) {
                    printf("================================================================\n");
                    printf("Cannot find this book!\n");
                } else {
                    int resb = borrow_book((int) res.list->next->id, userid, BOOKLIST, USERLIST);
                    if (resb == 1) {
                        printf("Successfully\n");
                    } else if (resb == 2) {
                        printf("Be borrowed\n");
                    } else {
                        printf("Cannot find this book\n");
                    }
                }
            } else if (op == 3) {
                printf("================================================================\n");
                printf("Please input book author\n");
                char bookAuthor[100];
                scanf("%s", bookAuthor);
                BookList res = find_book_by_author(bookAuthor, BOOKLIST);
                if (res.length == 0) {
                    printf("================================================================\n");
                    printf("Cannot find this book!\n");
                } else {
                    int resb = borrow_book((int) res.list->next->id, userid, BOOKLIST, USERLIST);
                    if (resb == 1) {
                        printf("Successfully\n");
                    } else if (resb == 2) {
                        printf("Be borrowed\n");
                    } else {
                        printf("Cannot find this book");
                    }
                }
            } else if (op == 4) {
                printf("================================================================\n");
                printf("Please input book year\n");
                char yearc[110];
                scanf("%s", yearc);
                int idcflag = 1;
                for(int i = 0;i<(int)strlen(yearc);++i){
                    if(yearc[i] > '9' || yearc[i]<'0') {
                        idcflag = 0;
                        break;
                    }
                }
                if(!idcflag ) {
                    printf("Invalid id!\n");
                    break;
                }
                int year = (int)atoi(yearc);
                BookList res = find_book_by_year(year, BOOKLIST);
                if (res.length == 0) {
                    printf("================================================================\n");
                    printf("Cannot find this book!\n");
                } else {
                    borrow_book(res.list->next->id, userid, BOOKLIST, USERLIST);
                }
            }
        }
        if (usOp == 5) {
            printf("================================================================\n");
            printf("Please input book id:\n");
            int bookid;
            scanf("%d", &bookid);
            int resr = return_book(bookid, userid, BOOKLIST, USERLIST);
            if (resr == 1) printf("Successfully!\n");
            if (resr == 0) printf("You haven't borrowed this book!\n");
            if (resr == -1) printf("This book is not in library!\n");
        }
        if(usOp == 6){
            printf("================================================================\n");
            int res = list_my_borrowedbook(userid,BOOKLIST,USERLIST);
            if(res == 1) printf("You don't have borrowed books.\n");
        }
        if (usOp == 7) return 0;

    }

}