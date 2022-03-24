#include <stdio.h>
#include <malloc.h>
#include "book_management.h"
#include "run_interface.h"

int main() {
    BookList *BOOKLIST = (BookList *) malloc(sizeof (BookList));
    UserList *USERLIST = (UserList *) malloc(sizeof (UserList));
    load_file(BOOKLIST,USERLIST);
//    listBook(BOOKLIST);
    run_interface(BOOKLIST, USERLIST);
//    write_file();
    return 0;
}

