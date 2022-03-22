#include <stdio.h>
#include<stdlib.h>


int userLogin(char a[], char b[]) {
    int User_type = 1;
    return User_type;
}

void run_interface() {
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
            Use_register();
        } else {
            Manager_register();
        }

    }
    if (op == 2) {
        char userName[100];
        char userPassword[100];
        printf("Please input your user name:\n");
        printf("Please input your password:\n");
        int type = userLogin();
        if (type == 1) {
            user();
        } else {
            managerif();
        }
    }
    if (op == 3) {
        exit(0);
    }
}
