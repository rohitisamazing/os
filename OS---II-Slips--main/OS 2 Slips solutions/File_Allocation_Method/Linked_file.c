#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#define MAX_BLOCKS 100 // Maximum number of disk blocks

// Function to display the status of disk blocks (free/allocated)
void showBitVector(bool disk[], int n)
{
    printf("Bit Vector:\n");
    for (int i = 0; i < n; ++i)
    {
        if (disk[i])
            printf("1 ");
        else
            printf("0 ");
    }
    printf("\n");
}

// Function to allocate blocks for a new file
void createNewFile(bool disk[], int n, int file_size)
{
    printf("Allocated blocks: ");
    int allocated_blocks = 0;
    for (int i = 0; i < n && allocated_blocks < file_size; ++i)
    {
        if (!disk[i])
        {
            printf("%d ", i);
            disk[i] = true;
            allocated_blocks++;
        }
    }
    printf("\n");
}

// Function to display the directory (list of free blocks)
void showDirectory(bool disk[], int n)
{
    printf("Free blocks: ");
    for (int i = 0; i < n; ++i)
    {
        if (!disk[i])
            printf("%d ", i);
    }
    printf("\n");
}

int main()
{
    int n, choice, file_size;
    bool disk[MAX_BLOCKS] = {false}; // Array to represent disk blocks

    // Input
    printf("Enter total number of disk blocks: ");
    scanf("%d", &n);

    // Menu
    do
    {
        printf("\nMenu:\n");
        printf("1. Show Bit Vector\n");
        printf("2. Create New File\n");
        printf("3. Show Directory\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            showBitVector(disk, n);
            break;
        case 2:
            printf("Enter file size: ");
            scanf("%d", &file_size);
            createNewFile(disk, n, file_size);
            break;
        case 3:
            showDirectory(disk, n);
            break;
        case 4:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}