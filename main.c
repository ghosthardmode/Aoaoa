#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  int size;
  char *str;
}string;

void init(string *str) {
  str->size = 10;
  str->str = malloc(sizeof(char) * str->size);
  strcpy(str->str, "0123456789012345");
}

void checkForOverFlow(string *str) {
  if (strlen(str->str) > str->size) {
    realloc(str->str, strlen(str->str) + 10);
  }
}

int main() {
  string str;
  init(&str);
  checkForOverFlow(&str);
  printf("%s\n", str.str);
  free(str.str);
  return 0;
}