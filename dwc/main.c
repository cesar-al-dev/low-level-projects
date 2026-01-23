#include <ctype.h>
#include <stddef.h>
#include <stdio.h>

#define BUFFER_SIZE 16384

int main(int argc, char *argv[]) {
  if (argc < 2) {
    printf("Usage: %s <Path to file>\n", argv[0]);
    return -1;
  }

  FILE *f = fopen(argv[1], "rb");

  if (!f) {
    perror("Error opening file");
    return -1;
  }

  size_t lines = 0;
  size_t words = 0;
  size_t bytes = 0;

  char buffer[BUFFER_SIZE];
  int in_word = 0;
  size_t bytes_read;

  while ((bytes_read = fread(buffer, 1, BUFFER_SIZE, f)) > 0) {
    bytes += bytes_read;
    for (size_t i = 0; i < bytes_read; i++) {
      char c = buffer[i];

      if (c == '\n') {
        lines++;
      }

      // Logic for word counting:
      // If it's not a whitespace, and we weren't in a word, we just started
      // one.
      if (isspace((unsigned char)c)) {
        in_word = 0;
      } else if (!in_word) {
        in_word = 1;
        words++;
      }
    }
  }

  printf(" %zu %zu %zu %s\n", lines, words, bytes, argv[1]);
  fclose(f);

  return 0;
}
