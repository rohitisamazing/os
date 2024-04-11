#include <stdio.h>
#include <stdlib.h>

// Function to calculate total head movements
int totalHeadMovements(int *requests, int n, int head)
{
    int total = 0;
    for (int i = 0; i < n; ++i)
    {
        total += abs(head - requests[i]);
        head = requests[i];
    }
    return total;
}

// LOOK disk scheduling algorithm
void LOOK(int *requests, int n, int head, char direction)
{
    printf("Order of service: %d ", head);
    if (direction == 'L')
    { // Left direction
        for (int i = n - 1; i >= 0; --i)
            printf("%d ", requests[i]);
    }
    else if (direction == 'R')
    { // Right direction
        for (int i = 0; i < n; ++i)
            printf("%d ", requests[i]);
    }
    printf("\nTotal number of head movements: %d\n", totalHeadMovements(requests, n, head));
}

int main()
{
    int n, head, *requests;
    char direction;

    printf("Enter total number of disk blocks: ");
    scanf("%d", &n);

    requests = (int *)malloc(n * sizeof(int));

    printf("Enter the disk request string: ");
    for (int i = 0; i < n; ++i)
        scanf("%d", &requests[i]);

    printf("Enter starting head position: ");
    scanf("%d", &head);

    printf("Enter direction (L for left, R for right): ");
    scanf(" %c", &direction);

    LOOK(requests, n, head, direction);

    free(requests);
    return 0;
}

// #include <stdio.h>
// #include <stdlib.h>
// int main()
// {
//     int RQ[100], i, j, n, TotalHeadMoment = 0, initial, size, move;
//     printf("Enter the number of Requests\n");
//     scanf("%d", &n);
//     printf("Enter the Requests sequence\n");
//     for (i = 0; i < n; i++)
//         scanf("%d", &RQ[i]);
//     printf("Enter initial head position\n");
//     scanf("%d", &initial);
//     printf("Enter total disk size\n");
//     scanf("%d", &size);
//     printf("Enter the head movement direction for high 1 and for low 0\n");
//     scanf("%d", &move);

//     // logic for look disk scheduling

//     /*logic for sort the request array */
//     for (i = 0; i < n; i++)
//     {
//         for (j = 0; j < n - i - 1; j++)
//         {
//             if (RQ[j] > RQ[j + 1])
//             {
//                 int temp;
//                 temp = RQ[j];
//                 RQ[j] = RQ[j + 1];
//                 RQ[j + 1] = temp;
//             }
//         }
//     }

//     int index;
//     for (i = 0; i < n; i++)
//     {
//         if (initial < RQ[i])
//         {
//             index = i;
//             break;
//         }
//     }

//     // if movement is towards high value
//     if (move == 1)
//     {
//         for (i = index; i < n; i++)
//         {
//             TotalHeadMoment = TotalHeadMoment + abs(RQ[i] - initial);
//             initial = RQ[i];
//         }

//         for (i = index - 1; i >= 0; i--)
//         {
//             TotalHeadMoment = TotalHeadMoment + abs(RQ[i] - initial);
//             initial = RQ[i];
//         }
//     }
//     // if movement is towards low value
//     else
//     {
//         for (i = index - 1; i >= 0; i--)
//         {
//             TotalHeadMoment = TotalHeadMoment + abs(RQ[i] - initial);
//             initial = RQ[i];
//         }

//         for (i = index; i < n; i++)
//         {
//             TotalHeadMoment = TotalHeadMoment + abs(RQ[i] - initial);
//             initial = RQ[i];
//         }
//     }

//     printf("Total head movement is %d", TotalHeadMoment);
//     return 0;
// }