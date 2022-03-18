#include <stdio.h>
#include <lmaccess.h>
#include <malloc.h>
#include "book_management.h"


void insert(struct _Book nowBook){


}


void load_file(char *Data){

    FILE *FIle  = fopen(Data, "r");
    if(fopen(Data, "r") == NULL){
        printf("Error\nLibrary Data does exist: %s\n", Data);
    }

    struct _BookList *bookList = malloc(sizeof(_Book));
    int bookNum;
    int userNum;
    fscanf(FIle, "%d", &bookNum);
    for(int i = 1; i<=bookNum;++i){
        struct _Book nowBook;
        fscanf(File,"%d", &nowBook.id);
        fscanf(FIle, "%s", nowBook.title);
        fscanf(FIle, "%s", nowBook.authors);
        fscanf(FIle,"%d", &nowBook.copies);
        insert(nowBook);
    }
}


int main() {

    char Data[10000];
    load_file(Data);
    run_interface();
    write_file();
    return 0;
}
