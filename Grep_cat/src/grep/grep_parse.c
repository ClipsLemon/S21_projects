#include "grep.h"

void parser(int *argc, char *argv[], Flags *flags) {
  int filesCnt = 0;
  if (*argc >= 3) {
    for (int i = 1; i < *argc && !flags->error; i++) {
      flagsAnalyser(argv[i], flags, &filesCnt, &i);
    }
    if (flags->h)
      filesCnt = 0;
    else
      filesCnt = (*argc) - filesCnt - 1;
    if (!flags->error) {
      for (int i = 1; i < *argc; i++) {
        if (filenameAnalyser(argv[i])) {
          if (flags->temp_pos != i)
            printFile(argv[i], flags, argv[flags->temp_pos], &filesCnt);
        }
      }
    }
  }
}
bool filenameAnalyser(char *string) {
  bool flag = FALSE;
  if (string[0] != '-') flag = TRUE;
  return flag;
}

void flagsAnalyser(char *string, Flags *flags, int *filesCnt, const int *i) {
  if (string[0] == '-') {
    int n = 1;
    while (string[n] != '\0') {
      if (string[n] == 'e') {
        flags->e = TRUE;
        flags->temp_pos = *i + 1;
      } else if (string[n] == 'i') {
        flags->i = TRUE;
      } else if (string[n] == 'v')
        flags->v = TRUE;
      else if (string[n] == 'c') {
        if (!flags->l) {
          flags->c = TRUE;
          flags->n = FALSE;
        }
      } else if (string[n] == 'l') {
        flags->l = TRUE;
        flags->n = FALSE;
        flags->c = FALSE;
      } else if (string[n] == 'n') {
        if (!flags->c && !flags->l) flags->n = TRUE;
      } else if (string[n] == 'h') {
        flags->h = TRUE;
      } else if (string[n] == 's') {
        flags->s = TRUE;
      } else {
        flags->error = TRUE;
        printf("grep: invalid option -- \'%c\'\n", string[n]);
        printf("Usage: grep [OPTION]... PATTERNS [FILE]...\n");
        printf("Try 'grep --help' for more information.\n");
      }
      n++;
    }
    // изначально в записывается количество флагов
    (*filesCnt)++;
  } else if (flags->temp_pos == 0) {
    flags->temp_pos = *i;
  }
}
