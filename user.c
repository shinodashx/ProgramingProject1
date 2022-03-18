#include <stdio.h>
#include <stdlib.h>
#include "book_management.h"


BookList find_book_by_title (const char *title){
    for(int i  = 1; i<= bookNum;++i){
        if( == ){
            break;
        }
    }
    return res;

}

BookList find_book_by_author (const char *author){
    for(int i = 1; i<=bookNum;++i){
        if( == ){

            break;
        }
    }
    return res;
}


BookList find_book_by_year (unsigned int year){
    for(int i = 1;i<=bookNum;++i){
        if( == ){

            break;
        }
    }
    return res;

}

void borrow_book(){

}

void return_book(){

}


void userinterfscea(){
    while(1) {
        printf("Please choose your choice:(Input choice number)");
        printf("1.Find book by title.");
        printf("2.Find book by author");
        printf("3.Find book by year");
        printf("4.Borrow book");
        printf("5.Return book");
        printf("6.List all books in library");
        printf("7.exit");
        int usOp;
        scanf("%d",&usOp);
        int usFlag = 1;
        while(1){
            if(usOp>=1&&usOp<=6) break;
            else {
                printf("Error choice number");
                scanf("%d", &usOp);
            }
        }
        if(usOp == 1){
            printf("Please input book title");
            char bookTitle[100];
            scanf("%s", bookTitle);
            find_book_by_title(bookTitle);
        }
        if(usOp == 2){
            printf("Please input book author");
            char author[100];
            scanf("%s", author);
            find_book_by_author(author);
        }
        if(usOp == 3){
            printf("Please input book year");
            int year;
            scanf("%d", year);
            find_book_by_year(year);
        }
        if(usOp == 4){


        }
        if(usOp == 5){

        }
        if(usOp == 6){

        }
        if(usOp == 7) exit(0);

    }

}