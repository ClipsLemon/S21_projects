#определяем переменные для системы
OS := $(shell uname)
CPPFLAGS = -std=c++17 -pedantic -g -Wall -Werror -Wextra
INC = -I ./
GPP = g++ -fdiagnostics-color=always

# Путь к исходным файлам
SRC_DIR = functions
OBJ_DIR = objects
TEST_DIR = tests
TEST_OBJ_DIR = tests_objects
# Получение имен подкаталогов в директории SRC_DIR
SUBDIRS := $(shell find $(SRC_DIR) -type d)
TEST_SUBDIRS := $(shell find $(TEST_DIR) -type d)


# Получение списка исходных файлов
SRCS := $(foreach dir,$(SUBDIRS),$(wildcard $(dir)/*.cpp))
TEST_SRCS := $(foreach dir,$(TEST_SUBDIRS),$(wildcard $(dir)/*.cpp))


# Преобразование имен исходных файлов в имена объектных файлов
OBJS := $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/$(SRC_DIR)/%.o,$(SRCS))
TEST_OBJS := $(patsubst $(TEST_DIR)/%.cpp,$(TEST_OBJ_DIR)/$(TEST_DIR)/%.o,$(TEST_SRCS))

# Имя статической библиотеки
LIB = s21_matrix_oop.a

ifeq ($(OS),Linux) # определяем ОС
	TEST_LIBS = -lgtest -lgtest_main -pthread
	GPP_COMPILE_BUILD = $(GPP) $(CPPFLAGS) 
	ADD_LIB = $(INC) -L. -l:$(LIB) 
	GPP_COMPILE_TEST = $(GPP) $(CPPFLAGS)
else
	TEST_LIBS = -lgtest
	GPP_COMPILE_BUILD = $(GPP) $(CPPFLAGS) 
	ADD_LIB = $(INC) $(LIB) 
	GPP_COMPILE_TEST = $(GPP) $(CPPFLAGS)
endif

GPP_COMPILE_GCOV = $(GPP) $(CPPFLAGS) --coverage


all: clean test

# Компиляция исходных файлов в объектные файлы
$(OBJ_DIR)/$(SRC_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(dir $@)
	$(GPP) $(CPPFLAGS) -c $< -o $@

# Компиляция тестовых файлов в объектные файлы
$(TEST_OBJ_DIR)/$(TEST_DIR)/%.o: $(TEST_DIR)/%.cpp
	@mkdir -p $(dir $@)
	$(GPP_COMPILE_TEST) -c $(TEST_LIBS) $< -o $@ 

# Создание статической библиотеки 
$(LIB): $(OBJS)
	ar rcs $@ $^

test: $(TEST_OBJS) $(LIB)  
	$(GPP_COMPILE_BUILD) -c main_test.cpp  -o main_test.o
	$(GPP_COMPILE_BUILD) $(TEST_OBJ_DIR)/$(TEST_DIR)/*.o main_test.o $(ADD_LIB) $(TEST_LIBS) -o main_test
	./main_test


gcov_report: clean
	$(GPP_COMPILE_GCOV) -c $(SRCS)
	mv ./*.o ./$(OBJ_DIR)/$(SRC_DIR)/
	ar rc s21_matrix_oop.a ./$(OBJ_DIR)/$(SRC_DIR)/*.o 
	ranlib s21_matrix_oop.a

	$(GPP_COMPILE_GCOV) -c  $(TEST_DIR)/*.cpp
	mv ./*.o ./$(TEST_OBJ_DIR)/$(TEST_DIR)/
	$(GPP_COMPILE_GCOV) -c main_test.cpp -o main_test.o
	$(GPP_COMPILE_GCOV) ./$(TEST_OBJ_DIR)/$(TEST_DIR)/*.o main_test.o $(ADD_LIB) $(TEST_LIBS) -o main_test

	./main_test
	
ifeq ($(OS),Linux)
	lcov -t "main_test" -o main_test.info --no-external -c -d .
else
	lcov -t "main_test" -o main_test.info --no-external -c -d .  --ignore-errors inconsistent
endif
	genhtml -o report main_test.info
	mv *.gcda gcov_objects
	mv *.gcno gcov_objects
	open ./report/index.html

clean:
	rm -rf *.a ./*.o ./main_test
	rm -rf $(OBJ_DIR)/$(SRC_DIR)/*.o $(TEST_OBJ_DIR)/$(TEST_DIR)/*.o   
	rm -fr main_test.info ./report ./gcov_objects/*.gcda ./gcov_objects/*.gcno ./*.gcno ./*.gcda
	rm -f valgrind_report.txt leaks_report.txt

format:
	cp ../materials/linters/.clang-format ./
	clang-format -n *.cpp *.h functions/*.cpp 
	clang-format -n *.cpp *.h tests/*.cpp 
	clang-format -i *.cpp *.h functions/*.cpp 
	clang-format -i *.cpp *.h tests/*.cpp 
	clang-format -n *.cpp *.h functions/*.cpp 
	rm .clang-format

valgrind_test: clean $(LIB) test
	valgrind --tool=memcheck --leak-check=full --track-origins=yes ./main_test 2> valgrind_report.txt

leaks_test: clean $(LIB) test
	leaks -atExit -- ./main_test > leaks_report.txt

.PHONY: clean