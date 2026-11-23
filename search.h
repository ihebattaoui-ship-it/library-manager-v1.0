#ifndef SEARCH_H
#define SEARCH_H

#include "book.h"

int searchByID(library *lib, int id);
int searchByTitle(library *lib, char title[]);

void borrowBook(library *lib);
void returnBook(library *lib);

#endif
