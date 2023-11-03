#include <stdio.h>
#include <stdlib.h>
int SSTF();
int SCAN();
int CLOOK();
int main()
{
    int ch, YN = 1, i, l, f;
    char F[10], s[25];
    for (i = 0; i < f; i++)
    {
        F[i] = -1;
    }
    do
    {
        // system("clear");
        printf("\n\n\t*********** MENU ***********");
        printf("\n\n\t1:SSTF\n\n\t2:SCAN\n\n\t3:CLOOK\n\n\t4:EXIT");
        printf("\n\n\tEnter your choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            for (i = 0; i < f; i++)
            {
                F[i] = -1;
            }
            SSTF();
            break;
        case 2:
            for (i = 0; i < f; i++)
            {
                F[i] = -1;
            }
            SCAN();
            break;
        case 3:
            for (i = 0; i < f; i++)
            {
                F[i] = -1;
            }
            CLOOK();
            break;
        case 4:
            exit(0);
        }
        printf("\n\n\tDo u want to continue IF YES PRESS 1\n\n\tIF NO PRESS 0: ");
        scanf("%d", &YN);
    } while (YN == 1);
    return (0);
}
// SSTF Algorithm
int SSTF()
{
    int RQ[100], i, n, TotalHeadMoment = 0, initial, count = 0;
    printf("Enter the number of Requests\n");
    scanf("%d", &n);
    printf("Enter the Requests sequence\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &RQ[i]);
    }
    printf("Enter initial head position\n");
    scanf("%d", &initial);
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
        RQ[index] = 1000;
        count++;
    }
    printf("Total head movement is %d", TotalHeadMoment);
    return 0;
}
// SCAN Algorithm
int SCAN()
{
    int RQ[100], i, j, n, TotalHeadMoment = 0, initial, size, move;
    printf("Enter the number of Requests\n");
    scanf("%d", &n);
    printf("Enter the Requests sequence\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &RQ[i]);
    }
    printf("Enter initial head position\n");
    scanf("%d", &initial);
    printf("Enter total disk size\n");
    scanf("%d", &size);
    printf("Enter the head movement direction for high 1 and for low 0\n");
    scanf("%d", &move);
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (RQ[j] > RQ[j + 1])
            {
                int temp;
                temp = RQ[j];
                RQ[j] = RQ[j + 1];
                RQ[j + 1] = temp;
            }
        }
    }
    int index;
    for (i = 0; i < n; i++)
    {
        if (initial < RQ[i])
        {
            index = i;
            break;
        }
    }
    if (move == 1)
    {
        for (i = index; i < n; i++)
        {
            TotalHeadMoment = TotalHeadMoment + abs(RQ[i] - initial);
            initial = RQ[i];
        }
        TotalHeadMoment = TotalHeadMoment + abs(size - RQ[i - 1] - 1);
        initial = size - 1;
        for (i = index - 1; i >= 0; i--)
        {
            TotalHeadMoment = TotalHeadMoment + abs(RQ[i] - initial);
            initial = RQ[i];
        }
    }
    else
    {
        for (i = index - 1; i >= 0; i--)
        {
            TotalHeadMoment = TotalHeadMoment + abs(RQ[i] - initial);
            initial = RQ[i];
        }
        TotalHeadMoment = TotalHeadMoment + abs(RQ[i + 1] - 0);
        initial = 0;
        for (i = index; i < n; i++)
        {
            TotalHeadMoment = TotalHeadMoment + abs(RQ[i] - initial);
            initial = RQ[i];
        }
    }
    printf("Total head movement is %d", TotalHeadMoment);
    return 0;
}
// C-LOOK Algorithm
int CLOOK()
{
    int RQ[100], i, j, n, TotalHeadMoment = 0, initial, size, move;
    printf("Enter the number of Requests\n");
    scanf("%d", &n);
    printf("Enter the Requests sequence\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &RQ[i]);
    }
    printf("Enter initial head position\n");
    scanf("%d", &initial);
    printf("Enter total disk size\n");
    scanf("%d", &size);
    printf("Enter the head movement direction for high 1 and for low 0\n");
    scanf("%d", &move);
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (RQ[j] > RQ[j + 1])
            {
                int temp;
                temp = RQ[j];
                RQ[j] = RQ[j + 1];
                RQ[j + 1] = temp;
            }
        }
    }
    int index;
    for (i = 0; i < n; i++)
    {
        if (initial < RQ[i])
        {
            index = i;
            break;
        }
    }
    if (move == 1)
    {
        for (i = index; i < n; i++)
        {
            TotalHeadMoment = TotalHeadMoment + abs(RQ[i] - initial);
            initial = RQ[i];
        }
        for (i = 0; i < index; i++)
        {
            TotalHeadMoment = TotalHeadMoment + abs(RQ[i] - initial);
            initial = RQ[i];
        }
    }
    else
    {
        for (i = index - 1; i >= 0; i--)
        {
            TotalHeadMoment = TotalHeadMoment + abs(RQ[i] - initial);
            initial = RQ[i];
        }
        for (i = n - 1; i >= index; i--)
        {
            TotalHeadMoment = TotalHeadMoment + abs(RQ[i] - initial);
            initial = RQ[i];
        }
    }
    printf("Total head movement is %d", TotalHeadMoment);
    return 0;
}
// Output:
// *********** MENU ***********
// 1:SSTF
// 2:SCAN
// 3:CLOOK
// 4:EXIT
// Enter your choice: 1
// Enter the number of Requests
// 50 8
// Enter the Requests sequence
// 176
// 79
// 34
// 60
// 92
// 1
// 41
// 114
// Enter initial head position
// 50
// Total head movement is 333
// Do u want to continue IF YES PRESS 1
// IF NO PRESS 0: 1
// *********** MENU ***********
// 1:SSTF
// 2:SCAN
// 3:CLOOK
// 4:EXIT
// Enter your choice: 2
// Enter the number of Requests
// 8
// Enter the Requests sequence
// 176
// 79
// 34
// 60
// 92
// 1
// 41
// 114
// Enter initial head position
// 50
// Enter total disk size
// 200
// Enter the head movement direction for high 1 and for low 0
// 1
// Total head movement is 347
// Do u want to continue IF YES PRESS 1
// IF NO PRESS 0: 1
// *********** MENU ***********
// 1:SSTF
// 2:SCAN
// 3:CLOOK
// 4:EXIT
// Enter your choice: 3
// Enter the number of Requests
// 8
// Enter the Requests sequence
// 178 6
// 79
// 34
// 60
// 92
// 1
// 41
// 114
// Enter initial head position
// 50
// Enter total disk size
// 200
// Enter the head movement direction for high 1 and for low 0
// 1
// Total head movement is 341
// Do u want to continue IF YES PRESS 1
// IF NO PRESS 0: 0



