#include "search.h"

int searchByID(library *lib, int id) {

    for (int i = 0; i < lib->count; i++) {
        if (lib->books[i].id == id) {
            return i;
        }
    }

    return -1;
}


int searchByTitle(library *lib, char title[]) {

    for (int i = 0; i < lib->count; i++) {
        if (strcmp(lib->books[i].name, title) == 0) {
            return i;
        }
    }

    return -1;
}


void borrowBook(library *lib) {

    int id, pos;

    printf("Enter book ID to borrow: ");
    scanf("%d", &id);

    pos = searchByID(lib, id);

    if (pos == -1) {
        printf("Book doesn't exist!\n");
    }
    else if (lib->books[pos].available == 0) {
        printf("This book is already borrowed!\n");
    }
    else {
        lib->books[pos].available = 0;
        printf("Book borrowed successfully!\n");
    }
}


void returnBook(library *lib) {

    int id, pos;

    printf("Enter book ID to return: ");
    scanf("%d", &id);

    pos = searchByID(lib, id);

    if (pos == -1) {
        printf("Book doesn't exist!\n");
    }
    else if (lib->books[pos].available == 1) {
        printf("This book is already available!\n");
    }
    else {
        lib->books[pos].available = 1;
        printf("Book returned successfully!\n");
    }
}