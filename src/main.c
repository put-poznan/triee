#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void dividers(int num, int from, int to, int depth, int childs) {
  int i = 0;
  /*printf("%d %d\n", depth, childs);*/

  if (depth <= 0) {
    for (i = from; i < to; i++) {
      if (num % i == 0) {
        printf("%d dzieli %d\n", i, num);
      }
    }
    exit(0);
  }

  int diff = to - from + 1;
  int step = diff / (childs);
  int pid = 0;
  for (i = 0; i < childs; i++) {
    if ((pid = fork()) == -1) {
      perror("Cannot fork.\n");
      exit(5);
    }

    if (pid == 0) {
      dividers(num,
          from + (step * i),
          from + (step * (i + 1)),
          depth - 1,
          childs);
    }
  }
}

int main(int argc, char *argv[]) {
  dividers(1000, 1, 100, 2, 2);

  return 0;
}
