#include <stddef.h>
#include <stdio.h>

#define BUFFER_SIZE 512000

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

  char buffer[BUFFER_SIZE];
  size_t bytes_read;

  while ((bytes_read = fread(buffer, 1, BUFFER_SIZE, f)) > 0) {
    printf("%s", buffer);
  }

  fclose(f);

  return 0;
}
