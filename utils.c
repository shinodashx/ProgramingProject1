#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdlib.h>
#include "book_management.h"


int borrow_book(int bookid, int userid, BookList *BOOKLIST, UserList *USERLIST) {
    User *pp = USERLIST->list->next;
    Book *p = BOOKLIST->list->next;
    while (p != NULL) {
        if (p->id == bookid) {
            if (p->copies == 0) {
                return 2;
            }
            p->borrowed = p->borrowed + 1;
            p->copies = p->copies - 1;
            while (pp != NULL) {
                if (userid == pp->id) {
                    pp->borrowednumber = pp->borrowednumber+1;
                    BorrowList *lst = pp->borrowbook;
                    while(lst->next!=NULL) lst = lst->next;
                    BorrowList *tmp = (BorrowList *) malloc(sizeof (BorrowList));
                    tmp->next = NULL;
                    tmp->bookid = bookid;
                    lst->next = tmp;
                }
                pp = pp->next;
            }
            return 1;
        }
        p = p->next;
    }
    return 0;
}

int return_book(int bookid, int userid, BookList *BOOKLIST, UserList *USERLIST) {
    User *pp = USERLIST->list;
    int flag = 1;
    while (pp != NULL) {
        if (pp->id == userid) {
            BorrowList *brp = pp->borrowbook;
            int cnt = 0;
            if(brp->next == NULL) return 0;
            if(brp->next->next == NULL){
                if(brp->next->bookid == bookid) {
                    pp->borrowednumber = pp->borrowednumber - 1;
                    brp->next = NULL;
                    break;
                } else {
                    return 0;
                }
            }
            while(brp->next->next!=NULL){
                if(brp->next->bookid == bookid) {
                    cnt++;
                    brp->next = brp->next->next;
                    break;
                }
            }
            if (cnt == 0) return 0;
            pp->borrowednumber = pp->borrowednumber - 1;
        }
        pp = pp->next;
    }
    Book *p = BOOKLIST->list;
    while (p != NULL) {
        if (p->id == bookid) {
            p->borrowed = p->borrowed - 1;
            p->copies = p->copies + 1;
            return 1;
        }
        p = p->next;
    }
    return -1;
}

int min(int x, int y) {
    if (x > y) return y;
    else return x;
}

int max(int x, int y) {
    if (x > y) return x;
    else return y;
}

int cmp_char(char *x, char *y){
    if(strlen(x)!=strlen(y)) return 0;
    for(int i = 0;i<=min(strlen(x),strlen(y));++i){
        if(x[i]!=y[i]) return 0;
    }
    return 1;
}

int check_user_id(char *username, UserList *USERLIST) {
    User *p = USERLIST->list->next;
    while (p != NULL) {
        if (strcmp(p->username, username) == 0) {
            return p->id;
        }
        p = p->next;
    }
}

int check_username(char *username, UserList *USERLIST) {
    for(int i = 0 ;i<(int)(strlen(username));++i){
        if(username[i] == ' ') return -1;
    }
    User *p = USERLIST->list->next;
    while (p != NULL) {
        int cnt = 0;
        if(cmp_char(username,p->username) == 1){
            return 0;
        }
        p = p->next;
    }
    return 1;
}

void user_register(int usertype, BookList *BOOKLIST, UserList *USERLIST) {
    printf("================================================================\n");
    printf("Please input your user name:\n");
    char *username = malloc(sizeof(40960));
    while (1) {
        fgets(username,40960,stdin);
        username[strlen(username)-1] = '\0';
        int resc = check_username(username, USERLIST);
        if (resc == 1) break;
        else if(resc == 0){
            printf("================================================================\n");
            printf("The username is used, please input another username.\n");
            return;
        } else {
            printf("================================================================\n");
            printf("The username should not contain spaces.\n");
            return;
        }
    }
    char *password = malloc(sizeof(40960));\
    printf("================================================================\n");
    printf("Please input your password:\n");
    fgets(password,40960,stdin);
    password[strlen(password)-1] = '\0';
    for(int i = 0;i< strlen(password);++i){
        if(password[i] == ' ') {
            printf("================================================================\n");
            printf("The password should not contain spaces.\n");
            return;
        }
    }
    User *now = (User *) malloc(sizeof(User));
    now->username = username;
    now->password = password;
    now->userType = usertype;
    now->borrowednumber = 0;
    BorrowList *borrowHead = (BorrowList *)malloc(sizeof(BorrowList));
    borrowHead->next = NULL;
    now->borrowbook = borrowHead;
    User *last = USERLIST->list;
    while (last->next != NULL) last = last->next;
    now->id = last->id + 1;
    now->next = NULL;
    last->next = now;
    USERLIST->length = USERLIST->length + 1;
    printf("================================================================\n");
    printf("Successfully register!\n");
}