/*Scheduling algorithms in operating systems are used to determine the order in which processes are executed on a CPU or the order in which disk I/O requests are serviced. Here's a short summary of how three common disk scheduling algorithms—SSTF (Shortest Seek Time First), SCAN, and C-LOOK—work:

1. SSTF (Shortest Seek Time First):
   - SSTF is a disk scheduling algorithm used to reduce seek time on a hard disk drive.
   - It selects the I/O request that is closest to the current position of the disk's read/write head.
   - The goal is to minimize the seek time, which is the time it takes for the disk head to move to the desired track.
   - SSTF can lead to starvation of some requests if there are always new requests arriving closer to the current head position.

2. SCAN (Elevator Algorithm):
   - SCAN, also known as the "elevator algorithm," moves the disk head in one direction until it reaches the end of the disk or the end of the request queue.
   - Once it reaches the end, it reverses direction and scans back in the opposite direction.
   - This approach minimizes seek time for I/O requests along the path of the head's movement, and it helps prevent starvation, as it eventually services all requests in both directions.

3. C-LOOK (Circular LOOK):
   - C-LOOK is a variation of the LOOK disk scheduling algorithm and is designed to minimize seek time while avoiding the unfairness of the standard LOOK algorithm.
   - It scans in one direction, servicing requests until there are no more in that direction, and then it quickly returns to the beginning of the disk (the "circular" part).
   - This approach eliminates the problem of starvation present in the standard LOOK algorithm and can provide fairer service to all requests.

These scheduling algorithms are primarily used for disk I/O requests, with the aim of reducing seek time and improving overall system performance. The choice of algorithm depends on the specific system requirements and workload. SSTF focuses on minimizing seek time, SCAN prevents starvation and provides fair service, and C-LOOK is a variant that also balances seek time and fairness in servicing disk requests.*/
