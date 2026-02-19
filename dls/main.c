#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
  struct dirent **namelist;
  int n;

  n = scandir(".", &namelist, 0, alphasort);
  if (n < 0)
    perror("scandir");
  else {
    while (n--) {
      printf("%s\n", namelist[n]->d_name);
      free(namelist[n]);
    }
    free(namelist);
  }
}
