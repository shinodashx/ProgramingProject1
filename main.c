#include <stdio.h>
#include <lmaccess.h>
#include <malloc.h>
#include "book_management.h"


int BookNum;
int UserNum;

void init(){
    struct _Book *p, *head;
    p = (struct _BookLisr*)malloc(sizeof(_BookList));
    if(p != NULL){
        head = p;
        p->head = NULL;
    }
    return head;

}

void insertBook(struct _BookList BookList){
    BookNum++;
    struct _bookList *last, *now;
    last = BookList;
    while(last -> next != NULL) last = last->next;
    now = (struct _BookList)malloc(sizeof(_BookList));
    fscanf(File,"%d", &now->nowbook.id);
    fscanf(FIle, "%s", now->nowbook.title);
    fscanf(FIle, "%s", now->nowbook.author);
    fscanf(FIle,"%d", &now->nowbook.copies);
    last->next = now;
    last = now;

}

void insertUser(struct _UserList UserList){
    UserNum++;
    struct _UserList *last, *now;
    last = UserList;
    while(last -> next != NULL) last = last->next;
    now = (struct _UserList)malloc(sizeof(_UserList));
    fscanf(File, "%d", now->NowUser.id);
    fscanf(FIle, "%d", now->NowUser.userType);
    fscanf(FIle, "%s", now->NowUser.username);
    fscanf(FIle, "%s", now->NowUser.password);
    fscanf(FIle,"%d", &now->NowUser.registeryear);
    last->next = now;
    last = now;
}


void load_file(char *Data){
    BookList = init();

    FILE *FIle  = fopen(Data, "r");
    if(fopen(Data, "r") == NULL){
        printf("Error\nLibrary Data does exist: %s\n", Data);
    }
    struct _BookList *bookList = malloc(sizeof(_Book));
    int bookNum;
    int userNum;
    fscanf(FIle, "%d", &bookNum);
    fscanf(File, "%d", &userNum);
    for(int i = 1; i<=bookNum;++i){
        insertBook(BookList);
    }
    for(int i = 1; i<=userNum;++i){
        insertUser(UserList);
    }
}



void write_file(struct _BookList *Userhead, struct _UserList UserHead){
    fprintf("%d", BookNum);
    struct _BookList *p;
    int Bookhead;
    p = Bookhead->next;;
    while(p->next != NULL)
    {
        fprintf(File, "%d ", p->nowbook.id);
        fprintf(FIle, "%s ", p->nowbook.title);
        fprintf(File, "%s ", p->nowbook.author);
        fprintf(File, "%d \n", p->nowbook.copies);
    }
    fprintf("%d", UserNum);
    struct _UserList *p;
    p = UserHead->next;
    while(p->next != NULL){
        fprintf(File, "%d ", p->nowbook.id);
        fprintf(FIle, "%s ", p->nowbook.title);
        fprintf(File, "%s ", p->nowbook.author);
        fprintf(File, "%d \n", p->nowbook.copies);
    }

}


int main() {

    char Data[10000];
    load_file(Data);
    run_interface();
    write_file();
    return 0;
}
