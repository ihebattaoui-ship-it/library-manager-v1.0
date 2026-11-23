#include "book.h"

int existe(library *lib, int id) {

    int i = 0;

    while (i < lib->count) {
        if (lib->books[i].id == id) {
            return 1;
        }
        i++;
    }

    return 0;
}


void addbook(library *lib) {

    int found;

    book *temp = realloc(
        lib->books,
        (lib->count + 1) * sizeof(book)
    );

    if (temp == NULL) {
        printf("Memory allocation error!\n");
        return;
    }

    lib->books = temp;

    do {
        printf("Give the book ID:\n");
        scanf("%d", &lib->books[lib->count].id);

        found = existe(lib, lib->books[lib->count].id);

        if (found) {
            printf("This ID already exists!\n");
        }

    } while (found);

    printf("Give the book name:\n");
    scanf(" %49[^\n]", lib->books[lib->count].name);

    printf("Give the book author:\n");
    scanf(" %49[^\n]", lib->books[lib->count].author);

    lib->books[lib->count].available = 1;

    lib->count++;

    printf("Book added successfully!\n");
}


void displeayBooks(library *lib) {

    if (lib->count == 0) {
        printf("The library is empty!\n");
        return;
    }

    for (int i = 0; i < lib->count; i++) {

        printf("\nID: %d\n", lib->books[i].id);
        printf("Name: %s\n", lib->books[i].name);
        printf("Author: %s\n", lib->books[i].author);

        printf("Available: %s\n",
            lib->books[i].available ? "Yes" : "No");
    }
}


void deletaBooks(library *lib, int id) {

    int i = 0;

    while (i < lib->count && lib->books[i].id != id) {
        i++;
    }

    if (i == lib->count) {
        printf("Book doesn't exist!\n");
        return;
    }

    lib->books[i] = lib->books[lib->count - 1];

    lib->count--;

    if (lib->count == 0) {
        free(lib->books);
        lib->books = NULL;
    }
    else {
        book *temp = realloc(
            lib->books,
            lib->count * sizeof(book)
        );

        if (temp != NULL) {
            lib->books = temp;
        }
    }

    printf("Book deleted successfully!\n");
}