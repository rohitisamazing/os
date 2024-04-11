#include <stdio.h>
#include <stdlib.h>
int main()
{
    int queue[20], n, head, i, j, k, seek = 0, max, diff, temp, queue1[20], queue2[20], temp1 = 0, temp2 = 0;
    float avg;
    printf("Enter the max range of disk\n");
    scanf("%d", &max);
    printf("Enter the initial head position\n");
    scanf("%d", &head);
    printf("Enter the size of queue request\n");
    scanf("%d", &n);
    printf("Enter the queue of disk positions to be read\n");
    for (i = 1; i <= n; i++)
    {
        scanf("%d", &temp);
        if (temp >= head)
        {
            queue1[temp1] = temp;
            temp1++;
        }
        else
        {
            queue2[temp2] = temp;
            temp2++;
        }
    }
    for (i = 0; i < temp1 - 1; i++)
    {
        for (j = i + 1; j < temp1; j++)
        {
            if (queue1[i] > queue1[j])
            {
                temp = queue1[i];
                queue1[i] = queue1[j];
                queue1[j] = temp;
            }
        }
    }
    for (i = 0; i < temp2 - 1; i++)
    {
        for (j = i + 1; j < temp2; j++)
        {
            if (queue2[i] > queue2[j])
            {
                temp = queue2[i];
                queue2[i] = queue2[j];
                queue2[j] = temp;
            }
        }
    }
    for (i = 1, j = 0; j < temp1; i++, j++)
        queue[i] = queue1[j];
    queue[i] = max;
    queue[i + 1] = 0;
    for (i = temp1 + 3, j = 0; j < temp2; i++, j++)
        queue[i] = queue2[j];
    queue[0] = head;
    for (j = 0; j <= n + 1; j++)
    {
        diff = abs(queue[j + 1] - queue[j]);
        seek += diff;
        printf("Disk head moves from %d to %d with seek %d\n", queue[j], queue[j + 1], diff);
    }
    printf("Total seek time is %d\n", seek);
    avg = seek / (float)n;
    printf("Average seek time is %f\n", avg);
    return 0;
}


// OR YOU CAN GO WITH THE BELOW CODE AS WELL. BOTH REPRESENT THE SAME LOGIC


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

//     // logic for C-Scan disk scheduling

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
//         //  last movement for max size
//         TotalHeadMoment = TotalHeadMoment + abs(size - RQ[i - 1] - 1);
//         /*movement max to min disk */
//         TotalHeadMoment = TotalHeadMoment + abs(size - 1 - 0);
//         initial = 0;
//         for (i = 0; i < index; i++)
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
//         //  last movement for min size
//         TotalHeadMoment = TotalHeadMoment + abs(RQ[i + 1] - 0);
//         /*movement min to max disk */
//         TotalHeadMoment = TotalHeadMoment + abs(size - 1 - 0);
//         initial = size - 1;
//         for (i = n - 1; i >= index; i--)
//         {
//             TotalHeadMoment = TotalHeadMoment + abs(RQ[i] - initial);
//             initial = RQ[i];
//         }
//     }
//     printf("Total head movement is %d", TotalHeadMoment);
//     return 0;
// }
