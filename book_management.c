#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>
#include "book_management.h"
#include "utils.h"


int BookNum;
int UserNum;

//Read the information from the book file and store it in the linked list
int load_books(FILE *file, BookList *BOOKLIST) {
    if (file == NULL) {
        return 1;
    }
    Book *BookHead = (Book *) malloc(sizeof(Book));
    BOOKLIST->list = BookHead;
    BookHead->next = NULL;
    BOOKLIST->length = 0;
    char booknum[100];
    int bookNum = 0;
    while (fscanf(file, "%s\n", booknum) != EOF) {
        int cnt = 0;
        for (int i = 0; i < (int) strlen(booknum) - 1; ++i) {
            if (booknum[i] > '9' || booknum[i] < '0') {
                cnt++;
            }
        }
        if (cnt == 0 || booknum[0] == '\n') break;
        else {
            printf("Book data error!\n");
            exit(0);
        }
    }
    bookNum = (int) atoi(booknum);
    BookNum = 0;
    if (bookNum != 0) {
        for (int i = 1; i <= bookNum; ++i) {
            BookNum++;
            Book *now;
            Book *last;
            last = BOOKLIST->list;
            while (last->next != NULL) last = last->next;
            now = (Book *) malloc(sizeof(Book));
            char *str = malloc(sizeof 40960);
            fgets(str, 40960, file);
            int ct = 0;
            char u[1000];
            if (str == NULL) {
                printf("Book data error!\n");
                exit(0);
            }
            for (int j = 0; j < strlen(str); ++j) {
                u[j] = str[j];
                if (u[j] == '-') ct++;
            }
            if (ct < 5) {
                printf("Book data error!\n");
                exit(0);
            }
            char *x;
            x = strtok(str, "-");
            if (x == NULL || x == "" || x[0] == '\n' || x[0] == '\0') {
                printf("Book data error!\n");
                exit(0);
            }
            now->id = (int) atoi(x);
            x = strtok(NULL, "-");
            if (x == NULL || x == "" || x[0] == '\n' || x[0] == '\0') {
                printf("Book data error!\n");
                exit(0);
            }
            now->title = malloc(strlen(x) + 1);
            now->title = x;
            now->title[strlen(x)] = '\0';
            x = strtok(NULL, "-");
            if (x == NULL || x == "" || x[0] == '\n' || x[0] == '\0') {
                printf("Book data error!\n");
                exit(0);
            }
            now->authors = malloc(strlen(x) + 1);
            now->authors = x;
            now->authors[strlen(x)] = '\0';
            x = strtok(NULL, "-");
            if (x == NULL || x == "" || x[0] == '\n' || x[0] == '\0') {
                printf("Book data error!\n");
                exit(0);
            }
            now->year = atoi(x);
            x = strtok(NULL, "-");
            if (x == NULL || x == "" || x[0] == '\n' || x[0] == '\0') {
                printf("Book data error!\n");
                exit(0);
            }
            now->copies = atoi(x);
            x = strtok(NULL, "-");
            if (x == NULL || x == "" || x[0] == '\n' || x[0] == '\0') {
                printf("Book data error!\n");
                exit(0);
            }
            now->borrowed = (int) atoi(x);
            now->next = NULL;
            last->next = now;
        }
        BOOKLIST->length = bookNum;
    }
    return 0;
}