void listBook(BookList *BOOKLIST) {
    Book *cur = BOOKLIST->list->next;
    while (cur != NULL) {
        printf("%s\t%s\n", cur->title, cur->authors);
        cur = cur->next;
    }
}

void listUser(UserList *USERLIST) {
    User *cur = USERLIST->list->next;
    while (cur != NULL) {
        printf("%s\t%s\n", cur->username, cur->password);
        cur = cur->next;
    }
}

int list_my_borrowedbook(int userid, BookList *BOOKLIST, UserList *USERLIST) {
    Book *bp = BOOKLIST->list->next;
    User *up = USERLIST->list->next;
    int tot = 0;
    int cnt = 1;
    int tmp[11];
    for (int i = 0; i <= 10; ++i) {
        tmp[i] = -1;
    }
    int ct = 0;
    while (up != NULL) {
        if (up->id == userid) {
            if (up->borrowednumber == 0) return 1;
            BorrowList *lst = up->borrowbook->next;
            while(lst!=NULL) {
                tmp[++ct] = lst->bookid;
                lst = lst->next;
            }
            tot = up->borrowednumber;
        }
        up = up->next;
    }
    for (int i = 1; i <= tot; ++i) {
        while (bp != NULL) {
            if (bp->id == tmp[i]) {
                printf("================================================================\n");
                printf("book id: %d\t", bp->id);
                printf("title: %s\t", bp->title);
                printf("authors: %s\t", bp->authors);
                printf("year: %d\t", bp->year);
                printf("copies: %d\n", bp->copies);
                break;
            }
            bp = bp->next;
        }
        bp = BOOKLIST->list;
    }
    return 0;
}

void print_books(BookList res) {
    printf("================================================================\n");
    printf("book id: %d\t", res.list->next->id);
    printf("title: %s\t", res.list->next->title);
    printf("author: %s\t", res.list->next->authors);
    printf("year: %d\t", res.list->next->year);
    printf("copies: %d\n", res.list->next->copies);
}

void borrow_function(BookList res, int userid, BookList *BOOKLIST, UserList *USERLIST) {
    if (res.length == 0) {
        printf("================================================================\n");
        printf("Cannot find this book!\n");
    } else {
        int resb = borrow_book((int) res.list->next->id, userid, BOOKLIST, USERLIST);
        if (resb == 1) {
            printf("Successfully\n");
        } else if (resb == 2) {
            printf("Be borrowed\n");
            getchar();
        } else {
            printf("Cannot find this book\n");
        }
    }
}

int get_op() {
    char OP[100];
    fgets(OP, 40960, stdin);
    int OP_flag = 1;
    for (int i = 0; i < (int) strlen(OP) - 1; ++i) {
        if (OP[i] < '0' || OP[i] > '9') {
            OP_flag = 0;
            break;
        }
    }
    if (!OP_flag) {
        return -1;
    }
    int res = (int) atoi(OP);
    return res;
}

void find_book(int choice, BookList *BOOKLIST) {
    if (choice == 1) {
        printf("================================================================\n");
        printf("Please input book title\n");
        char bookTitle[100];
        fgets(bookTitle, 40960, stdin);
        bookTitle[strlen(bookTitle) - 1] = '\0';
        BookList res = find_book_by_title(bookTitle, BOOKLIST);
        if (res.length == 0) {
            printf("================================================================\n");
            printf("Cannot find this book:!\n");
        } else {
            print_books(res);
        }
    }
    if (choice == 2) {
        printf("================================================================\n");
        printf("Please input book author\n");
        char bookAuthor[100];
        fgets(bookAuthor, 40960, stdin);
        BookList res = find_book_by_author(bookAuthor, BOOKLIST);
        if (res.length == 0) {
            printf("================================================================\n");
            printf("Cannot find this book:!\n");
        } else {
            print_books(res);
        }
    }
    if (choice == 3) {
        printf("================================================================\n");
        printf("Please input book year:\n");
        int year = get_op();
        if (year == -1) {
            printf("================================================================\n");
            printf("Error input!\n");
            return;
        }
        BookList res = find_book_by_year(year, BOOKLIST);
        if (res.length == 0) {
            printf("================================================================\n");
            printf("Cannot find this book:!\n");
        } else {
            print_books(res);
        }
    }
}

