FLAGS = -Wall -Werror -Wextra

SRC_GREP = $(shell find . -name '*.c')
OBJ_GREP := $(SRC_GREP:.c=.o)

TEST = $(shell find ./tests -name '*.sh')
LIB = $(shell find . -name '*.a')

FLAGS_TEST = -lcheck -lgcov -coverage
FLAGS_COV = -lcheck -lgcov -fprofile-arcs --coverage

TSAN = -g -fsanitize=thread
ASAN = -g -fsanitize=address
USAN = -g -fsanitize=undefined

PEDANT = -std=c11 -pedantic

all: clean s21_grep

s21_grep: $(OBJ_GREP)
	gcc $(FLAGS) $(OBJ_GREP) $(PEDANT) -o ./s21_grep

$(OBJ_GREP): %.o: %.c
	gcc -c $(FLAGS) $< -o $@

clean:
	rm -rf *.o *.out *.txt s21_grep

test:
	chmod +x $(TEST)
	sh $(TEST)

lint:
	cp ../../materials/linters/CPPLINT.cfg ./
	python3 ../../materials/linters/cpplint.py --extensions=c *.c > linters.txt
	python3 ../../materials/linters/cpplint.py --extensions=h *.h >> linters.txt
	rm -rf ./CPPLINT.cfg *.o

asan:
	gcc $(FLAGS) $(USAN) -g -c *.c

leak:
	leaks --atExit -- ./s21_grep -e struct -e ^int s21_grep.c s21_grep.h