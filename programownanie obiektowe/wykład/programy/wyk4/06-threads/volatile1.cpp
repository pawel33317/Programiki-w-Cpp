#include <stdio.h>
#include <pthread.h>

int val = 0;

void *
fun1 (void *)
{
  val = 0;
  while (1)
    if (val != 0)
      break;
  printf ("wyszlismy z petli\n");
  pthread_exit (NULL);
}


int
main ()
{
  pthread_t w;

  pthread_create (&w, NULL, fun1, NULL);
  val = 1;
  pthread_join (w, NULL);
}
