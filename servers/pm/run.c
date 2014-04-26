#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <errno.h>
#include <sys/stat.h>

#define ITERATIONS 100000
#define CHILDREN 1

int main(int argc, char *argv[])
{
  int pid;
        int status=0;
        pid = fork();
        int i;
        for (i = 0; i < CHILDREN; i++)
          beChildish(i);
        if (pid > 0)
        {
                int i;
                for (i = 0; i < ITERATIONS; i++)
                  printf("Parent!\n");
                for (i = 0; i < CHILDREN; i++)
                  wait(&status);
        }

}

int beChildish(int name){
  int pid;
  pid = fork();

  if (pid == 0) //if the child                                                                                                                                                   
    {
      int i;
      for (i = 0; i < ITERATIONS; i++)
        printf("Child <%d%d%d%d>!\n",name,name,name,name);
      exit(0);

    }
  return 0;
}
