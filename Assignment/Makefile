TARGET=hall.out
OBJS=test.o src/mystring.o src/myutils.o src/bitmask.o
TOPDIR=${PWD}

build:
	gcc test.c ./src/myutils.c ./src/mystring.c ./src/bitmask.c ./unity/unity.c
run:
	./a.out
clean:
	rm -rf ${OBJS} ${TARGET}