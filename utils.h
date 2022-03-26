//
// Created by shinoda_shx on 24/3/2022.
//

#ifndef CWK1_UTILS_H
#define CWK1_UTILS_H

#include <stdio.h>
#include <malloc.h>
#include "book_management.h"

int check_username(char *username, UserList *USERLIST);
int check_user_id(char *username, UserList *USERLIST);
void User_register(BookList *BOOKLIST, UserList  *USERLIST);
void Manager_register(BookList *BOOKLIST, UserList  *USERLIST);

int borrow_book(int bookid, int userid,BookList *BOOKLIST,UserList *USERLIST);
int return_book(int id,BookList *BOOKLIST);
int min(int x,int y);
int max(int x, int y);


void listBook(BookList *BOOKLIST);
void listUser(UserList *USERLIST);
#endif //CWK1_UTILS_H
