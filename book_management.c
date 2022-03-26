#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>
#include "book_management.h"
#include "utils.h"


int BookNum;
int UserNum;

int store_books(FILE *BookFile, BookList *BOOKLIST) {
    BookNum++;
    Book *now;
    Book *last;
    last = BOOKLIST->list;
    while (last->next != NULL) last = last->next;

    now = (Book *) malloc(sizeof(Book));


    char str[100];
    fgets(str, 99, stdin);
    char *x;
    x = strtok(str, '-');
    now->id = atoi(x);
    printf("%d", now->id);

    x = strtok(str, '-');
    now->title = malloc(strlen(x) + 1);
    now->title = x;
    now->title[strlen(x)] = '\0';
    x = strtok(str, '-');
    now->authors = malloc(strlen(x) + 1);
    now->authors = x;
    now->authors[strlen(x)] = '\0';
    x = strtok(str, '-');
    now->year = atoi(x);
    x = strtok(str, '-');
    now->copies = atoi(x);
    x = strtok(str, '-');
    now->borrowed = atoi(x);




//    fscanf(BookFile, "%d", &now->id);
//    fscanf(BookFile, "%s", now->title);
//    fscanf(BookFile, "%s", now->authors);
//    fscanf(BookFile,"%d",&now->year);
//    fscanf(BookFile, "%d", &now->copies);
//    fscanf(BookFile,"%d",&now->borrowed);
    printf("%s\n%s\n", now->id, now->title);
    now->next = NULL;
    last->next = now;
    return 1;
}

int store_users(FILE *BookFile, UserList *USERLIST) {
    UserNum++;
    User *now;
    User *last;
    last = USERLIST->list;
    while (last->next != NULL) last = last->next;
    now = (User *) malloc(sizeof(User));
    fscanf(BookFile, "%d", &now->id);
    fscanf(BookFile, "%d", &now->userType);
    fscanf(BookFile, "%s", now->username);
    fscanf(BookFile, "%s", now->password);
    fscanf(BookFile, "%d", &now->borrowednumber);
    for (int i = 0; i <= (int) (now->borrowednumber); ++i) {
        fscanf(BookFile, "%d", &now->borrowedId[i]);
    }
    now->next = NULL;
    last->next = now;
    return 1;
}

int load_books(FILE *BookFile, BookList *BOOKLIST) {
    Book *BookHead = (Book *) malloc(sizeof(Book));
    BOOKLIST->list = BookHead;
    BookHead->next = NULL;
    int bookNum;
    fscanf(BookFile, "%d\n", &bookNum);
    BookNum = 0;
    for (int i = 1; i <= bookNum; ++i) {
        BookNum++;
        Book *now;
        Book *last;
        last = BOOKLIST->list;
        while (last->next != NULL) last = last->next;

        now = (Book *) malloc(sizeof(Book));

        char *str = malloc(sizeof(1000));
        fgets(str, 1024, BookFile);
        char *x;
        x = strtok(str, "-");
        now->id = (int) atoi(x);
        printf("%d\n", now->id);

        x = strtok(NULL, "-");
        now->title = malloc(strlen(x) + 1);
        now->title = x;
        now->title[strlen(x)] = '\0';
        x = strtok(NULL, "-");
        now->authors = malloc(strlen(x) + 1);
        now->authors = x;
        now->authors[strlen(x)] = '\0';
        x = strtok(NULL, "-");
        now->year = atoi(x);
        x = strtok(NULL, "-");
        now->copies = atoi(x);
        x = strtok(NULL, "-");
        now->borrowed = atoi(x);

        now->next = NULL;
        last->next = now;
    }
    listBook(BOOKLIST);
}

int load_users(FILE *UserFile, UserList *USERLIST) {
    User *UserHead = (User *) malloc(sizeof(User));
    UserHead->next = NULL;
    USERLIST->list = UserHead;
    int userNum;
    fscanf(UserFile, "%d\n", &userNum);
    UserNum = 0;
    for (int i = 1; i <= userNum; ++i) {
        UserNum++;
        User *now;
        User *last;
        last = USERLIST->list;
        while (last->next != NULL) last = last->next;
        now = (User *) malloc(sizeof(User));
        char *str = malloc(sizeof(1000));
        fgets(str, 1024, UserFile);
        char *x;
        x = strtok(str, "-");
        now->id = (int) atoi(x);
        x = strtok(NULL, "-");
        now->userType = (int) atoi(x);
        x = strtok(NULL, "-");
        now->username = malloc(strlen(x) + 1);
        now->username = x;
        now->username[strlen(x)] = '\0';
        x = strtok(NULL, "-");
        now->password = malloc(strlen(x) + 1);
        now->password = x;
        now->password[strlen(x)] = '\0';
        puts(now->username);
        puts(now->password);
        x = strtok(NULL, "-");
        now->borrowednumber = (int) atoi(x);
        for (int j = 1; j <= (int) now->borrowednumber; ++j) {
            fscanf(UserFile, "%d\n", now->borrowedId[j]);
        }
        now->next = NULL;
        last->next = now;
    }
    listUser(USERLIST);
}


