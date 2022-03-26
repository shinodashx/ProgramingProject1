#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include "book_management.h"


int check_user_id(char *username, UserList *USERLIST){
    User *p = USERLIST->list->next;
    while(p!= NULL){
        if(strcmp(p->username, username) == 0){
            return p->id;
        }
        p = p->next;
    }
}

int borrow_book(int bookid, int userid,BookList *BOOKLIST,UserList *USERLIST) {
    User *pp = USERLIST->list->next;
//    while(pp!= NULL){
//        if(pp->id == userid) {
//
//        }
//    }
    Book *p = BOOKLIST->list->next;
    while (p != NULL) {
        if (p->id == bookid) {
            if (p->borrowed == 1) {
                return 2;
            }
            p->borrowed = 1;
            while(pp!=NULL){
                if(userid == pp->id){
                    pp->borrowednumber = pp->borrowednumber +1;
                    pp->borrowedId[pp->borrowednumber] = p->id;
                }
                return 1;
            }
        }
        p = p->next;
    }
    return 0;
}


int return_book(int bookid, BookList *BOOKLIST) {
    Book *p = BOOKLIST->list;
    int flag = 0;
    while (p->next != NULL) {
        if (p->id == bookid) {
            if (p->borrowed == 0) {
                return 1;
            }
            flag = 1;
            p->borrowed = 0;
            return 1;
        }
    }
    if (!flag) return 0;
}

int min(int x, int y) {
    if (x > y) return y;
    else return x;
}

int max(int x, int y) {
    if (x > y) return x;
    else return y;
}


int check_username(char *username, UserList *USERLIST) {
    User *p = USERLIST->list->next;
    while (p != NULL) {
        int cnt = 0;
        if ((int) strlen(username) == (int) strlen(p->username)) {
            for (int i = 0; i < min((int) strlen(username), (int) (p->username)); ++i) {
                if (username[i] == p->username[i]) cnt++;
            }
            if (cnt == strlen(username)) return 0;
        }
        p = p->next;
    }
    return 1;
}

void User_register(BookList *BOOKLIST, UserList *USERLIST) {
    printf("================================================================\n");
    printf("Please input your user name:\n");
    char *username = malloc(sizeof(1000));
    while (1) {
        scanf("%s", username);
        if (check_username(username, USERLIST)) break;
        else {
            printf("================================================================\n");
            printf("The username is used, please input another username.\n");
        }
    }
    char *password = malloc(sizeof(1000));
    printf("Please input your password:\n");
    scanf("%s", password);
    User *now = (User *) malloc(sizeof(User));
    int id;
    now->username = username;
    now->password = password;
    now->userType = 0;
    now->borrowednumber = 0;
    User *last = USERLIST->list->next;
    while (last->next != NULL) last = last->next;
    now->id = last->id + 1;
    now->next = NULL;
    last->next = now;
}

void Manager_register(BookList *BOOKLIST, UserList *USERLIST) {
    printf("================================================================\n");
    printf("Please input your user name.");
    char *username = malloc(sizeof(1000));
    while (1) {
        scanf("%s", username);
        if (check_username(username, USERLIST)) break;
        else {
            printf("================================================================\n");
            printf("The username is used, please input another username.");
        }
    }
    char *password = malloc(sizeof(1000));
    printf("================================================================\n");
    printf("Please input your username.");
    User *now = (User *)malloc(sizeof(User));
    int id;
    now->username = username;
    now->password = password;
    now->userType = 1;
    now->borrowednumber = 0;
    User *last = USERLIST->list;
    while (last->next != NULL) last = last->next;
    now->id = last->id + 1;
    now->next = NULL;
    last->next = now;
}





void listBook(BookList *BOOKLIST) {
    Book *cur = BOOKLIST->list->next;
    while (cur != NULL) {
        printf("%s\t%s\n", cur->title, cur->authors);
        cur = cur->next;
    }
    //printf("%s\t%s\n", cur->title, cur->authors);
}


void listUser(UserList *USERLIST) {
    User *cur = USERLIST->list->next;
    while (cur != NULL) {
        printf("%s\t%s\n", cur->username, cur->password);
        cur = cur->next;
    }
    //printf("%s\t%s\n", cur->username, cur->password);
}
