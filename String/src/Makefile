OBJ_PATH = ./objects
FUN_PATH = ./functions
TESTS_PATH = ./tests
TEST_OBJ_PATH = ./tests_objects

# ADD_LIB = -lcheck -lsubunit -lpthread -lm -lrt -D_GNU_SOURCE
ADD_LIB = $(shell pkg-config --libs check)

OBJECT_FILES = $(OBJ_PATH)/*.o
SOURCE=$(wildcard $(FUN_PATH)/*.c)
TEST_SOURCE=$(wildcard $(TESTS_PATH)/*.c)

GCC_COMPILE = gcc -g -c -I ./ -Wall -Wextra -Werror
GCC_COMPILE_GCOV = gcc -g -c --coverage -I ./ $(ADD_LIB) -Wall -Wextra -Werror

GCC_BUILD_TEST = gcc -g $(TEST_OBJ_PATH)/*.o -L. -l:s21_string.a $(ADD_LIB) -o s21_test

all: clean s21_string.a

s21_string.o: s21_string.c
	$(GCC_COMPILE) s21_string.c -o s21_string.o

s21_string.a: s21_string.h $(SOURCE)
	$(GCC_COMPILE) $(SOURCE)
	mv ./*.o $(OBJ_PATH)/
	ar rc s21_string.a $(OBJECT_FILES) 
	ranlib s21_string.a

test: clean s21_string.a
	$(GCC_COMPILE) $(TEST_SOURCE) s21_test.c
	mv *.o $(TEST_OBJ_PATH)
	$(GCC_BUILD_TEST)
	./s21_test

tmp: clean tmp.c s21_string.a
	$(GCC_COMPILE) tmp.c
	gcc -g tmp.o -L. -l:s21_string.a -o tmp

gcov_report: clean $(SOURCE)
	$(GCC_COMPILE_GCOV) $(SOURCE) $(TEST_SOURCE)
	mv ./*.o $(OBJ_PATH)/
	ar rc s21_string.a $(OBJECT_FILES) 
	ranlib s21_string.a
	gcc --coverage s21_test.c s21_string.a $(ADD_LIB) s21_string.h -o s21_test 
	./s21_test
	lcov -t "s21_test" -o s21_test.info -c -d .
	genhtml -o report s21_test.info
	open ./report/index.html

clean:
	rm -fr *.o
	rm -fr $(OBJ_PATH)/*.o
	rm -fr $(TEST_OBJ_PATH)/*.o
	rm -fr ./*.gcno ./*.gcda ./*.info
	rm -fr ./report/*
	rm -fr s21_string s21_string.o s21_string.a s21_test.o s21_test s21_test tmp

format:
	clang-format -i functions/*.c
	clang-format -i tests/*.c
	clang-format -i *.c
	clang-format -i *.h

valgrind_test:
	make test
	clear
	valgrind ./s21_test
# valgrind --leak-check=full --show-reachable=yes ./s21_test
