#ifndef BOOK_H
#define BOOK_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char name[50];
    char author[50];
    int available;
} book;

typedef struct {
    book *books;
    int count;
} library;

void addbook(library *lib);
void displeayBooks(library *lib);
void deletaBooks(library *lib, int id);

#endif