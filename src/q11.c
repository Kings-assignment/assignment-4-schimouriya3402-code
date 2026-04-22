// Write a C program to create a file and write a user-entered string into it. Then display a 
// message confirming that the file has been written successfully.

#include <stdio.h>
int main() {
    char filename[100];
    char content[1000];
    FILE *file; 
    printf("Enter the filename: ");
    scanf("%s", filename);
    printf("Enter the content to write to the file: ");
    scanf(" %[^\n]s", content);
    file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error opening file!\n");
        return 1;
    }
    fprintf(file, "%s\n", content);
    fclose(file);
    printf("File has been written successfully.\n");
    return 0;
}