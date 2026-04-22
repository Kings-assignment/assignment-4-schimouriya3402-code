// Write a C program that stores student records (name, roll number, and marks) into a 
// file and then reads and displays all stored records.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
#define MAX_NAME_LEN  50
#define FILE_NAME     "students.dat"
 
// ── Data Structure ──────────────────────────────────────────
typedef struct {
    int  rollNumber;
    char name[MAX_NAME_LEN];
    float marks;
} Student;
 
// ── Function Prototypes ──────────────────────────────────────
void  addStudents();
void  displayAllRecords();
void  printDivider();
 
// ── Main ─────────────────────────────────────────────────────
int main() {
    int choice;
 
    printf("\n╔══════════════════════════════════════╗\n");
    printf(  "║   STUDENT RECORD MANAGEMENT SYSTEM   ║\n");
    printf(  "╚══════════════════════════════════════╝\n");
 
    do {
        printf("\n  1. Add Student Records\n");
        printf(  "  2. Display All Records\n");
        printf(  "  3. Exit\n");
        printf(  "\n  Enter your choice: ");
        scanf("%d", &choice);
 
        switch (choice) {
            case 1: addStudents();        break;
            case 2: displayAllRecords();  break;
            case 3: printf("\n  Goodbye!\n\n"); break;
            default: printf("\n  [!] Invalid choice. Try again.\n");
        }
    } while (choice != 3);
 
    return 0;
}
 
// ── Add Student Records to File ──────────────────────────────
void addStudents() {
    FILE    *fp;
    Student  s;
    int      n, i;
 
    printf("\n  How many students to add? ");
    scanf("%d", &n);
 
    // Open in append-binary mode so existing records are preserved
    fp = fopen(FILE_NAME, "ab");
    if (fp == NULL) {
        printf("  [!] Error: Could not open file for writing.\n");
        return;
    }
 
    for (i = 0; i < n; i++) {
        printf("\n  --- Student %d ---\n", i + 1);
 
        printf("  Roll Number : ");
        scanf("%d", &s.rollNumber);
 
        printf("  Name        : ");
        scanf(" %49[^\n]", s.name);   // reads full name with spaces
 
        printf("  Marks       : ");
        scanf("%f", &s.marks);
 
        fwrite(&s, sizeof(Student), 1, fp);
    }
 
    fclose(fp);
    printf("\n  [✓] %d record(s) saved to \"%s\".\n", n, FILE_NAME);
}
 
// ── Display All Records from File ────────────────────────────
void displayAllRecords() {
    FILE    *fp;
    Student  s;
    int      count = 0;
 
    fp = fopen(FILE_NAME, "rb");
    if (fp == NULL) {
        printf("\n  [!] No records found. Add students first.\n");
        return;
    }
 
    printf("\n");
    printDivider();
    printf("  %-6s  %-25s  %-8s\n", "Roll", "Name", "Marks");
    printDivider();
 
    while (fread(&s, sizeof(Student), 1, fp) == 1) {
        printf("  %-6d  %-25s  %-8.2f\n",
               s.rollNumber, s.name, s.marks);
        count++;
    }
 
    if (count == 0) {
        printf("  (no records in file)\n");
    } else {
        printDivider();
        printf("  Total records: %d\n", count);
    }
 
    fclose(fp);
}
 
// ── Utility: Print a divider line ────────────────────────────
void printDivider() {
    printf("  %-45s\n", "---------------------------------------------");
}
 