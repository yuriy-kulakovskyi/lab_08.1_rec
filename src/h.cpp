#include "../include/main.h"
#include <algorithm>

int Count(char* str, int i) {
  if (strlen(str) < 4)
    return 0;

  if (str[i + 3] != 0)
    if (str[i] == str[i + 1] && str[i + 1] == str[i + 2] && str[i + 2] == str[i + 3])
      return 1 + Count(str, i + 1);
    else
      return Count(str, i + 1);
  else
    return 0;
}

void ReplaceStars(char* str, char* result, size_t i, size_t j) {
  if (str[i] == '\0') {
    result[j] = '\0';
    strcpy(str, result);
    return;
  }

  if (str[i] == str[i + 1] && str[i + 1] == str[i + 2] && str[i + 2] == str[i + 3]) {
    result[j] = '*';
    result[j + 1] = '*';
    ReplaceStars(str, result, i + 4, j + 2);
  } else {
    result[j] = str[i];
    ReplaceStars(str, result, i + 1, j + 1);
  }
}

char* Change(char* str) {
  size_t len = strlen(str);
  if (len < 4)
    return str;

  char* tmp = new char[len * 2 + 1];
  ReplaceStars(str, tmp, 0, 0);
  delete[] tmp;
  return str;
}