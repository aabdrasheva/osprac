#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

int a = 0;

void *mythread(void *dummy)
{
    pthread_t mythid;
    mythid = pthread_self();
    a = a + 1;
    printf("Thread %d, Calculation result = %d\n", mythid, a);
    return NULL;
}

int main()
{
    pthread_t thid2, thid3, mythid;
    int result;

    result = pthread_create( &thid2, (pthread_attr_t *)NULL, mythread, NULL);
    if (result != 0) {
        printf ("Error on thread create, return value = %d\n", result);
        exit(-1);
    }
    printf("thread №2 created, thid2 = %d\n", thid2);

    result = pthread_create( &thid3, (pthread_attr_t *)NULL, mythread, NULL);
    if (result != 0) {
        printf ("Error on thread create, return value = %d\n", result);
        exit(-1);
    }
    printf("thread №3 created, thid3 = %d\n", thid3);

    mythid = pthread_self();
    a = a + 1;
    printf("Thread %d, Calculation result = %d\n", mythid, a);

    pthread_join(thid2, (void **)NULL);
    pthread_join(thid3, (void **)NULL);
    return 0;
}
