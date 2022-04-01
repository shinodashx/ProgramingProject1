#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "book_management.h"
#include "user.h"
#include "manager.h"
#include "utils.h"


int userLogin(const char *username, const char *password, UserList *USERLIST) {
    User *p = USERLIST->list->next;
    while (p != NULL) {
        if (strcmp(p->username, username) == 0) {
            if (strcmp(p->password, password) == 0) {
                if (p->userType == 0) return 0;
                else return 1;
            } else {
                return 2;
            }
        }
        p = p->next;
    }
    return 3;
}

void run_interface(char *BookFile, char *UserFile, BookList *BOOKLIST, UserList *USERLIST) {
    while (1) {
        printf("================================================================\n");
        printf("Please choose your choice:(Input choice number)\n");
        printf("1.Register.\n");
        printf("2.Login.\n");
        printf("3.Exit.\n");
        printf("================================================================\n");

        int op = get_op();
        if (op == -1) continue;
        if (op > 3 || op < 1) {
            printf("================================================================\n");
            printf("Error choice, please choose your choice:(Input choice number)\n");
            continue;
        }
        if (op == 1) {
            printf("================================================================\n");
            printf("Please choose your user type:(Input choice number)\n");
            printf("1.User.\n");
            printf("2.Manager.\n");

            int rg_op;
            while (1) {
                rg_op = get_op();
                if (rg_op == -1 || rg_op > 2 || rg_op < 1) {
                    printf("================================================================\n");
                    printf("Error choice, please choose your choice:(Input choice number)\n");
                    continue;
                }
                if (rg_op == 1 || rg_op == 2) break;
            }
            user_register((rg_op - 1), BOOKLIST, USERLIST);

        }
        if (op == 2) {
            char userName[100];
            char userPassword[100];
            printf("================================================================\n");
            printf("Please input your user name:\n");
            scanf("%s", userName);
            getchar();
            printf("================================================================\n");
            printf("Please input your password:\n");
            scanf("%s", userPassword);
            getchar();
            int type = userLogin(userName, userPassword, USERLIST);
            if (type == 0) {
                printf("================================================================\n");
                printf("Successfully login!\n");
                int Userid = check_user_id(userName, USERLIST);
                int uer_op = user_interface(Userid, BOOKLIST, USERLIST);
            } else if (type == 1) {
                printf("================================================================\n");
                printf("Successfully login!\n");
                int Userid = check_user_id(userName, USERLIST);
                int user_op = manager_interface(Userid, BOOKLIST, USERLIST);
            } else if (type == 2) {
                printf("Invalid password\n");
            } else {
                printf("Invalid username\n");
            }
        }
        if (op == 3) {
            store_file(BookFile, UserFile, BOOKLIST, USERLIST);
            exit(0);
        }
    }
}
