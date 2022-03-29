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

//int check_admin_code(char *)

void run_interface(char *BookFile, char *UserFile, BookList *BOOKLIST, UserList *USERLIST) {
    while (1) {
        printf("================================================================\n");
        printf("Please choose your choice:(Input choice number)\n");
        printf("1.Register.\n");
        printf("2.Login.\n");
        printf("3.Exit.\n");
        printf("================================================================\n");


        char OP[100];
        fgets(OP,1024, stdin);
        int OP_flag = 1;
        for (int i = 0; i < (int) strlen(OP)-1; ++i) {
            if (OP[i] < '0' || OP[i] > '9') {
                OP_flag = 0;
                break;
            }
        }
        if (!OP_flag) {
            printf("================================================================\n");
            printf("Error choice, please choose your choice:(Input choice number)\n");
            continue;
        }


        int op = (int) atoi(OP);
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

            char RG_OP[100];
            int rg_op;
            while (1) {
//                scanf("%s", RG_OP);
                fgets(RG_OP,1024, stdin);
                int RG_flag = 1;
                for (int i = 0; i < (int) strlen(RG_OP) -1 ; ++i) {
                    if (RG_OP[i] < '0' || RG_OP[i] > '2') {
                        RG_flag = 0;
                        break;
                    }
                }
                if (!RG_flag) {
                    printf("================================================================\n");
                    printf("Error choice, please choose your choice:(Input choice number)\n");
                    continue;
                }
                rg_op = (int) atoi(RG_OP);
                if (rg_op == 1 || rg_op == 2) break;
            }

//            if (rg_op == 1) {
//                User_register(BOOKLIST, USERLIST);
//            } else {
//                Manager_register(BOOKLIST, USERLIST);
//            }
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
