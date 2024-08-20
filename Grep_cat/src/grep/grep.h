#include <regex.h>
#include <stdio.h>
#include <stdlib.h>

typedef int bool;

#define TRUE 1
#define FALSE 0

typedef struct flags {
  bool e;  // явно указывает что после него идет шаблон   | done
  int temp_pos;  // вспом переменная, указывает позицию шаблона когда есть e и
                 // когда нет e
  bool i;  // игнорирует регистры                         | done
  bool v;  // инвертирует символы                         | done
  bool c;  // выводит название файла и кол-во совпадений  | done выключает n
  bool l;  // выводит файлы в которых есть совпадение     | done выключате n c
  bool n;  // вывод номер строки с совпадение             | done
  bool h;  // выкл печать названия файла               | done зануляет filesCnt
  bool s;  // выключает вывод ошибок связанных с файлами  | done
  bool error;
} Flags;

void parser(int *argc, char *argv[], Flags *flags);
void flagsAnalyser(char *string, Flags *flags, int *filesCnt, const int *i);
void flags_init(Flags *flags);
bool filenameAnalyser(char *string);
char *getString(FILE *file, bool *endFile);
void printString(Flags *flags, char *str, int *index, int *match);
int printFile(char *filename, Flags *flags, char *template_string,
              int *filesCnt);