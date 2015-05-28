#include <stdio.h>
#include "mutex.h"

volatile int Counter=0;

Mutex m;

void *
thread1 (void *p)
{
  for (unsigned int i = 0; i < 100000; i++)
    {
      MutexLock l(m);
      Counter++;
      Counter--;
    }
  pthread_exit (p);
}

void *
thread2 (void *p)
{
  for (unsigned int i = 0; i < 100000; i++)
    {
      MutexLock l(m);
      Counter++;
      Counter--;
    }
  pthread_exit (p);
}


int
main ()
{
  pthread_t t1;
  pthread_t t2;

  pthread_create (&t1, NULL, thread1, NULL);
  pthread_create (&t2, NULL, thread2, NULL);

  pthread_join (t1, (void **) NULL);
  pthread_join (t2, (void **) NULL);

  printf ("Counter=%d\n", Counter);
}
