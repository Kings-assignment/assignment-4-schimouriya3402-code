// Write a C program that dynamically allocates memory for a string entered by the user and finds its length using pointers.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main() {
    char *str;
    int length;

    printf("Enter a string: ");
    str = (char *)malloc(100 * sizeof(char)); 
    if (str == NULL) {
        printf("Memory allocation failed\n");
        return 1; 
    }
    fgets(str, 100, stdin); 

    
    str[strcspn(str, "\n")] = '\0';

    
    char *ptr = str;
    length = 0;
    while (*ptr != '\0') {
        length++;
        ptr++;
    }

 
    printf("The length of the string is: %d\n", length);

    
    free(str);
    return 0;
}