//Read the information from the user file and store it in the linked list
int load_users(FILE *file, UserList *USERLIST) {
    if (file == NULL) return 1;
    User *UserHead = (User *) malloc(sizeof(User));
    UserHead->next = NULL;
    USERLIST->list = UserHead;
    USERLIST->length = 0;
    char usernum[100];
    int userNum = 0;
    while (fscanf(file, "%s\n", usernum) != EOF) {
        int cnt = 0;
        for (int i = 0; i < (int) strlen(usernum) - 1; ++i) {
            if (usernum[i] > '9' || usernum[i] < '0') {
                cnt++;
            }
        }
        if (cnt == 0 || usernum[0] == '\n') break;
        else {
            printf("Book data error!\n");
            exit(0);
        }
    }
    userNum = (int) atoi(usernum);
    BookNum = 0;
    for (int i = 1; i <= userNum; ++i) {
        UserNum++;
        User *now;
        User *last;
        last = USERLIST->list;
        while (last->next != NULL) last = last->next;
        now = (User *) malloc(sizeof(User));
        char *str = malloc(sizeof(1000));
        fgets(str, 40960, file);
        if (str == NULL) {
            printf("User data error!\n");
            exit(0);
        }
        char *x;
        x = strtok(str, "-");
        if (x == NULL || x == "" || x[0] == '\n' || x[0] == '\0') {
            printf("User data error!\n");
            exit(0);
        }
        now->id = (int) atoi(x);
        x = strtok(NULL, "-");
        if (x == NULL || x == "" || x[0] == '\n' || x[0] == '\0') {
            printf("User data error!\n");
            exit(0);
        }
        now->userType = (int) atoi(x);
        x = strtok(NULL, "-");
        if (x == NULL || x == "" || x[0] == '\n' || x[0] == '\0') {
            printf("User data error!\n");
            exit(0);
        }
        now->username = malloc(strlen(x) + 1);
        now->username = x;
        now->username[strlen(x)] = '\0';
        x = strtok(NULL, "-");
        if (x == NULL || x == "" || x[0] == '\n' || x[0] == '\0') {
            printf("User data error!\n");
            exit(0);
        }
        now->password = malloc(strlen(x) + 1);
        now->password = x;
        now->password[strlen(x)] = '\0';
        x = strtok(NULL, "-");
        if (x == NULL || x == "" || x[0] == '\n' || x[0] == '\0') {
            printf("User data error!\n");
            exit(0);
        }
        now->borrowednumber = (int) atoi(x);
        BorrowList *borrowHead = (BorrowList *) malloc(sizeof(BorrowList));
        borrowHead->next = NULL;
        BorrowList *lst = borrowHead;
        while (lst->next != NULL) lst = lst->next;
        if ((int) now->borrowednumber != 0) {
            for (int j = 1; j <= (int) now->borrowednumber; ++j) {
                char *xxc = malloc(sizeof 40960);
                fgets(xxc, 40960, file);
                xxc[strlen(xxc) - 1] = '\0';
                for (int k = 0; k < strlen(xxc); ++k) {
                    if (xxc[k] > '9' || xxc[k] < '0') {
                        printf("User data error!\n");
                        exit(0);
                    }
                }
                int xx = atoi(xxc);
                BorrowList *tmp = (BorrowList *) malloc(sizeof(BorrowList));
                tmp->bookid = xx;
                tmp->next = NULL;
                lst->next = tmp;
                lst = lst->next;
            }
        }
        now->borrowbook = borrowHead;
        now->next = NULL;
        last->next = now;
    }
    USERLIST->length = userNum;
    return 0;
}

void load_file(char *BookFile, char *UserFile, BookList *BOOKLIST, UserList *USERLIST) {

    FILE *Book_File = fopen(BookFile, "r");
    int res = load_books(Book_File, BOOKLIST);
    if (res == 1) {
        printf("Error!\nLibrary Data does exist: %s\n", BookFile);
        exit(0);
    }

    FILE *User_File = fopen(UserFile, "r");
    load_users(User_File, USERLIST);
    if (res == 1) {
        printf("Error\nLibrary Data does exist: %s\n", UserFile);
        exit(0);
    }
    fclose(Book_File);
    fclose(User_File);
}

//Save book information from linked list into txt file
int store_books(FILE *file, BookList *BOOKLIST) {
    if (file == NULL) {
        return 1;
    }
    fprintf(file, "%d\n", (int) BOOKLIST->length);
    Book *bp = BOOKLIST->list;
    bp = bp->next;
    while (bp != NULL) {
        fprintf(file, "%d-", bp->id);
        fprintf(file, "%s-", bp->title);
        fprintf(file, "%s-", bp->authors);
        fprintf(file, "%d-", bp->year);
        fprintf(file, "%d-", bp->copies);
        fprintf(file, "%d-\n", bp->borrowed);

        bp = bp->next;
    }
    return 0;
}

