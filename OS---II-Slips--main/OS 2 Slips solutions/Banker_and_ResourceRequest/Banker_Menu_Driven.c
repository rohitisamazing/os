#include <stdio.h>

#define MAX_PROCESSES 5
#define MAX_RESOURCES 3

int main()
{
    int available[MAX_RESOURCES] = {7, 2, 6};
    int allocation[MAX_PROCESSES][MAX_RESOURCES];
    int max[MAX_PROCESSES][MAX_RESOURCES];
    int need[MAX_PROCESSES][MAX_RESOURCES];

    // Menu
    char choice;
    do
    {
        printf("\nMenu:\n");
        printf("a) Accept Allocation\n");
        printf("b) Display Allocation, Max\n");
        printf("c) Find Need and display It\n");
        printf("d) Display Available\n");
        printf("e) Exit\n");
        printf("Enter your choice: ");
        scanf(" %c", &choice);

        switch (choice)
        {
        case 'a':
            // Accept allocation matrix
            printf("Enter allocation matrix:\n");
            for (int i = 0; i < MAX_PROCESSES; ++i)
            {
                for (int j = 0; j < MAX_RESOURCES; ++j)
                {
                    scanf("%d", &allocation[i][j]);
                }
            }
            break;
        case 'b':
            // Display allocation and max matrices
            printf("\nAllocation Matrix:\n");
            for (int i = 0; i < MAX_PROCESSES; ++i)
            {
                for (int j = 0; j < MAX_RESOURCES; ++j)
                {
                    printf("%d ", allocation[i][j]);
                }
                printf("\n");
            }
            printf("\nMax Matrix:\n");
            for (int i = 0; i < MAX_PROCESSES; ++i)
            {
                for (int j = 0; j < MAX_RESOURCES; ++j)
                {
                    scanf("%d", &max[i][j]);
                }
            }
            break;
        case 'c':
            // Calculate and display the need matrix
            printf("\nNeed matrix:\n");
            for (int i = 0; i < MAX_PROCESSES; ++i)
            {
                for (int j = 0; j < MAX_RESOURCES; ++j)
                {
                    need[i][j] = max[i][j] - allocation[i][j];
                    printf("%d ", need[i][j]);
                }
                printf("\n");
            }
            break;
        case 'd':
            // Display available resources
            printf("\nAvailable resources: ");
            for (int i = 0; i < MAX_RESOURCES; ++i)
            {
                printf("%d ", available[i]);
            }
            printf("\n");
            break;
        case 'e':
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 'e');

    return 0;
}