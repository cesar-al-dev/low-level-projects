#include <stdio.h>

int main(int argc, char *argv[]) {
  if (argc < 2) {
    printf("Usage: ./dwc <Path to file>\n");
    return -1;
  }

  FILE *f = fopen(argv[1], "rb");

  if (!f) {
    printf("File not found\n");
    return -1;
  }

  int newLines = 1;
  int words = 0;
  int chars = 0;

  while (1) {
    char c = fgetc(f);
    if (c == EOF) {
      break;
    }
    switch (c) {
    case '\n':
      newLines++;
      words++;
      break;
    case ' ':
      words++;
      break;
    case '\t':
      words++;
      break;
    }
    chars++;
  }

  printf(" %d %d %d %s\n", newLines, words, chars, argv[1]);

  fclose(f);

  return 0;
}