void load_file(BookList *BOOKLIST, UserList *USERLIST) {

    FILE *BookFile = fopen("BookFile.txt", "r");
    if (BookFile == NULL) {
        printf("Error\nLibrary Data does exist: BookData\n");
    }
    load_books(BookFile, BOOKLIST);

    FILE *UserFile = fopen("UserFile.txt", "r");
    if (UserFile == NULL) {
        printf("Error\nLibrary Data does exist: UserData\n");
    }
    load_users(UserFile, USERLIST);

}


//void write_file(FILE *BookFile, FILE *UserFile,BookList *BOOKLIST, UserList *USERLIST) {
//    fprintf("%d", BookNum);
//    Book *bp = BOOKLIST->list;
//    bp = bp->next;
//    while (bp->next != NULL) {
//        fprintf(BookFile, "%d ", bp->id);
//        fprintf(BookFile, "%s ", bp->title);
//        fprintf(BookFile, "%s ", bp->authors);
//        fprintf(BookFile, "%d \n", bp->copies);
//    }
//    fprintf("%d", UserNum);
//    User *up = USERLIST -> list;
//    up = up->next;
//    up = up->next;
//    while (up->next != NULL) {
//        fprintf(UserFile, "%d ", up->id);
//        fprintf(UserFile, "%d ", up->userType);
//        fprintf(UserFile, "%s ", up->username);
//        fprintf(UserFile, "%s ", up->password);
//    }
//
//}

BookList find_book_by_author(const char *author, BookList *BOOKLIST) {

    BookList  res;
    res.length = 0;
    Book *head = (Book*)malloc(sizeof(Book));
    head->next = NULL;
    res.list = head;
    Book *p = BOOKLIST->list->next;
    while (p != NULL) {
        int flag = 1;
        if((int)strlen(author)!=(int)(strlen(p->authors))) flag = 0;
        for(int i = 0;i<=min((int) strlen(author),(int)strlen(p->authors));++i){
            if(author[i] != p->authors[i]) {
                flag = 0;
                break;
            }
        }
        if (flag) {
            res.length = 1;
            Book *now = (Book *) malloc(sizeof(Book));
            memccpy(now,p,sizeof(Book),sizeof(Book));
            now->next = NULL;
            res.list->next = now;
            return res;
        }
        p = p->next;
    }
    return res;

}

BookList find_book_by_title(const char *title, BookList *BOOKLIST) {
    BookList  res;
    res.length = 0;
    Book *head = (Book*)malloc(sizeof(Book));
    head->next = NULL;
    res.list = head;
    Book *p = BOOKLIST->list->next;
    while (p != NULL) {
        int flag = 1;
        if((int)strlen(title)!=(int)(strlen(p->title))) flag = 0;
        for(int i = 0;i<=min((int) strlen(title),(int)strlen(p->title));++i){
            if(title[i] != p->title[i]) {
                flag = 0;
                break;
            }
        }
        if (flag) {
            res.length = 1;
            Book *now = (Book *) malloc(sizeof(Book));
            memccpy(now,p,sizeof(Book),sizeof(Book));
            now->next = NULL;
            res.list->next = now;
            return res;
        }
        p = p->next;
    }
    return res;

}

BookList find_book_by_year(unsigned int year, BookList *BOOKLIST) {

    BookList res;
    res.length = 0;
    Book *head = (Book *) malloc(sizeof(Book));
    head->next = NULL;
    res.list = head;

    Book *p = BOOKLIST->list;
    while (p != NULL) {
        int flag = 0;
        if ((int) year == (int) p->year) flag = 1;
        if (flag) {
            res.length = 1;
            Book *now = (Book *) malloc(sizeof(Book));
            memccpy(now, p, sizeof(Book), sizeof(Book));
            now->next = NULL;
            res.list->next = now;
            return res;
        }
        p = p->next;
    }
    return res;
}



