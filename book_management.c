#include <stdio.h>
#include <lmaccess.h>
#include <malloc.h>
#include "book_management.h"


int BookNum;
int UserNum;
int store_books(FILE *BookFile, BookList *BOOKLIST) {
    BookNum++;
    Book *now;
    Book *last;
    last = BOOKLIST->list;
    while (last->next != NULL) last = last->next;
    now = (Book *) malloc(sizeof(Book));
    fscanf(BookFile, "%d", &now->id);
    fscanf(BookFile, "%s", now->title);
    fscanf(BookFile, "%s", now->authors);
    fscanf(BookFile, "%d", &now->copies);
    now->next = NULL;
    last->next = now;
    last = now;
    return 1;
}

int store_users(FILE *BookFile, BookList *USERLIST) {
    UserNum++;
    User *now;
    User *last;
    last = USERLIST->list;
    while (last->next != NULL) last = last->next;
    now = (User *) malloc(sizeof(User));
    fscanf(BookFile, "%d", &now->id);
    fscanf(BookFile, "%d", now->userType);
    fscanf(BookFile, "%d", &now->username);
    fscanf(BookFile, "%d", &now->password);
    now->next = NULL;
    last->next = now;
    last = now;

    return 1;
}

int load_books(FILE *BookFile ,BookList *BOOKLIST){

    struct _Book *BookHead = (Book *) malloc(sizeof(Book));
    BookHead->next = NULL;
    BOOKLIST -> list = BookHead;
    BookHead->
    int bookNum;

    fscanf(BookFile, "%d", &bookNum);
    BookNum = bookNum;

    for (int i = 1; i <= bookNum; ++i) {
        int x = store_books(BookFile, BOOKLIST);
        if(x == 0) exit(0);
    }
}

int load_users(FILE *UserFile, UserList *USERLIST){
    User *UserHead = (User *) malloc(sizeof(User));
    UserHead->next = NULL;
    USERLIST->list = UserHead;
    int userNum;
    fscanf(UserFile, "%d", &userNum);
    UserNum = UserNum;
    for(int i = 1; i<=userNum;++i){
        int x = store_users(UserFile, USERLIST);
    }
}


int load_file(BookList *BOOKLIST, UserList *USERLIST) {

    FILE *BookFile = fopen("BookData.txt", "r");
    if (fopen("BookFile.txt", "r") == NULL) {
        printf("Error\nLibrary Data does exist: BookData\n");
    }
    load_books(BookFile,BOOKLIST);

    FILE *UserFile = fopen("BookData.txt", "r");
    if (fopen("UserFile.txt", "r") == NULL) {
        printf("Error\nLibrary Data does exist: BookData\n");
    }
    load_users(UserFile,USERLIST);

}


void write_file(FILE *BookFile, FILE *UserFile,BookList *BOOKLIST, UserList *USERLIST) {
    fprintf("%d", BookNum);
    Book *bp = BOOKLIST->list;
    bp = bp->next;
    while (bp->next != NULL) {
        fprintf(BookFile, "%d ", bp->id);
        fprintf(BookFile, "%s ", bp->title);
        fprintf(BookFile, "%s ", bp->authors);
        fprintf(BookFile, "%d \n", bp->copies);
    }
    fprintf("%d", UserNum);
    User *up = USERLIST -> list;
    up = up->next;
    up = up->next;
    while (up->next != NULL) {
        fprintf(UserFile, "%d ", up->id);
        fprintf(UserFile, "%d ", up->userType);
        fprintf(UserFile, "%s ", up->username);
        fprintf(UserFile, "%s ", up->password);
    }

}

BookList * find_book_by_author(const char *author, BookList *BOOKLIST){
    Book *p = BOOKLIST->list;
    p = p->next;
    int flag = 0;
    while(p->next!=NULL){
        if(p->authors == author){
            flag = 1;
            BookList *res;
            res -> list = p;
            return res;
        }
    }
    if(!flag) {
        BookList *res;
        res->list = NULL;
        return res;
    }
}

BookList * find_book_by_title(const char *title, BookList *BOOKLIST){
    Book *p = BOOKLIST->list;
    p = p->next;
    int flag = 0;
    while(p->next!=NULL){
        if(p->title == title){
            flag = 1;
            BookList *res;
            res -> list = p;
            return res;
        }
    }
    if(!flag) {
        BookList *res;
        res->list = NULL;
        return res;
    }
}

BookList * find_book_by_year(unsigned int year, BookList *BOOKLIST){
    Book *p = BOOKLIST->list;
    p = p->next;
    int flag = 0;
    while(p->next!=NULL){
        if(p->year == year){
            flag = 1;
            BookList *res;
            res -> list = p;
            return res;
        }
    }
    if(!flag) {
        BookList *res;
        res->list = NULL;
        return res;
    }
}


int check_username(char *username, UserList *USERLIST){
    User *p = USERLIST->list;
    while(p->next!=NULL){
        if(p->username == username){
            return 0;
        }
    }
    return 1;
}
 void User_register(BookList *BOOKLIST, UserList  *USERLIST){
     printf("Please input your user name.");
     char username[100];
     while(1){
         scanf("%s", username);
         if(check_username(username,USERLIST)) break;
         else {
             printf("The username is used, please input another username.");
         }
     }
     char password[1000];
     printf("Please input your username.");
     User *now;
     int id;
     now->username = username;
     now->password = password;
     now->userType = 0;
     now->borrowednumber = 0;
     User *last = USERLIST -> list;
     while(last->next!=NULL) last = last->next;
     now->id = last->id +1;
     now->next = NULL;
     last->next = now;
}

void Manager_register(BookList *BOOKLIST, UserList  *USERLIST){
    printf("Please input your user name.");
    char username[100];
    while(1){
        scanf("%s", username);
        if(check_username(username, USERLIST)) break;
        else {
            printf("The username is used, please input another username.");
        }
    }
    char password[1000];
    printf("Please input your username.");
    User *now;
    int id;
    now->username = username;
    now->password = password;
    now->userType = 1;
    now->borrowednumber = 0;
    User *last = USERLIST -> list;
    while(last->next!=NULL) last = last->next;
    now->id = last->id +1;
    now->next = NULL;
    last->next = now;
}