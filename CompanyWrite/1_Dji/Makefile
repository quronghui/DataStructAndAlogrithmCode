# compile condition
CC	=	gcc
CFLAGS	=	-g 	-Wall
INCLUDE	=	-I.
# LIB	=	-lm

#all
# all:	circularReadWrite
# all:	charConvertint
# all:	sizeofStructUnion
# all:	numberNegAddPos
all:	strncmp
# all:	test_string

# target file link
circularReadWrite:	circularReadWrite.o
	$(CC)	$^	-o	$@

charConvertint:	charConvertint.o 
	$(CC)	$^	-o	$@

sizeofStructUnion:	sizeofStructUnion.o
	$(CC)	$^	-o	$@

numberNegAddPos:	numberNegAddPos.o
	$(CC)	$^	-o	$@

strncmp:	strncmp.o
	$(CC)	$^	-o	$@

test_string:	test_string.o
	$(CC)	$^	-o	$@

# *.o file compile
circularReadWrite.o: circularReadWrite.c
	$(CC)	$(CFLAGS)	-c	$(INCLUDE)	$<	-o	$@

charConvertint.o: charConvertint.c
	$(CC)	$(CFLAGS)	-c	$(INCLUDE)	$<	-o	$@

sizeofStructUnion.o: sizeofStructUnion.c
	$(CC)	$(CFLAGS)	-c	$(INCLUDE)	$<	-o	$@

numberNegAddPos.o:	numberNegAddPos.c
	$(CC)	$(CFLAGS)	-c	$(INCLUDE)	$<	-o	$@

strncmp.o:	strncmp.c
	$(CC)	$(CFLAGS)	-c	$(INCLUDE)	$<	-o	$@

test_string.o:	test_string.c
	$(CC)	$(CFLAGS)	-c	$(INCLUDE)	$<	-o	$@

#clean
clean:	
	@echo	"cleanning compile file "
	-rm	*.o
	-rm	circularReadWrite  charConvertint
	-rm sizeofStructUnion numberNegAddPos
	-rm	strncmp test_string
	@echo	"cleanning  target file"
.PHONY:	clean