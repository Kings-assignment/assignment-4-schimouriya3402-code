// Write a C program that defines a structure Book with members: title, author, and price. 
// Allow the user to enter details of n books and then display all books whose price is above a 
// user-defined value.
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct Book {
    char title[100];
    char author[50];
    float price;    
};
int main() {
    int n;
    printf("Enter the number of books: ");
    scanf("%d", &n);
    struct Book *books = (struct Book *)malloc(n * sizeof(struct Book));
    if (books == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }
    for (int i = 0; i < n; i++) {
        printf("Enter details for book %d:\n", i + 1);
        printf("Title: ");
        getchar();

        fgets(books[i].title, sizeof(books[i].title), stdin);
        books[i].title[strcspn(books[i].title, "\n")] =



            '\0';
        printf("Author: ");
        fgets(books[i].author, sizeof(books[i].author), stdin);

        books[i].author[strcspn(books[i].author, "\n")] = '\0';
        printf("Price: ");
        scanf("%f", &books[i].price);
    }
    float price_threshold;
    printf("Enter the price threshold: ");
    scanf("%f", &price_threshold);
    printf("\nBooks with price above %.2f:\n", price_threshold);
    for (int i = 0; i < n; i++) {
        if (books[i].price > price_threshold) {
            printf("Title: %s\n", books[i].title);
            printf("Author: %s\n", books[i].author);
            printf("Price: %.2f\n", books[i].price);
            printf("\n");
        }
    }
    free(books);
    return 0;
}