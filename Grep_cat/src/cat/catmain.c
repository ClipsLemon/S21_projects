#include "./cat.h"

int main(int argc, char *argv[]) {
  Flags flags;
  flags_init(&flags);
  parser(argc, argv, &flags);
  return 0;
}

void flags_init(Flags *flags) {
  flags->b = false;  // -b --number-nonblank
  flags->n = false;  // -n --number
  flags->E = false;  // -e
  flags->v = false;  // -v
  flags->s = false;  // -s --squeeze-blank
  flags->T = false;  // -t
  flags->flags_error = false;
  flags->filename = false;
  flags->help = false;
  flags->new_file = false;
  flags->filesCnt = 0;
}
// 1
// -b (GNU: --number-nonblank)
// нумерует только непустые строки
// 2
// -e предполагает и -v (GNU only: -E то же самое, но без применения -v)
// также отображает символы конца строки как $
// 3
// -n (GNU: --number)
// нумерует все выходные строки
// 4
// -s (GNU: --squeeze-blank)
// сжимает несколько смежных пустых строк
// 5
// -t предполагает и -v (GNU: -T то же самое, но без применения -v)
// также отображает табы как ^I