#include "grep.h"

typedef int bool;

int main(int argc, char *argv[]) {
  Flags flags;
  flags_init(&flags);
  parser(&argc, argv, &flags);
  return 0;
}

void flags_init(Flags *flags) {
  flags->e = FALSE;
  flags->temp_pos = 0;
  flags->i = FALSE;
  flags->v = FALSE;
  flags->c = FALSE;
  flags->l = FALSE;
  flags->n = FALSE;
  flags->h = FALSE;
  flags->s = FALSE;
  flags->error = FALSE;
}
