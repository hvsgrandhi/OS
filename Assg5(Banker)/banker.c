#include <stdio.h>
struct process
{
    int max[10], allocate[10], need[10];
} p[10];
int n, m;
void input(int[]);
void display();
int isSafestate(int[], int[]);
int safetyalgorithm(int[], int[]);
int main()
{
    int i;
    printf("\nEnter No of processes: ");
    scanf("%d", &n);
    printf("Enter no of resources: ");
    scanf("%d", &m);
    int available[m];
    int safesequence[n];
    printf("\n*****Enter details of process*****");
    input(available);
    display();
    if (isSafestate(available, safesequence))
    {
        printf("\n\tSYSTEM IS IN SAFE STATE...");
        printf("\nsafesequence is: ");
        for (i = 0; i < n; i++)
            printf("P%d -> ", safesequence[i]);
    }
    else
        printf("\nSYSTEM IS IN UNSAFE STATE!!!");
    return 0;
}
void input(int available[m])
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        printf("\nEnter the details of process P%d: ", i);
        printf("\n\tEnter the allocates resources: ");
        for (j = 0; j < m; j++)
        {
            scanf("%d", &p[i].allocate[j]);
        }
        printf("\tEnter the max resourcess: ");
        for (j = 0; j < m; j++)
        {
            scanf("%d", &p[i].max[j]);

            p[i].need[j] = p[i].max[j] - p[i].allocate[j];
        }
    }
    printf("\nEnter the allvailable resources: ");
    for (j = 0; j < m; j++)
    {
        scanf("%d", &available[j]);
    }
}
void display()
{
    int i, j;
    printf("\n\tPID\tALLOCATE\tMAX\t\tNEED\n");
    for (i = 0; i < n; i++)
    {
        printf("\tP%d\t", i);
        for (j = 0; j < m; j++)
            printf("%d ", p[i].allocate[j]);
        printf("\t\t");
        for (j = 0; j < m; j++)
            printf("%d ", p[i].max[j]);
        printf("\t\t");
        for (j = 0; j < m; j++)
            printf("%d ", p[i].need[j]);
        printf("\n");
    }
}
int isSafestate(int available[m], int safesequence[n])
{
    if (safetyalgorithm(available, safesequence) == 1)
        return 1;
    return 0;
}
int safetyalgorithm(int available[m], int safesequence[n])
{
    int i, j;
    int work[m], finish[n];
    for (j = 0; j < m; j++)
        work[j] = available[j];
    for (i = 0; i < n; i++)
        finish[i] = 0;
    int proceed = 1, k = 0;
    while (proceed)
    {
        proceed = 0;
        for (i = 0; i < n; i++)
        {

            int flag = 1;
            if (finish[i] == 0)
            {
                for (j = 0; j < m; j++)
                {
                    if (p[i].need[j] <= work[j])
                    {
                        continue;
                    }
                    else
                    {
                        flag = 0;
                        break;
                    }
                }
                if (flag == 0)
                    continue;
                for (j = 0; j < m; j++)
                {
                    work[j] += p[i].allocate[j];
                }
                finish[i] = 1;
                safesequence[k++] = i;
                proceed = 1;
            }
        }
    }

    for (i = 0; i < n && finish[i] == 1; i++)
        continue;
    if (i == n)
        return 1;
    return 0;
}
// output:
// comp123@comp123:~/Desktop/os/5$ gcc Banker.c
// comp123@comp123:~/Desktop/os/5$ ./a.out
// Enter No of processes: 5
// Enter no of resources: 3
// *****Enter details of process*****
// Enter the details of process P0:
// Enter the allocates resources: 0
// 1
// 0
// Enter the max resourcess: 7
// 5
// 3

// Enter the details of process P1:
// Enter the allocates resources: 2
// 0
// 0
// Enter the max resourcess: 3
// 2
// 2
// Enter the details of process P2:
// Enter the allocates resources: 3
// 0
// 2
// Enter the max resourcess: 9
// 0
// 2
// Enter the details of process P3:
// Enter the allocates resources: 2
// 1
// 1
// Enter the max resourcess: 2
// 2
// 2
// Enter the details of process P4:
// Enter the allocates resources: 0
// 0
// 2
// Enter the max resourcess: 4
// 3
// 3
// Enter the allvailable resources: 3
// 3
// 2
// PID ALLOCATE MAX NEED
// P0 0 1 0 7 5 3 7 4 3
// P1 2 0 0 3 2 2 1 2 2
// P2 3 0 2 9 0 2 6 0 0
// P3 2 1 1 2 2 2 0 1 1
// P4 0 0 2 4 3 3 4 3 1
// SYSTEM IS IN SAFE STATE...

// safesequence is: P1 -> P3 -> P4 -> P0 -> P2 -> comp123@comp123:~/Desktop/os/5$

/*The Banker's Algorithm is a resource allocation and deadlock avoidance technique used in operating systems to ensure that processes request and release resources in a way that prevents deadlock. It works as follows:

1. Initialization: The algorithm starts with an initial allocation of resources and a maximum demand for each process. It also maintains a record of available resources.

2. Request Phase: When a process requests additional resources, the system checks if granting those resources will result in a safe state, i.e., it won't lead to a deadlock. If the request can be satisfied without compromising the safety of the system, the resources are allocated; otherwise, the process must wait.

3. Release Phase: When a process is done with its resources, it releases them back to the system.

4. Safety Check: The algorithm periodically checks if the system is in a safe state, meaning it can allocate resources to processes in such a way that they can complete their execution and release their resources. If a safe sequence of resource allocation can be found, the system proceeds; otherwise, it waits for resources to become available.

The Banker's Algorithm uses the concepts of available resources, maximum resource demands, and allocated resources to determine whether the system can satisfy a process's request without causing a potential deadlock. If a deadlock is detected, the algorithm prevents resource allocation until the system is in a safe state.

By carefully managing resource allocation and monitoring for potential deadlocks, the Banker's Algorithm helps ensure the stability and reliability of an operating system.*/
