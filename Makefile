.PHONY: all build install test clean gcov_report uninstall dist dvi linter linter_wow cppcheck

CC = gcc
FLAGS = -Wall -Wextra -Werror -std=c11
TESTFILE = test
GCOV_FLAG = -lgcov --coverage

LIBS_FOR_CHECK_PCKG =
D_OS =
OS = $(shell uname -s)
ifeq ($(OS), Linux)
	LIBS_FOR_CHECK_PCKG = -lcheck -lsubunit -lm -lpthread -lrt
	D_OS = -D __My_Linux__
else
	LIBS_FOR_CHECK_PCKG = -lcheck -lm -lpthread
	D_OS = -D __My_APPLE__
endif

all: build

build: clean
	-mkdir Build 
	cd Build; qmake ../SmartCalc/SmartCalc.pro
	make -C Build > /dev/null 

install: build
	-mkdir CoolFolder
	mv Build/SmartCalc.app CoolFolder

test:
	$(CC) -g polka.c testik.c $(LIBS_FOR_CHECK_PCKG) -o test 
	./test

clean:
	rm -f *.a *.o *.so *.out $(TESTFILE) $(TESTFILE).c *.info *.gcno *.gcda leak.log *.gz
	rm -rf report
	rm -rf *.gch
	rm -rf Build
	rm -rf SmartCalc.install



gcov_report:
	$(CC)  $(GCOV_FLAG) testik.c polka.c $(LIBS_FOR_CHECK_PCKG) -o $(TESTFILE)
	./$(TESTFILE)
	lcov -t "BigFuckingBolls" -o $(TESTFILE).info -c -d .
	genhtml -o report $(TESTFILE).info
	open ./report/index.html
	rm -f test

uninstall:
	rm -rf CoolFolder

dist:
	tar -czf SmartCalc.install.tar.gz ./*

dvi:
	open ./dvi.html

linter:
	clang-format -n -style=google *.c *.h 

linter_wow:
	clang-format -i -style=google *.c *.h 

