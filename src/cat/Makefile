FLAGS = -Wall -Werror -Wextra

SRC_CAT = $(shell find . -name '*.c')
OBJ_CAT := $(SRC_CAT:.c=.o)

TEST = $(shell find ./tests -name '*.sh')
LIB = $(shell find . -name '*.a')

FLAGS_TEST = -lcheck -lgcov -coverage
FLAGS_COV = -lcheck -lgcov -fprofile-arcs --coverage

TSAN = -g -fsanitize=thread
ASAN = -g -fsanitize=address
USAN = -g -fsanitize=undefined

PEDANT = -std=c11 -pedantic

all: clean s21_cat

s21_cat: $(OBJ_CAT)
	gcc $(FLAGS) $(OBJ_CAT) $(PEDANT) -o ./s21_cat

$(OBJ_CAT): %.o: %.c
	gcc -c $(FLAGS) $< -o $@

clean:
	rm -rf *.o *.out *.txt s21_cat

test:
	chmod +x $(TEST)
	sh $(TEST)

lint:
	cp ../../materials/linters/CPPLINT.cfg ./
	python3 ../../materials/linters/cpplint.py --extensions=c *.c > linters.txt
	python3 ../../materials/linters/cpplint.py --extensions=h *.h >> linters.txt
	rm -rf ./CPPLINT.cfg *.o

asan:
	gcc $(FLAGS) $(ASAN) -g -c *.c

leak:
	leaks --atExit -- ./s21_cat -best tests/bytes.txt