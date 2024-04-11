#include <stdio.h>
#include <stdbool.h>

#define MAX_PROCESSES 5
#define MAX_RESOURCES 4

int main()
{
    int available[MAX_RESOURCES];
    int max[MAX_PROCESSES][MAX_RESOURCES];
    int allocation[MAX_PROCESSES][MAX_RESOURCES];
    int need[MAX_PROCESSES][MAX_RESOURCES];

    // Input for available resources
    printf("Enter available resources: ");
    for (int i = 0; i < MAX_RESOURCES; ++i)
    {
        scanf("%d", &available[i]);
    }

    // Input for maximum matrix
    printf("Enter maximum matrix:\n");
    for (int i = 0; i < MAX_PROCESSES; ++i)
    {
        for (int j = 0; j < MAX_RESOURCES; ++j)
        {
            scanf("%d", &max[i][j]);
        }
    }

    // Input for allocation matrix
    printf("Enter allocation matrix:\n");
    for (int i = 0; i < MAX_PROCESSES; ++i)
    {
        for (int j = 0; j < MAX_RESOURCES; ++j)
        {
            scanf("%d", &allocation[i][j]);
        }
    }

    // Calculate and display the need matrix
    printf("Need matrix:\n");
    for (int i = 0; i < MAX_PROCESSES; ++i)
    {
        for (int j = 0; j < MAX_RESOURCES; ++j)
        {
            need[i][j] = max[i][j] - allocation[i][j];
            printf("%d ", need[i][j]);
        }
        printf("\n");
    }

    // Check if the system is in a safe state
    bool finish[MAX_PROCESSES] = {false};
    int work[MAX_RESOURCES];
    int safeSequence[MAX_PROCESSES];
    int count = 0;

    // Initialize work as available
    for (int i = 0; i < MAX_RESOURCES; ++i)
    {
        work[i] = available[i];
    }

    // Find a process which can be allocated resources
    while (count < MAX_PROCESSES)
    {
        bool found = false;
        for (int i = 0; i < MAX_PROCESSES; ++i)
        {
            if (!finish[i])
            {
                bool canAllocate = true;
                for (int j = 0; j < MAX_RESOURCES; ++j)
                {
                    if (need[i][j] > work[j])
                    {
                        canAllocate = false;
                        break;
                    }
                }
                if (canAllocate)
                {
                    for (int j = 0; j < MAX_RESOURCES; ++j)
                    {
                        work[j] += allocation[i][j];
                    }
                    safeSequence[count++] = i;
                    finish[i] = true;
                    found = true;
                }
            }
        }
        // If no process can be allocated resources, system is not in a safe state
        if (!found)
        {
            printf("System is not in a safe state.\n");
            return 0;
        }
    }

    // If all processes are allocated resources, system is in a safe state
    printf("System is in a safe state.\nSafe sequence: ");
    for (int i = 0; i < MAX_PROCESSES; ++i)
    {
        printf("%d ", safeSequence[i]);
    }
    printf("\n");

    return 0;
}