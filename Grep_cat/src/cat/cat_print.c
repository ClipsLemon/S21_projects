#include "cat.h"

void printFile(char *filename, Flags *flags, int *i) {
  FILE *file;
  if ((file = fopen(filename, "rb")) == NULL) {
    printf("cat: %s: No such file or directory\n", filename);
  } else {
    char symbl;
    bool line_numeric = false;
    bool line_empty = false;
    bool new_line = false;

    while ((symbl = fgetc(file)) != EOF) {
      printSymbol(&symbl, flags, &line_numeric, &line_empty, &new_line, i);
      flags->new_file = false;
    }
    if (flags->filesCnt > 1) {
      flags->filesCnt--;
      flags->new_file = true;
    }
    fclose(file);
  }
}

void printSymbol(char *symbl, Flags *flags, bool *line_numeric,
                 bool *line_empty, bool *new_line, int *i) {
  if (!(*new_line && *line_empty && *symbl == '\n' && flags->s)) {
    if (*new_line && *symbl == '\n' && !(*line_empty)) {
      *line_empty = true;
    } else if (*new_line && *symbl != '\n' && *line_empty) {
      *line_empty = false;
    }
    // -b / -n
    if (((!(*line_numeric) && flags->n && !flags->b) ||
         (!(*line_numeric) && flags->b && *symbl != '\n')) &&
        !flags->new_file) {
      printf("%6d\t", *i);
      *line_numeric = true;
      (*i)++;
    }
    // -T
    if (flags->T && *symbl == '\t') {
      printf("^");
      *symbl = *symbl + 64;
    }
    // -v
    if (flags->v && *symbl != '\n' && *symbl != '\t') {
      if ((*symbl >= 0 && *symbl < 32)) {
        printf("^");
        *symbl = *symbl + 64;
      } else if (*symbl == 127 || (unsigned char)*symbl == 255) {
        printf("^?");
      } else if ((unsigned char)*symbl > 127 && (unsigned char)*symbl < 160) {
        *symbl = *symbl - 128 + 64;
        printf("M-^");
      } else if ((unsigned char)*symbl > 159 && (unsigned char)*symbl < 255) {
        *symbl = *symbl - 128;
        printf("M-");
      }
    }
    // -E
    if (*symbl == '\n') {
      *line_numeric = false;
      *new_line = true;
      if (flags->E) printf("$");
    } else
      *new_line = false;
    if (*symbl != 127 && flags->v)
      printf("%c", *symbl);
    else if (!flags->v) {
      printf("%c", *symbl);
    }
  }
}

void printHelp() {
  printf("Использование: ./s21_cat [ПАРАМЕТР]… [ФАЙЛ]…\n");
  printf("Печатает слияние ФАЙЛ(ов) на стандартный вывод.\n");
  printf("Если ФАЙЛ не задан или задан как -, читает стандартный ввод.\n");
  printf("\n");
  printf("  -b, --number-nonblank    нумеровать непустые строки при выводе\n");
  printf("  -e                       подавляет -n, синоним -vE\n");
  printf("  -E                       показывать $ в конце каждой строки\n");
  printf("  -n, --number             нумеровать все строки при выводе\n");
  printf(
      "  -s, --squeeze-blank      выводить не более одной пустой строки при "
      "повторе\n");
  printf("  -t                       синоним -vT\n");
  printf("  -T, --show-tabs          показывать символы табуляции как ^I\n");
  printf(
      "  -v, --show-nonprinting   использовать запись с ^ и M-, за "
      "исключением "
      "символов перевода строки и табуляции\n");
  printf("      --help        display this help and exit\n");
  printf("\n");
  printf("Примеры:\n");
  printf("./s21_cat filename -n  Выводит содержимое файла нумеруя строки\n");
  printf(
      "./s21_cat filename -ns Выводит содержимое файла нумеруя строки и "
      "выводит не более одной пустой при повторе\n");
  printf("\n");
  printf("Made by Sancepasta\n");
}