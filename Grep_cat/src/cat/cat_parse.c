#include "cat.h"

int parser(int argc, char *argv[], Flags *flags) {
  int ind = 1;
  if (argc >= 2) {
    for (int i = 1; i < argc && !flags->flags_error; i++) {
      flagsAnalyser(argv[i], flags);
    }
    // если пользователь вызвал --help то кроме этого ничего не вызываем
    if (!flags->help) {
      for (int i = 1; i < argc && !flags->flags_error; i++) {
        if (filenameAnalyser(argv[i]) && flags->filename)
          printFile(argv[i], flags, &ind);
      }
    } else
      printHelp();
  } else {
    printf("Укажите название файла\n");
  }
  return 0;
}

void flagsAnalyser(char *string, Flags *flags) {
  // проверка на GNU
  if (string[0] == '-') {  // проверка на то что аргумент флаг
    if (string[1] == '-') {
      if (!strcmp(string, "--number-nonblank")) {
        flags->b = true;
      } else if (!strcmp(string, "--number")) {
        flags->n = true;
      } else if (!strcmp(string, "--squeeze-blank")) {
        flags->s = true;
      } else if (!strcmp(string, "--help")) {
        flags->help = true;
      }
    } else {
      int len = strlen(string);
      for (int i = 1; i <= len - 1; i++) {
        if (string[i] == 'n') {
          if (!flags->b) flags->n = true;
        } else if (string[i] == 'b') {
          flags->b = true;
          flags->n = false;
        } else if (string[i] == 'e') {
          flags->E = true;
          flags->v = true;
        } else if (string[i] == 'E')
          flags->E = true;
        else if (string[i] == 's')
          flags->s = true;
        else if (string[i] == 'T')
          flags->T = true;
        else if (string[i] == 't') {
          flags->T = true;
          flags->v = true;
        } else if (string[i] == 'v')
          flags->v = true;
        else {
          flags->flags_error = true;
          printf("cat: invalid option -- \'%c'\n", string[i]);
          printf("Try 'cat --help' for more information.\n");
          break;
        }
      }
    }
  } else {
    flags->filesCnt++;
    flags->filename = true;
  }
}

bool filenameAnalyser(char *string) {
  bool flag = false;
  if (string[0] != '-' && string[1] != '-') flag = true;
  return flag;
}
