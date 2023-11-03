#include <stdio.h>
#include <unistd.h>
#include <semaphore.h>
#include <pthread.h>
#include <sys/syscall.h>
void *reader(void *argp);
void *writer(void *argp);
int buffer;
int flag = 0;
int read_count = 0;
int getbuff()
{
    int temp;
    printf("Enter the no to add in buffer : ");
    scanf("%d", &temp);
    return temp;
}
void readbuff(int buffer)
{
    printf("Element read by reader=%d\n", buffer);
}
pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t wrt = PTHREAD_MUTEX_INITIALIZER;
int main()
{
    pthread_t wtid1, rtid1, rtid2;
    pthread_create(&wtid1, NULL, writer, NULL);
    pthread_create(&rtid1, NULL, reader, NULL);
    pthread_create(&rtid2, NULL, reader, NULL);
    pthread_join(wtid1, NULL);
    pthread_join(rtid1, NULL);
    pthread_join(rtid2, NULL);
    return 0;
}
void *writer(void *argp)
{
    while (1)
    {
        pthread_mutex_lock(&wrt);
        if (flag == 0)
        {

            buffer = getbuff();
            flag = 1;
        }
        pthread_mutex_unlock(&wrt);
    }
}
void *reader(void *argp)
{
    while (1)
    {
        pthread_mutex_lock(&mutex1);
        read_count++;
        if (read_count == 1)
        {
            pthread_mutex_lock(&wrt);
        }
        pthread_mutex_unlock(&mutex1);

        if (flag == 1)
        {
            readbuff(buffer);
            sleep(1);
            flag = 0;
        }
        pthread_mutex_lock(&mutex1);
        read_count--;
        if (read_count == 0)
        {
            pthread_mutex_unlock(&wrt);
        }
        pthread_mutex_unlock(&mutex1);
    }
}
// output:
// comp123@comp123:~/Desktop/os/4$ gcc reader-writer.c
// comp123@comp123:~/Desktop/os/4$ ./a.out
// Enter the no to add in buffer : 6
// Element read by reader=6
// Element read by reader=6
// Enter the no to add in buffer : 90
// Element read by reader=90
// Element read by reader=90
// Enter the no to add in buffer : 35
// Element read by reader=35
// Element read by reader=35
// 2Enter the no to add in buffer :
// Element read by reader=2
// Element read by reader=2

// Enter the no to add in buffer : 2
// Element read by reader=2
// Element read by reader=2
// Enter the no to add in buffer : 6
// Element read by reader=6
// Element read by reader=6
// Enter the no to add in buffer : 4
// Element read by reader=4
// Element read by reader=4
// Enter the no to add in buffer : 75
// Element read by reader=75
// Element read by reader=75
// Enter the no to add in buffer : ^C
// comp123@comp123:~/Desktop/os/4$


/*The Reader-Writer Problem is a synchronization challenge in operating systems and concurrent programming where multiple processes need to access a shared resource, but with different access requirements. The problem typically involves readers who can read the resource simultaneously and writers who have exclusive write access. Here's how it works:

1. Readers: Multiple reader processes can access the shared resource concurrently without any issues, as reading does not modify the resource.

2. Writers: Writer processes, on the other hand, need exclusive access to the resource, as they intend to modify it. This means only one writer can access the resource at a time, and no other readers or writers can access it during that time.

3. Synchronization: To manage access to the shared resource, synchronization mechanisms like semaphores, mutexes, or other concurrency control tools are employed.

4. Priority: The Reader-Writer Problem can be implemented with different priorities. For example, a reader-preference approach allows readers to proceed unless a writer is waiting. A writer-preference approach allows waiting writers to gain access as soon as the resource becomes available, even if there are waiting readers.

5. Starvation: Care must be taken to prevent issues like writer starvation, where writers may be waiting indefinitely if readers are continuously accessing the resource.

6. Balance: Achieving a balance between the needs of readers and writers, ensuring data integrity, and preventing race conditions is the key challenge in solving the Reader-Writer Problem.

The Reader-Writer Problem highlights the need for careful synchronization and resource management in a concurrent system. The goal is to allow readers to access the resource concurrently while preventing any conflicts or data corruption when writers modify the resource. Implementations of the Reader-Writer Problem can vary based on the specific requirements and priorities of the system.*/