void borrow(int userid, BookList *BOOKLIST, UserList *USERLIST){
    printf("================================================================\n");
    User *p = USERLIST->list->next;
    int flag = 1;
    while (p != NULL) {
        if (p->id == userid) {
            if (p->borrowednumber == 8) flag = 0;
            break;
        }
        p = p->next;
    }
    if (!flag) {
        printf("================================================================\n");
        printf("You have borrowed 8 books, please return books.\n");
        return;
    }
    printf("1.Borrowed by book id.\n");
    printf("2.Borrowed by book title.\n");
    printf("3.borrowed by book author.\n");
    printf("4.borrowed by book year.\n");
    int br_op;
    while (1) {
        br_op = get_op();
        if (br_op == -1 || br_op > 4 || br_op < 1) {
            printf("================================================================\n");
            printf("Error choice, please choose your choice:(Input choice number)\n");
            continue;
        }
        break;
    }
    if (br_op == 1) {
        char idc[110];
        printf("================================================================\n");
        printf("Please input book id:\n");
        int id = get_op();
        if (id == -1) {
            printf("Invalid id!\n");
            return;
        }
        int resb = borrow_book(id, userid, BOOKLIST, USERLIST);
        if (resb == 1) {
            printf("================================================================\n");
            printf("Successfully\n");
        } else if (resb == 2) {
            printf("================================================================\n");
            printf("Be borrowed\n");
        } else {
            printf("================================================================\n");
            printf("Cannot find this book");
        }
    } else if (br_op == 2) {
        printf("================================================================\n");
        printf("Please input book title\n");
        char bookTitle[100];
        scanf("%s", bookTitle);
        BookList res = find_book_by_title(bookTitle, BOOKLIST);
        borrow_function(res, userid, BOOKLIST, USERLIST);
    } else if (br_op == 3) {
        printf("================================================================\n");
        printf("Please input book author\n");
        char bookAuthor[100];
        scanf("%s", bookAuthor);
        BookList res = find_book_by_author(bookAuthor, BOOKLIST);
        borrow_function(res, userid, BOOKLIST, USERLIST);
    } else if (br_op == 4) {
        printf("================================================================\n");
        printf("Please input book year\n");
        char yearc[110];
        scanf("%s", yearc);
        int idcflag = 1;
        for (int i = 0; i < (int) strlen(yearc); ++i) {
            if (yearc[i] > '9' || yearc[i] < '0') {
                idcflag = 0;
                break;
            }
        }
        if (!idcflag) {
            printf("================================================================\n");
            printf("Invalid id!\n");
            return;
        }
        int year = (int) atoi(yearc);
        BookList res = find_book_by_year(year, BOOKLIST);
        borrow_function(res, userid, BOOKLIST, USERLIST);
    }
}

void return_(int userid, BookList *BOOKLIST, UserList *USERLIST){
    printf("================================================================\n");
    printf("Please input book id:\n");
    int bookid = get_op();
    if(bookid == -1){
        printf("================================================================\n");
        printf("Invalid id!\n");
        return;
    }
    int resr = return_book(bookid, userid, BOOKLIST, USERLIST);
    if (resr == 1) printf("Successfully!\n");
    if (resr == 0) printf("You haven't borrowed this book!\n");
    if (resr == -1) printf("This book is not in library!\n");
}

void who_borrow(int bookid, BookList *BOOKLIST, UserList *USERLIST){
    int flag = 0;
    User *p = USERLIST -> list;
    while(p!= NULL){
        if(p->borrowednumber > 0){
            int cnt = 0;
            BorrowList *brp = p->borrowbook;
            while(brp!=NULL){
                if(brp->bookid == bookid) {
                    cnt++;
                }
                brp = brp->next;
            }
            if(cnt > 0){
                flag = 1;
                printf("================================================================\n");
                printf("userid: %d  username: %s\tnumber: %d\n",p->id,p->username,cnt);
            }
        }
        p = p->next;
    }
    if(!flag){
        printf("================================================================\n");
        printf("No one has borrowed this book!\n");
    }
}