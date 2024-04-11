#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, head, total_head_movements = 0;
    char direction;

    // Input
    printf("Enter total number of disk blocks: ");
    scanf("%d", &n);

    int *requests = (int *)malloc(n * sizeof(int));

    printf("Enter the disk request string: ");
    for (int i = 0; i < n; ++i)
        scanf("%d", &requests[i]);

    printf("Enter starting head position: ");
    scanf("%d", &head);

    printf("Enter direction (L for left, R for right): ");
    scanf(" %c", &direction);

    // Sort requests in ascending order
    for (int i = 0; i < n - 1; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            if (requests[i] > requests[j])
            {
                int temp = requests[i];
                requests[i] = requests[j];
                requests[j] = temp;
            }
        }
    }

    // C-LOOK algorithm
    printf("Order of service: %d ", head);
    if (direction == 'L')
    { // Left direction
        for (int i = n - 1; i >= 0; --i)
        {
            if (requests[i] < head)
            {
                printf("%d ", requests[i]);
                total_head_movements += abs(requests[i] - head);
                head = requests[i];
            }
        }
        for (int i = n - 1; i >= 0; --i)
        {
            if (requests[i] >= head)
            {
                printf("%d ", requests[i]);
                total_head_movements += abs(requests[i] - head);
                head = requests[i];
            }
        }
    }
    else if (direction == 'R')
    { // Right direction
        for (int i = 0; i < n; ++i)
        {
            if (requests[i] > head)
            {
                printf("%d ", requests[i]);
                total_head_movements += abs(requests[i] - head);
                head = requests[i];
            }
        }
        for (int i = 0; i < n; ++i)
        {
            if (requests[i] <= head)
            {
                printf("%d ", requests[i]);
                total_head_movements += abs(requests[i] - head);
                head = requests[i];
            }
        }
    }

    // Display total number of head movements
    printf("\nTotal number of head movements: %d\n", total_head_movements);

    free(requests);
    return 0;
}