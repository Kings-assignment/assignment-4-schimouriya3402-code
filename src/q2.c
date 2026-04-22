// Write a C program that reverses an array of characters using pointers.
#include <stdio.h>
void reverseArray(char *arr, int size) {
    char temp;
    for (int i = 0; i < size / 2; i++) {
        temp = arr[i];
        arr[i] = arr[size - i - 1];
        arr[size - i - 1] = temp;
    }
}
int main() {
    char str[] = "Hello, World!";
    int size = sizeof(str) - 1; // Exclude the null terminator
    printf("Original string: %s\n", str);
    reverseArray(str, size);
    printf("Reversed string: %s\n", str);
    return 0;
}
