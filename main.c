#include <stdio.h>
#include <lmaccess.h>
#include <malloc.h>
#include "book_management.h"
#include "run_interface.h"


void load_file(BookList *BOOKLIST, UserList *USERLIST);

int main() {

    BookList BOOKLIST = *(BookList *) malloc(sizeof (BookList));
    UserList USERLIST = *(UserList *) malloc(sizeof (UserList));
    load_file(&BOOKLIST,&USERLIST);
    run_interface(BOOKLIST, USERLIST);

    write_file();
    return 0;
}

void load_file(BookList *pList, UserList *pList1) {

}
