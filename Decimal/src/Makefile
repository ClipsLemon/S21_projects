OS := $(shell uname)
ifeq ($(OS),Linux) # определяем ОС
	TEST_LIBS = -lcheck -lrt -lsubunit -lm -lpthread
else
	TEST_LIBS = -lcheck -lpthread -lm
endif

# Флаги компиляции и сборки
CC = gcc
CFLAGS = -std=c11 -g -Wall -Werror -Wextra 
CFLAGS_TESTS = -g -lcheck -lsubunit -lpthread -lm -lrt -D_GNU_SOURCE -Wall -Wextra -Werror
INC = -I. -lm
GCC_COMPILE_GCOV = gcc -std=c11 -g -c --coverage -I ./ $(TEST_LIBS)  -Wall -Wextra -Werror


# Имя статической библиотеки
LIB = s21_decimal.a


# -------------------- ОСНОВНЫЕ ФАЙЛЫ -------------------------
# Путь к исходным файлам
SRC_DIR = functions
OBJ_DIR = objects

# Получение имен подкаталогов в директории SRC_DIR
SUBDIRS := $(shell find $(SRC_DIR) -type d)

# Получение списка исходных файлов
SRCS := $(foreach dir,$(SUBDIRS),$(wildcard $(dir)/*.c))

# Преобразование имен исходных файлов в имена объектных файлов
OBJS := $(patsubst %.c,$(OBJ_DIR)/%.o,$(SRCS))
# -------------------------------------------------------------


# ------------------------ ТЕСТЫ ------------------------------
SRC_TEST_DIR = tests
OBJ_TEST_DIR = tests_objects

# Получение имен подкаталогов в директории SRC_DIR
TEST_SUBDIRS := $(shell find $(SRC_TEST_DIR) -type d)

# Получение списка исходных файлов
TEST_SRCS := $(foreach dir,$(TEST_SUBDIRS),$(wildcard $(dir)/*.c))

# Преобразование имен исходных файлов в имена объектных файлов
TEST_OBJS := $(patsubst %.c,$(OBJ_TEST_DIR)/%.o,$(TEST_SRCS))
# -------------------------------------------------------------


all: $(LIB) gcov_report

# Компиляция исходных файлов в объектные файлы
$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

# Создание статической библиотеки
$(LIB): $(OBJS)
	ar rcs $@ $^

# Компиляция исходных файлов тестов в объектные файлы
$(OBJ_TEST_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS_TESTS) $(INC) -c $< -o $@

# Компиляция и запуск тестов
test: clean $(LIB) $(TEST_OBJS)
	gcc -g $(OBJ_TEST_DIR)/$(SRC_TEST_DIR)/*.o -L. -l:$(LIB) -lcheck -lsubunit -lpthread -lm -lrt -D_GNU_SOURCE -o s21_test
	./s21_test

gcov_report: clean 
	$(GCC_COMPILE_GCOV) $(SRCS) ./tests/*.c
	mv ./*.o ./$(OBJ_DIR)/
	ar rc s21_decimal.a ./objects/*.o 
	ranlib s21_decimal.a
	gcc --coverage ./tests/s21_test.c s21_decimal.a $(TEST_LIBS) s21_decimal.h -o s21_test 
	./s21_test
	lcov -t "s21_test" -o s21_test.info -c -d .
	genhtml -o report s21_test.info
	open ./report/index.html

clean:
	rm -rf $(OBJ_TEST_DIR)/$(SRC_TEST_DIR)
	rm -rf $(OBJ_DIR)/$(SRC_DIR)
	rm -f *.a $(OBJ_DIR)/*.o ./s21_decimal ./s21_test ./s21_decimal.o
	rm -fr *.gcno *.gcda s21_test.info ./report

format:
	cp ../materials/linters/.clang-format .
	clang-format -i *.h functions/arithmetic/*.c functions/compare/*.c functions/converters/*.c functions/other/*.c tests/*.c tests/*.h
	rm -f ./.clang-format