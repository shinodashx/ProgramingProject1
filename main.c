#include <stdio.h>
#include <lmaccess.h>
#include <malloc.h>
#include "book_management.h"


int BookNum;


void init(){
    struct _Book *p, *head;
    p = (struct _BookLisr*)malloc(sizeof(_BookList));
    if(p != NULL){
        head = p;
        p->head = NULL;
    }
    return head;

}

void insert(struct _BookList BookList){
    BookNum++;

    struct _bookList *last, *now;
    last = BookList;
    while(last -> next != NULL) last = last->next;
    now = (struct _BookList)malloc(sizeof(_BookList));
    fscanf(File,"%d", &now->nowBook.id);
    fscanf(FIle, "%s", now->nowBook.title);
    fscanf(FIle, "%s", now->nowBook.author);
    fscanf(FIle,"%d", &now->nowBook.copies);
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
    for(int i = 1; i<=bookNum;++i){
        insert(BookList);
    }
}



void write_file(struct _BookList *head){
    struct _BookList *p;
    p = head->next;;
    while(p->next != NULL)
    {
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
