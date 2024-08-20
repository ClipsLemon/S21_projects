s21_cat: cat_parse.o cat_print.o catmain.o
	gcc cat_parse.o cat_print.o catmain.o -o s21_cat
cat_parse.o:
	gcc -c -Wall -Wextra -Werror -o cat_parse.o cat_parse.c
cat_print.o:
	gcc -c -Wall -Wextra -Werror -o cat_print.o cat_print.c
catmain.o:
	gcc -c -Wall -Wextra -Werror -o catmain.o catmain.c

cat_tests:
	bash tests.sh
	bash test_cat.sh

cat_leaks:
	bash test_leaks.sh

clean:
	rm -f *.o 
	rm -f *.log
	rm -f s21_cat
	rm -f outputs/*