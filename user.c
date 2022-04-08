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
        int usOp = get_op();
        switch (usOp) {
            case 1: {
                find_book(usOp, BOOKLIST);
                continue;
            }
            case 2: {
                find_book(usOp, BOOKLIST);
                continue;
            }
            case 3: {
                find_book(usOp, BOOKLIST);
                continue;
            }
            case 4: {
                borrow(userid, BOOKLIST, USERLIST);
                continue;
            }
            case 5: {
                return_(userid, BOOKLIST, USERLIST);
                continue;
            }
            case 6: {
                printf("================================================================\n");
                int res = list_my_borrowedbook(userid, BOOKLIST, USERLIST);
                if (res == 1) printf("You don't have borrowed books.\n");
                continue;
            }
            case 7: {
                return 0;
            }
            default: {
                printf("================================================================\n");
                printf("Error choice, please choose your choice:(Input choice number)\n");
                continue;
            }
        }

    }
}