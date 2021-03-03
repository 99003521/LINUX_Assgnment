# TARGET=hall.out
# OBJS=test.o src/mystring.o src/myutils.o src/bitmask.o
# TOPDIR=${PWD}

# run:
# 	gcc 
# clean:
# 	rm -rf ${OBJS} ${TARGET}
PROJECTNAME = ASSIGNMENT1
TARGET=hall.out
OBJS=test.o src/mystring.o src/myutils.o src/bitmask.o
TOPDIR=${PWD}
INC = -Iinc
LDFLAGS = -lmyutils -lmystring -lbitmask -Lsrc
build:
	gcc test.c ./src/myutils.c ./src/mystring.c ./src/bitmask.c ./unity/unity.c
run:
	./a.out
clean:
	rm -rf ${OBJS} ${TARGET}

libraries: 
	make libmystring -C src
	make libmyutils -C src
	make libbitmask -C src