//Save book information from linked list into txt file
int store_users(FILE *file, UserList *USERLIST) {
    if (file == NULL) return 1;
    fprintf(file, "%d\n", (int) USERLIST->length);
    User *up = USERLIST->list;
    up = up->next;
    while (up != NULL) {
        fprintf(file, "%d-", up->id);
        fprintf(file, "%d-", up->userType);
        fprintf(file, "%s-", up->username);
        fprintf(file, "%s-", up->password);
        fprintf(file, "%d-\n", up->borrowednumber);
        if (up->borrowednumber != 0) {
            BorrowList *brp = up->borrowbook->next;
            while (brp != NULL) {
                fprintf(file, "%d\n", brp->bookid);
                brp = brp->next;
            }
        }
        up = up->next;
    }
    return 0;
}

void store_file(char *BookFile, char *UserFile, BookList *BOOKLIST, UserList *USERLIST) {
    FILE *Book_File = fopen(BookFile, "w");
    int resb = store_books(Book_File, BOOKLIST);
    if (resb == 1) {
        printf("==========================================\n");
        printf("Cannot find this file: %s\n", Book_File);
    }
    FILE *User_File = fopen(UserFile, "w");
    int resu = store_users(User_File, USERLIST);
    if (resu == 1) {
        printf("==========================================\n");
        printf("Cannot find this file: %s\n", User_File);
    }
    fclose(Book_File);
    fclose(User_File);
}

BookList find_book_by_author(const char *author, BookList *BOOKLIST) {
    BookList res;
    res.length = 0;
    Book *head = (Book *) malloc(sizeof(Book));
    head->next = NULL;
    res.list = head;
    Book *p = BOOKLIST->list->next;
    while (p != NULL) {
        int flag = 1;
        if ((int) strlen(author) != (int) (strlen(p->authors))) flag = 0;
        for (int i = 0; i <= min((int) strlen(author), (int) strlen(p->authors)); ++i) {
            if (author[i] != p->authors[i]) {
                flag = 0;
                break;
            }
        }
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

BookList find_book_by_title(const char *title, BookList *BOOKLIST) {
    BookList res;
    res.length = 0;
    Book *head = (Book *) malloc(sizeof(Book));
    head->next = NULL;
    res.list = head;
    Book *p = BOOKLIST->list->next;
    while (p != NULL) {
        int flag = 1;
        if ((int) strlen(title) != (int) (strlen(p->title))) flag = 0;
        for (int i = 0; i <= min((int) strlen(title), (int) strlen(p->title)); ++i) {
            if (title[i] != p->title[i]) {
                flag = 0;
                break;
            }
        }
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
    res.list = NULL;
    return res;
}

BookList find_book_by_id(unsigned int id, BookList *BOOKLIST) {
    BookList res;
    res.length = 0;
    Book *head = (Book *) malloc(sizeof(Book));
    head->next = NULL;
    res.list = head;

    Book *p = BOOKLIST->list;
    while (p != NULL) {
        int flag = 0;
        if ((int) id == (int) p->id) flag = 1;
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

int remove_book(Book book, BookList *BOOKLIST) {
    int id = (int) book.id;
    if (id == -1) return -1;
    if ((int) book.borrowed == 1) return 1;
    Book *p;
    p = BOOKLIST->list;
    while (p != NULL) {
        if (p->next->id == id) {
            p->next = p->next->next;
            return 0;
        }
        p = p->next;
    }
}

int add_book(Book book, BookList *BOOKLIST) {

    Book *cp = BOOKLIST->list->next;
    while (cp != NULL) {
        if (cmp_char(cp->authors, book.authors) == 1 && cmp_char(cp->title, book.title) == 1 && cp->year == book.year) {
            cp->copies = cp->copies + book.copies;
            return 0;
        }
        cp = cp->next;
    }
    if (book.year > 2022) return 1;
    Book *now = (Book *) malloc(sizeof(Book));
    Book *last;
    now->title = book.title;
    now->authors = book.authors;
    now->year = book.year;
    now->copies = book.copies;
    now->borrowed = 0;
    BOOKLIST->length = BOOKLIST->length + 1;
    last = BOOKLIST->list;
    while (last->next != NULL) last = last->next;
    now->id = last->id + 1;
    now->next = NULL;
    last->next = now;
    return 0;
}
