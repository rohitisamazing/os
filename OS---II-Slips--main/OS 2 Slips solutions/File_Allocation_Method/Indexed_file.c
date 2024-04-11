#include <stdio.h>
#include <stdbool.h>
#define MAX_BLOCKS 100 // Maximum number of disk blocks
#define MAX_FILES 10   // Maximum number of files

// Function to display the status of disk blocks (free/allocated)
void showBitVector(bool disk[], int n) {
    printf("Bit Vector:\n");
    for (int i = 0; i < n; ++i)
        printf("%d ", disk[i]);
    printf("\n");
}

// Function to allocate blocks for a new file
void createNewFile(bool disk[], bool index_table[], int n, int file_size) {
    printf("Allocated blocks: ");
    for (int i = 0, j = 0; i < n && j < file_size; ++i) {
        if (!disk[i]) {
            printf("%d ", i);
            disk[i] = true;
            while (index_table[j]) ++j;
            index_table[j++] = i;
        }
    }
    printf("\n");
}

// Function to display the directory (list of free blocks)
void showDirectory(bool disk[], int n) {
    printf("Free blocks: ");
    for (int i = 0; i < n; ++i)
        if (!disk[i])
            printf("%d ", i);
    printf("\n");
}

int main() {
    int n, choice, file_size;
    printf("Enter total number of disk blocks: ");
    scanf("%d", &n);
    bool disk[MAX_BLOCKS] = {false};        // Disk block status
    bool index_table[MAX_BLOCKS] = {false}; // Index table

    do {
        printf("\nMenu:\n1. Show Bit Vector\n2. Create New File\n3. Show Directory\n4. Exit\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: showBitVector(disk, n); break;
            case 2:
                printf("Enter file size: ");
                scanf("%d", &file_size);
                createNewFile(disk, index_table, n, file_size);
                break;
            case 3: showDirectory(disk, n); break;
            case 4: printf("Exiting...\n"); break;
            default: printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}