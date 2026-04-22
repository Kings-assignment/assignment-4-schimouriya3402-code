// Write a C program that copies the contents of one file to another file.
#include <stdio.h>
int main() {
    char sourceFile[100], destFile[100];
    FILE *src, *dest;
    char ch;

    printf("Enter the source file name: ");
    scanf("%s", sourceFile);

    printf("Enter the destination file name: ");
    scanf("%s", destFile);

    src = fopen(sourceFile, "r");
    if (src == NULL) {
        perror("Error opening source file");
        return 1;
    }

    dest = fopen(destFile, "w");
    if (dest == NULL) {
        perror("Error opening destination file");
        fclose(src);
        return 1;
    }

    while ((ch = fgetc(src)) != EOF) {
        fputc(ch, dest);
    }

    printf("File copied successfully.\n");

    fclose(src);
    fclose(dest);
    
    return 0;
}
