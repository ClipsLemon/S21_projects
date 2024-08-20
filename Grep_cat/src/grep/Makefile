s21_grep: grep_parse.o grep_print.o grep_main.o
	gcc -Wall -Wextra -Werror -o s21_grep grep_parse.o grep_print.o grep_main.o

grep_parse.o:
	gcc -c -Wall -Wextra -Werror -o grep_parse.o grep_parse.c

grep_print.o:
	gcc -c -Wall -Wextra -Werror -o grep_print.o grep_print.c

grep_main.o:
	gcc -c -Wall -Wextra -Werror -o grep_main.o grep_main.c

grep_tests:
	bash test_grep.sh

grep_leaks:
	bash test_leaks.sh

clean:
	rm -f *.o 
	rm -f *.log
	rm -f s21_grep
	rm -f outputs/*