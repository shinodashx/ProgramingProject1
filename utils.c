#define _GNU_SOURCE

#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdlib.h>
#include "book_management.h"

//Borrow a book function, and return a value through the function,
// indicating the borrowing result.
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
                    pp->borrowednumber = pp->borrowednumber + 1;
                    BorrowList *lst = pp->borrowbook;
                    while (lst->next != NULL) lst = lst->next;
                    BorrowList *tmp = (BorrowList *) malloc(sizeof(BorrowList));
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

//Return the book function, and return the value through the function, indicating the borrowing result.
int return_book(int bookid, int userid, BookList *BOOKLIST, UserList *USERLIST) {
    User *pp = USERLIST->list;
    while (pp != NULL) {
        if (pp->id == userid) {
            BorrowList *brp = pp->borrowbook;
            int cnt = 0;
            if (brp->next == NULL) return 0;
            if (brp->next->next == NULL) {
                if (brp->next->bookid == bookid) {
                    pp->borrowednumber = pp->borrowednumber - 1;
                    brp->next = NULL;
                    break;
                } else {
                    return 0;
                }
            }
            else{
                BorrowList *cur = pp->borrowbook;
                BorrowList *prev = pp->borrowbook;

                while(cur != NULL){
                    if(cur -> bookid == bookid){
                        cnt ++;
                        prev -> next = cur -> next;
                        break;
                    }
                    prev = cur;
                    cur = cur -> next;
                }
                // while (brp->next->next != NULL) {
                //     if (brp->next->bookid == bookid) {
                //         cnt++;
                //         brp->next = brp->next->next;
                //         break;
                //     }
                //     brp = brp->next;
                // }
                // if(brp->next->bookid == bookid) {
                //     brp->next = NULL;
                //     cnt++;
                // }
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

//Compares the two strings for equality, and returns 1 if they are equal, otherwise returns 0.
int cmp_char(char *x, char *y) {
    if (strlen(x) != strlen(y)) return 0;
    for (int i = 0; i <= min((int) strlen(x), (int) strlen(y)); ++i) {
        if (x[i] != y[i]) return 0;
    }
    return 1;
}

//Check the user id corresponding to the username and return
int check_user_id(char *username, UserList *USERLIST) {
    User *p = USERLIST->list->next;
    while (p != NULL) {
        if (strcmp(p->username, username) == 0) {
            return (int) p->id;
        }
        p = p->next;
    }
    return 0;
}

//Check if the corresponding username already exists in the system
int check_username(char *username, UserList *USERLIST) {
    for (int i = 0; i < (int) (strlen(username)); ++i) {
        if (username[i] == ' ') return -1;
    }
    User *p = USERLIST->list->next;
    while (p != NULL) {
        if (cmp_char(username, p->username) == 1) {
            return 0;
        }
        p = p->next;
    }
    return 1;
}


void user_register(int usertype, BookList *BOOKLIST, UserList *USERLIST) {
    printf("================================================================\n");
    printf("Please input your user name:\n");
//    char *username = (char *)malloc(sizeof(200));
//    fgets(username, 200, stdin);
    char *username = NULL;
    size_t len = 0;
    getline(&username, &len, stdin);
    username[strlen(username) - 1] = '\0';
    int resc = check_username(username, USERLIST);
    if (resc == 0) {
        printf("================================================================\n");
        printf("The username is used, please input another username.\n");
        return;
    } else if (resc == -1) {
        printf("================================================================\n");
        printf("The username should not contain spaces.\n");
        return;
    }
    char *password = NULL;
    printf("================================================================\n");
    printf("Please input your password:\n");
    len = 0;
    getline(&password, &len, stdin);
    password[strlen(password) - 1] = '\0';
    for (int i = 0; i < strlen(password); ++i) {
        if (password[i] == ' ') {
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
    BorrowList *borrowHead = (BorrowList *) malloc(sizeof(BorrowList));
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

//The user registration function creates a new structure for the current user and stores it in the linked list.
void listBook(BookList *BOOKLIST) {
    Book *cur = BOOKLIST->list->next;
    while (cur != NULL) {
        printf("id: %d\ttitle: %s\tauthors: %s\tyear: %u\n", cur->id, cur->title, cur->authors, cur->year);
        cur = cur->next;
    }
}

//List all users in the system.
void listUser(UserList *USERLIST) {
    User *cur = USERLIST->list->next;
    while (cur != NULL) {
        printf("%s\t%s\n", cur->username, cur->password);
        cur = cur->next;
    }
}

//Lists all books borrowed by the current user.
int list_my_borrowedbook(int userid, BookList *BOOKLIST, UserList *USERLIST) {
    Book *bp = BOOKLIST->list->next;
    User *up = USERLIST->list->next;
    int tot = 0;
    int tmp[11];
    for (int i = 0; i <= 10; ++i) {
        tmp[i] = -1;
    }
    int ct = 0;
    while (up != NULL) {
        if (up->id == userid) {
            if (up->borrowednumber == 0) return 1;
            BorrowList *lst = up->borrowbook->next;
            while (lst != NULL) {
                tmp[++ct] = (int) lst->bookid;
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

//Display book information.
void print_books(BookList res) {
    Book *p = res.list->next;
    while (p != NULL) {
        printf("================================================================\n");
        printf("book id: %d\t", p->id);
        printf("title: %s\t", p->title);
        printf("author: %s\t", p->authors);
        printf("year: %d\t", p->year);
        printf("copies: %d\n", p->copies);
        p = p->next;
    }
}

//Borrowing a book function.
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

//Check if the input is a number, if not return -1, otherwise return a number.
int get_op() {
    char *OP = NULL;
    size_t len = 0;
    getline(&OP, &len, stdin);
    int OP_flag = 1;
    for (int i = 0; i < (int) strlen(OP) - 1; ++i) {
        if (OP[i] < '0' || OP[i] > '9') {
            OP_flag = 0;
            break;
        }
    }
    if (!OP_flag || OP == NULL || strlen(OP) == 0) {
        return -1;
    }
    int res = (int) atoi(OP);
    return res;
}

//According to the user's selection, the sub-table calls three lookup functions.
int find_book(int choice, BookList *BOOKLIST) {
    if (choice == 1) {
        printf("================================================================\n");
        printf("Please input book title\n");
        char *bookTitle = NULL;
        size_t len = 0;
        getline(&bookTitle, &len, stdin);
        bookTitle[strlen(bookTitle) - 1] = '\0';
        BookList res = find_book_by_title(bookTitle, BOOKLIST);
        if (res.length == 0) {
            printf("================================================================\n");
            printf("Cannot find this book:!\n");
            return -1;
        } else {
            print_books(res);
        }
    }
    if (choice == 2) {
        printf("================================================================\n");
        printf("Please input book author\n");
        char *bookAuthor = NULL;
        size_t len = 0;
        getline(&bookAuthor, &len, stdin);
        bookAuthor[strlen(bookAuthor) - 1] = '\0';
        BookList res = find_book_by_author(bookAuthor, BOOKLIST);
        if (res.length == 0) {
            printf("================================================================\n");
            printf("Cannot find this book:!\n");
            return -1;
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
            return -1;
        }
        BookList res = find_book_by_year(year, BOOKLIST);
        if (res.length == 0) {
            printf("================================================================\n");
            printf("Cannot find this book:!\n");
            return -1;
        } else {
            print_books(res);
        }
    }
    return 0;
}

void borrow_by_id(int userid, UserList *USERLIST, BookList *BOOKLIST) {
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
        printf("Cannot find this book\n");
    }
}

//Through the function, users can borrow books by author, title, year, and id respectively.
//And display information for different situations.
void borrow(int userid, BookList *BOOKLIST, UserList *USERLIST) {
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
        borrow_by_id(userid, USERLIST, BOOKLIST);
        return;
    } else if (br_op == 2) {
        int u = find_book(1, BOOKLIST);
        if (u == -1) return;
        borrow_by_id(userid, USERLIST, BOOKLIST);
        return;
    } else if (br_op == 3) {
        int u = find_book(2, BOOKLIST);
        if (u == -1) return;
        borrow_by_id(userid, USERLIST, BOOKLIST);
        return;
    } else if (br_op == 4) {
        int u = find_book(3, BOOKLIST);
        if (u == -1) return;
        borrow_by_id(userid, USERLIST, BOOKLIST);
        return;
    }
}

//return book function
void return_(int userid, BookList *BOOKLIST, UserList *USERLIST) {
    printf("================================================================\n");
    printf("Please input book id:\n");
    int bookid = get_op();
    // printf("%d", bookid);
    if (bookid == -1 || bookid == 0) {
        printf("================================================================\n");
        printf("Invalid id!\n");
        return;
    }
    int resr = return_book(bookid, userid, BOOKLIST, USERLIST);
    if (resr == 1) printf("Successfully!\n");
    if (resr == 0) printf("You haven't borrowed this book!\n");
    if (resr == -1) printf("This book is not in library!\n");
}

//Display who has borrowed a certain book, and display user information.
void who_borrow(int bookid, BookList *BOOKLIST, UserList *USERLIST) {
    int flag = 0;
    User *p = USERLIST->list;
    while (p != NULL) {
        if (p->borrowednumber > 0) {
            int cnt = 0;
            BorrowList *brp = p->borrowbook;
            while (brp != NULL) {
                if (brp->bookid == bookid) {
                    cnt++;
                }
                brp = brp->next;
            }
            if (cnt > 0) {
                flag = 1;
                printf("================================================================\n");
                printf("userid: %d  username: %s\tnumber: %d\n", p->id, p->username, cnt);
            }
        }
        p = p->next;
    }
    if (!flag) {
        printf("================================================================\n");
        printf("No one has borrowed this book!\n");
    }
}

void edit_book(BookList *BOOKLIST) {
    printf("================================================================\n");
    printf("Please input book id:\n");
    int bookid = get_op();
    if (bookid == -1) {
        printf("================================================================\n");
        printf("Invalid id!\n");
        return;
    }
    Book *p = BOOKLIST->list;
    while (p != NULL) {
        if (p->id == bookid) {
            printf("================================================================\n");
            printf("Please input new book title:\n");
            char *title = NULL;
            size_t len = 0;
            getline(&title, &len, stdin);
            if (title == NULL) {
                printf("================================================================\n");
                printf("Invalid title!\n");
                return;
            }
            p->title = malloc(strlen(title) - 1);
            title[strlen(title) - 1] = '\0';
            p->title = strcpy(p->title, title);
            printf("================================================================\n");
            printf("Please input new book author:\n");
            char *author = NULL;
            size_t len1 = 0;
            getline(&author, &len1, stdin);
            if (author == NULL) {
                printf("================================================================\n");
                printf("Invalid author!\n");
                return;
            }
            p->authors = (char *) malloc(strlen(author) - 1);
            author[strlen(author) - 1] = '\0';
            p->authors = strcpy(p->authors, author);
            printf("================================================================\n");
            printf("Please input new book year:\n");
            int year = get_op();
            if (year == -1 || year > 2022) {
                printf("================================================================\n");
                printf("Invalid year!\n");
                return;
            }
            p->year = year;
            printf("================================================================\n");
            printf("Please input new book number:\n");
            int number = get_op();
            if (number == -1) {
                printf("================================================================\n");
                printf("Invalid number!\n");
                return;
            }
            p->copies = number;
            printf("================================================================\n");
            printf("Successfully!\n");
            return;
        }
        p = p->next;
    }
}