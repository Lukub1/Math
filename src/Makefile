CC=gcc -std=c11 -D_GNU_SOURCE
CFLAGS=-c -Wall -Wextra -Werror -g

all: clean s21_math.a test gcov_report

s21_math: s21_math.o
	@$(CC) s21_math.o -lm -o s21_math
	@./s21_math

s21_math.o: s21_math.c s21_math.h
	@$(CC) $(CFLAGS) s21_math.c s21_math.h

s21_math.a: s21_math.o
	@ar -rcs s21_math.a s21_math.o
	@ranlib $@
	@cp $@ lib$@


clean:
	@rm -rf *.out *.o *.gch  log.txt logTest.txt s21_math
	@rm -rf coverage *.a *.gcda *gcno *.info Test *.cfg


OS = $(shell uname)
ifeq ($(OS), Linux)
	LINUX_LIBS=-lsubunit -lrt -lpthread -lm
	CC += -D OS_LINUX -g
	CHECK_LEAKS=valgrind --leak-check=full -s --log-file=log.txt
	OPEN_GCOV=firefox coverage/src/index.html
else
	LINUX_LIBS=
	CC += -D OS_MAC
	CHECK_LEAKS=CK_FORK=no leaks --atExit --
	OPEN_GCOV=open coverage/index.html
endif

test:
	@cppcheck s21_math.c s21_math.h s21_math_test.c s21_math_test.h
	@cp ../materials/linters/CPPLINT.cfg CPPLINT.cfg
	@python3 ../materials/linters/cpplint.py --extension=c s21_math.c s21_math.h s21_math_test.c s21_math_test.h
	@$(CC)  s21_math.c s21_math.h s21_math_test.c s21_math_test.h -lcheck $(LINUX_LIBS) -o ./Test
	@$(CHECK_LEAKS) ./Test
	@rm CPPLINT.cfg Test



gcov_report: s21_math.c s21_math_test.c s21_math.h
	@$(CC) -fprofile-arcs -ftest-coverage s21_math_test.c s21_math.c -o Test -lcheck $(LINUX_LIBS) $(GCOV)
	@./Test
	@lcov -c -d . -o coverage.info
	@genhtml coverage.info -o coverage
	@$(OPEN_GCOV)

s21_math_test.o: s21_math_test.c s21_math.h
	@$(CC) $(CFLAGS) s21_math_test.c

