#ifndef SEARCH_H
#define SEARCH_H

#include "C:\Users\Lenovo-PC\Desktop\ttttttt\cs\c\library manager\book manager\book.h"

int searchByID(library *lib, int id);
int searchByTitle(library *lib, char title[]);

void borrowBook(library *lib);
void returnBook(library *lib);

#endif