#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  char t[7] = "Skibidi";
  char p[3] = "ski";

  int p_length = sizeof(p) / sizeof(char);
  int t_length = sizeof(t) / sizeof(char);
  int i = 0;

  printf("%d\n", t_length);

  while (i < t_length) {
    char temp;
    int last_coincidence;
    for (int j = p_length - 1; j >= 0; j--) {
      temp = t[i + j];
      if (p[j] == temp) {
        last_coincidence = i + j;
      }
    }
  }

  printf("Hello world!\n");
  return EXIT_SUCCESS;
}
