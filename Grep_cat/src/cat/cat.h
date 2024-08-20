#ifndef CAT_H
#define CAT_H

#include <stdbool.h>
#include <stdio.h>
#include <string.h>

typedef struct flags {
  bool b;  // -b --number-nonblank
  bool n;  // -n --number
  bool E;  // -e
  bool v;  // -v
  bool s;  // -s --squeeze-blank
  bool T;  // -t
  bool flags_error;
  bool filename;
  bool new_file;
  int filesCnt;
  bool help;
} Flags;

void printFile(char *filename, Flags *flag, int *i);
int parser(int argc, char *argv[], Flags *flags);
void flags_init(Flags *flags);
void flagsAnalyser(char *string, Flags *flags);
bool filenameAnalyser(char *string);  // true если найдено имя файла
                                      //  вариант с сохранением названия файла
void printSymbol(char *symbl, Flags *flags, bool *line_numeric,
                 bool *line_empty, bool *new_line, int *i);
void printHelp();

#endif