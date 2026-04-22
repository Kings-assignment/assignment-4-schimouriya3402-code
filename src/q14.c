// Write a C program that counts the number of characters, words, and lines in a text file.

#include <stdio.h>
#include <stdlib.h>

int main() {
    char filename[100];
    printf("Enter the filename to read: ");
    scanf("%s", filename);

    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    int char_count = 0, word_count = 0, line_count = 0;
    char ch;
    while ((ch = fgetc(file)) != EOF) {
        char_count++;
        if (ch == ' ' || ch == '\n' || ch == '\t') {
            word_count++;
        }
        if (ch == '\n') {
            line_count++;
        }
    }

    // If the file is not empty, count the last word and line
    if (char_count > 0) {
        word_count++;
        line_count++;
    }

    printf("\nNumber of characters: %d\n", char_count);
    printf("Number of words: %d\n", word_count);
    printf("Number of lines: %d\n", line_count);

    fclose(file);
    return EXIT_SUCCESS;
}