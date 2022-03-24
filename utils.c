#include <stdio.h>
#include <malloc.h>
#include "book_management.h"

int borrow_book(int id, BookList *BOOKLIST) {

    Book *p = BOOKLIST -> list;
    int flag = 0;
    while(p->next!=NULL){
        if(p->id == id){
            if(p->borrowed == 1){
                return 2;
            }
            flag = 1;
            p->borrowed = 1;
            return 1;
        }
    }
    if(!flag) return 0;
}


int return_book(int id,BookList *BOOKLIST) {
    Book *p = BOOKLIST -> list;
    int flag = 0;
    while(p->next!=NULL){
        if(p->id == id){
            if(p->borrowed == 0){
                return 1;
            }
            flag = 1;
            p->borrowed = 0;
            return 1;
        }
    }
    if(!flag) return 0;
}