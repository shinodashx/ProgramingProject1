//
// Created by shinoda_shx on 24/3/2022.
//

#ifndef CWK1_UTILS_H
#define CWK1_UTILS_H

#include <stdio.h>
#include <malloc.h>
#include "book_management.h"

int borrow_book(int id, BookList *BOOKLIST);
int return_book(int id,BookList *BOOKLIST);
int min(int x,int y);
int max(int x, int y);
#endif //CWK1_UTILS_H
