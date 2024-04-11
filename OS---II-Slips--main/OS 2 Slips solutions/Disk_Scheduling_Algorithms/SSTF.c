#include <stdio.h>
#include <stdlib.h>
int main()
{
    int RQ[100], i, n, TotalHeadMoment = 0, initial, count = 0;
    printf("Enter the number of Requests\n");
    scanf("%d", &n);
    printf("Enter the Requests sequence\n");
    for (i = 0; i < n; i++)
        scanf("%d", &RQ[i]);
    printf("Enter initial head position\n");
    scanf("%d", &initial);

    // logic for sstf disk scheduling

    /* loop will execute until all process is completed*/
    while (count != n)
    {
        int min = 1000, d, index;
        for (i = 0; i < n; i++)
        {
            d = abs(RQ[i] - initial);
            if (min > d)
            {
                min = d;
                index = i;
            }
        }
        TotalHeadMoment = TotalHeadMoment + min;
        initial = RQ[index];
        // 1000 is for max
        // you can use any number
        RQ[index] = 1000;
        count++;
    }

    printf("Total head movement is %d", TotalHeadMoment);
    return 0;
}

// OR YOU CAN GO WITH THE BELOW CODE AS WELL. BOTH REPRESENT THE SAME LOGIC

// #include <math.h>
// #include <stdio.h>
// #include <stdlib.h>
// int main()
// {
//     int i, n, k, req[50], mov = 0, cp, index[50], min, a[50], j = 0, mini, cp1;
//     printf("enter the current position\n");
//     scanf("%d", &cp);
//     printf("enter the number of requests\n");
//     scanf("%d", &n);
//     cp1 = cp;
//     printf("enter the request order\n");
//     for (i = 0; i < n; i++)
//     {
//         scanf("%d", &req[i]);
//     }
//     for (k = 0; k < n; k++)
//     {
//         for (i = 0; i < n; i++)
//         {
//             index[i] = abs(cp - req[i]); // calculate distance of each request from current position
//         }
//         // to find the nearest request
//         min = index[0];
//         mini = 0;
//         for (i = 1; i < n; i++)
//         {
//             if (min > index[i])
//             {
//                 min = index[i];
//                 mini = i;
//             }
//         }
//         a[j] = req[mini];
//         j++;
//         cp = req[mini]; // change the current position value to next request
//         req[mini] = 999;
//     } // the request that is processed its value is changed so that it is not processed again
//     printf("Sequence is : ");
//     printf("%d", cp1);
//     mov = mov + abs(cp1 - a[0]); // head movement
//     printf(" -> %d", a[0]);
//     for (i = 1; i < n; i++)
//     {
//         mov = mov + abs(a[i] - a[i - 1]); /// head movement
//         printf(" -> %d", a[i]);
//     }
//     printf("\n");
//     printf("total head movement = %d\n", mov);
// }