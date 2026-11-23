#include <stdio.h>
#include <stdlib.h>

#include "book manager\book.h"
#include "Search and borrowing\search.h"

int main() {

    library lib = {NULL, 0};


    int choice;

    do {
        printf("\n========== LIBRARY MANAGER ==========\n");
        printf("1. Add a book\n");
        printf("2. Display all books\n");
        printf("3. Search for a book by ID\n");
        printf("4. Search for a book by title\n");
        printf("5. Delete a book\n");
        printf("6. Borrow a book\n");
        printf("7. Return a book\n");
        printf("0. Exit\n");
        printf("=====================================\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                addbook(&lib);
                break;

            case 2:
                displeayBooks(&lib);
                break;

            case 3: {
                int id, pos;

                printf("Enter book ID: ");
                scanf("%d", &id);

                pos = searchByID(&lib, id);

                if (pos == -1)
                    printf("Book not found!\n");
                else {
                    printf("ID: %d\n", lib.books[pos].id);
                    printf("Name: %s\n", lib.books[pos].name);
                    printf("Author: %s\n", lib.books[pos].author);
                    printf("Available: %s\n",
                        lib.books[pos].available ? "Yes" : "No");
                }
                break;
            }

            case 4: {
                char title[50];
                int pos;

                printf("Enter book title: ");
                scanf(" %49[^\n]", title);

                pos = searchByTitle(&lib, title);

                if (pos == -1)
                    printf("Book not found!\n");
                else {
                    printf("Book found: %s\n", lib.books[pos].name);
                    printf("Author: %s\n", lib.books[pos].author);
                }
                break;
            }

            case 5: {
                int id;

                printf("Enter book ID to delete: ");
                scanf("%d", &id);

                deletaBooks(&lib, id);
                break;
            }

            case 6:
                borrowBook(&lib);
                break;

            case 7:
                returnBook(&lib);
                break;

            case 0:
                printf("Closing library...\n");
                break;

            default:
                printf("Invalid choice!\n");
        }

    } while (choice != 0);

    free(lib.books);

    return 0;
}