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
void user_register(int usertype, BookList *BOOKLIST, UserList  *USERLIST);
void Manager_register(BookList *BOOKLIST, UserList  *USERLIST);

int borrow_book(int bookid, int userid,BookList *BOOKLIST,UserList *USERLIST);
int return_book(int bookid, int userid, BookList *BOOKLIST,UserList *USERLIST);
int min(int x,int y);
int max(int x, int y);


void listBook(BookList *BOOKLIST);
void listUser(UserList *USERLIST);

int list_my_borrowedbook(int userid, BookList *BOOKLIST, UserList *USERLIST);
void print_books(BookList res);
void borrow_function(BookList res, int userid, BookList *BOOKLIST, UserList *USERLIST);
int get_op();

void find_book(int choice, BookList *BOOKLIST);
void borrow(int userid, BookList *BOOKLIST, UserList *USERLIST);
void return_(int userid, BookList *BOOKLIST, UserList *USERLIST);
#endif //CWK1_UTILS_H
