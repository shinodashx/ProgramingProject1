#include <stdio.h>
#include <malloc.h>
#include "book_management.h"
#include "run_interface.h"

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <BookFile> <UserFile>\n", argv[0]);
    }
    char *BookFile = argv[1];
    char *UserFile = argv[2];
    // char BookFile[20] = "BookFile.txt";
    // char UserFile[20] = "UserFile.txt";

    BookList *BOOKLIST = (BookList *) malloc(sizeof(BookList));
    UserList *USERLIST = (UserList *) malloc(sizeof(UserList));

    load_file(BookFile, UserFile, BOOKLIST, USERLIST);
    run_interface(BookFile, UserFile, BOOKLIST, USERLIST);

    free(BOOKLIST);
    free(USERLIST);

    return 0;
}

