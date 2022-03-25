#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "book_management.h"
#include "user.h"
#include "manager.h"


int userLogin(const char *username, const char *password, UserList *USERLIST) {
    User *p = USERLIST->list->next;
    while(p!=NULL){
        if(strcmp(p->username, username) == 0) {
            if(strcmp(p->password, password) == 0){
                if(p->userType == 0) return 0;
                else return 1;
            } else {
                return 2;
            }
        }
        p = p->next;
    }
    return 3;
}

void run_interface(BookList *BOOKLIST, UserList *USERLIST) {
    printf("Please choose your choice:(Input choice number)\n");
    printf("1.Register.\n");
    printf("2.Login.\n");
    printf("3.Exit.\n");
    int op = 0;
    int opFlag = 1;
    scanf("%d", &op);
    while (opFlag) {
        if (op >= 1 && op <= 3) break;
        else {
            printf("Error choice, please choose your choice:(Input choice number)\n");
            scanf("%d", &op);
        }
    }
    if (op == 1) {
        printf("Please choose your user type:(Input choice number)\n");
        printf("1.User.\n");
        printf("2.Manager.\n");
        int opr;
        scanf("%d", &opr);
        int oprFlag = 1;
        while (oprFlag) {
            if (op >= 1 && op <= 3) break;
            else {
                printf("Error choice, please choose your choice:(Input choice number)\n");
                scanf("%d", &op);
            }
        }
        if (opr == 1) {
            User_register(BOOKLIST, USERLIST);
        } else {
            Manager_register(BOOKLIST, USERLIST);
        }

    }
    if (op == 2) {
        char userName[100];
        char userPassword[100];
        printf("Please input your user name:\n");
        scanf("%s",userName);
        printf("Please input your password:\n");
        scanf("%s",userPassword);
        int type = userLogin(userName, userPassword, USERLIST);
        printf("%d",type);
        if (type == 0) {
            printf("Successfully login!\n");
            user_interface(BOOKLIST,USERLIST);
        } else if(type == 1){
            printf("Successfully login!\n");
            manager_interface(BOOKLIST, USERLIST);
        } else if(type == 2){
            printf("Invaild password");
        } else {
            printf("Invalid username");
        }
    }
    if (op == 3) {
        exit(0);
    }
}
