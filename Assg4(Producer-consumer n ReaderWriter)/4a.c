#include <stdio.h>
#include <sys/syscall.h>
#include <pthread.h>
#include <semaphore.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
void *producer();
void *consumer();
typedef struct
{
    int buffer[20];
    sem_t full, empty;
} shared;
shared sh;
int item;
int in = 0, out = 0;
sem_t mutex;
int main()
{
    pthread_t ptid1, ptid2, ctid1;
    sem_init(&sh.empty, 0, 20);
    sem_init(&sh.full, 0, 0);
    sem_init(&mutex, 0, 1);
    pthread_create(&ptid1, NULL, producer, NULL);
    pthread_create(&ptid2, NULL, producer, NULL);
    pthread_create(&ctid1, NULL, consumer, NULL);
    pthread_join(ptid1, NULL);
    pthread_join(ptid2, NULL);
    pthread_join(ctid1, NULL);
    return 0;
}
void *producer()
{
    // pthread_t item;
    int ptid;
    while (1)
    {
        item = in;
        sem_wait(&sh.empty);

        sem_wait(&mutex);
        sh.buffer[in++] = item;
printf("PRODUCER Thread id = %ld and Producer Item = %d \

n",pthread_self(),item);

sem_post(&mutex);
sem_post(&sh.full);
sleep(3);
    }
}
void *consumer()
{
    int ctid;
    while (out <= 19 && in <= 19)
    {
sem_wait(&sh.full);
sem_wait(&mutex);
item = sh.buffer[out++];
printf("\tCONSUMER Thread id = %ld and Consumer Item = %d \

n",syscall(SYS_gettid,ctid),item);
sem_post(&mutex);
sem_post(&sh.empty);
sleep(1);
    }
}
// output:
// comp123@comp123:~/Desktop/os/4$ gcc producer-consumer.c
// comp123@comp123:~/Desktop/os/4$ ./a.out
// PRODUCER Thread id = 139828242937408 and Producer Item = 0
// CONSUMER Thread id = 25193 and Consumer Item = 0
// PRODUCER Thread id = 139828234544704 and Producer Item = 0
// CONSUMER Thread id = 25193 and Consumer Item = 0
// PRODUCER Thread id = 139828242937408 and Producer Item = 2
// PRODUCER Thread id = 139828234544704 and Producer Item = 3
// CONSUMER Thread id = 25193 and Consumer Item = 2
// CONSUMER Thread id = 25193 and Consumer Item = 3
// PRODUCER Thread id = 139828242937408 and Producer Item = 4
// PRODUCER Thread id = 139828234544704 and Producer Item = 4
// CONSUMER Thread id = 25193 and Consumer Item = 4
// CONSUMER Thread id = 25193 and Consumer Item = 4
// PRODUCER Thread id = 139828242937408 and Producer Item = 6
// PRODUCER Thread id = 139828234544704 and Producer Item = 7
// CONSUMER Thread id = 25193 and Consumer Item = 6
// CONSUMER Thread id = 25193 and Consumer Item = 7
// PRODUCER Thread id = 139828242937408 and Producer Item = 8
// PRODUCER Thread id = 139828234544704 and Producer Item = 9

// CONSUMER Thread id = 25193 and Consumer Item = 8
// CONSUMER Thread id = 25193 and Consumer Item = 9
// PRODUCER Thread id = 139828242937408 and Producer Item = 10
// CONSUMER Thread id = 25193 and Consumer Item = 10
// PRODUCER Thread id = 139828234544704 and Producer Item = 11
// CONSUMER Thread id = 25193 and Consumer Item = 11
// PRODUCER Thread id = 139828242937408 and Producer Item = 12
// PRODUCER Thread id = 139828234544704 and Producer Item = 13
// CONSUMER Thread id = 25193 and Consumer Item = 12
// CONSUMER Thread id = 25193 and Consumer Item = 13
// PRODUCER Thread id = 139828234544704 and Producer Item = 14
// PRODUCER Thread id = 139828242937408 and Producer Item = 15
// CONSUMER Thread id = 25193 and Consumer Item = 14
// CONSUMER Thread id = 25193 and Consumer Item = 15
// PRODUCER Thread id = 139828234544704 and Producer Item = 16
// PRODUCER Thread id = 139828242937408 and Producer Item = 17
// CONSUMER Thread id = 25193 and Consumer Item = 16
// CONSUMER Thread id = 25193 and Consumer Item = 17
// PRODUCER Thread id = 139828242937408 and Producer Item = 18
// PRODUCER Thread id = 139828234544704 and Producer Item = 19
// CONSUMER Thread id = 25193 and Consumer Item = 18
// PRODUCER Thread id = 139828242937408 and Producer Item = 20
// PRODUCER Thread id = 139828234544704 and Producer Item = 21
// PRODUCER Thread id = 139828242937408 and Producer Item = 22
// The futex facility returned an unexpected error code.
// PRODUCER Thread id = 139828234544704 and Producer Item = 23
// The futex facility returned an unexpected error code.
// Aborted (core dumped)




/*The Producer-Consumer Problem is a classic synchronization issue in operating systems where two types of processes, producers and consumers, share a common, finite-size buffer or queue. The goal is to ensure that producers can add items to the buffer, and consumers can remove items from it without any race conditions or conflicts. Here's how it works:

1. Producers produce items: Producers generate items or data and wish to place them into the shared buffer for consumption by consumers.

2. Consumers consume items: Consumers want to retrieve and process items from the shared buffer.

3. Buffer management: A finite-size buffer is used to hold the produced items until consumers can consume them. The buffer can be thought of as a shared resource.

4. Synchronization: To avoid problems like buffer overflows (when the buffer is full) and underflows (when it's empty), synchronization mechanisms like semaphores, mutexes, or condition variables are employed. These mechanisms ensure that producers and consumers coordinate their actions.

5. Producer actions: Producers must check if there is space in the buffer to add new items. If space is available, they can add items to the buffer.

6. Consumer actions: Consumers must check if there are items in the buffer to consume. If items are present, they can retrieve and process them.

7. Coordination: Producers and consumers communicate through shared synchronization constructs to ensure that the buffer remains in a consistent state. For example, producers signal when they add items, and consumers signal when they remove items.

8. Handling overflows and underflows: The system needs to handle situations where the buffer becomes full or empty. Depending on the design, producers may need to wait if the buffer is full, and consumers may need to wait if the buffer is empty.

The Producer-Consumer Problem is a fundamental concept in concurrent programming and is used to illustrate the challenges of managing shared resources and coordinating actions between multiple processes to prevent issues like data corruption, race conditions, or deadlock. It often serves as a basis for understanding and implementing synchronization in operating systems and parallel computing environments.*/
