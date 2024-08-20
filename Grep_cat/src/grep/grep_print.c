#include "grep.h"

int printFile(char *filename, Flags *flags, char *template_string,
              int *filesCnt) {
  bool flag = TRUE;
  FILE *file;
  if ((file = fopen(filename, "r")) == NULL && !flags->s) {
    printf("grep: %s: No such file or directory\n", filename);
  } else if (file) {
    regex_t template;
    bool endFile = FALSE;
    int index = 1;
    int res = 0;
    char *str;
    int match = 0;
    // при наличии флага i шаблон должен игнорировать регистры
    if (flags->i)
      res = regcomp(&template, template_string, REG_ICASE);
    else
      res = regcomp(&template, template_string, REG_EXTENDED);
    if (res != 0) {
      printf("grep: Invalid range end\n");
      regfree(&template);
      flag = FALSE;
    }
    if (flag) {
      while (1) {
        str = getString(file, &endFile);
        if (!(res = regexec(&template, str, 0, NULL, 0)) && !flags->v) {
          if (flags->l) {
            printf("%s\n", filename);
            break;
          } else {
            if (*filesCnt >= 3 && !flags->c) printf("%s:", filename);
            printString(flags, str, &index, &match);
          }
        } else if (res && flags->v && !flags->l) {
          if (*filesCnt >= 3 && !flags->c) printf("%s:", filename);
          printString(flags, str, &index, &match);
        } else if (res && flags->v && flags->l) {
          printf("%s\n", filename);
          break;
        }
        if (endFile) break;
        index++;
        free(str);
      }
      if (flags->c && *filesCnt < 3)
        printf("%d\n", match);
      else if (flags->c && *filesCnt >= 3)
        printf("%s:%d\n", filename, match);
    }
    free(str);
    regfree(&template);
    fclose(file);
  }
  return flag;
}

void printString(Flags *flags, char *str, int *index, int *match) {
  if (flags->n) printf("%d:", *index);
  if (!flags->c) {
    printf("%s", str);
  } else
    (*match)++;
  if (!flags->c) printf("\n");
}

char *getString(FILE *file, bool *endFile) {
  int capacity = 1;
  int len = 0;
  char *s = (char *)malloc(sizeof(char));
  char c;
  c = getc(file);
  while (c != '\n' && c != EOF) {
    s[len++] = c;
    if (len >= capacity) {
      capacity *= 2;
      s = (char *)realloc(s, capacity * sizeof(char));
    }
    c = getc(file);
  }
  if (c == EOF) *endFile = TRUE;
  if (len != 0) {
    s = (char *)realloc(s, (len + 1) * sizeof(char));
  }
  s[len] = '\0';
  return s;
}