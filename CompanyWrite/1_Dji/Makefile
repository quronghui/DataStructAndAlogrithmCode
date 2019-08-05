# compile condition
CC	=	gcc
CFLAGS	=	-g 	-Wall
INCLUDE	=	-I.

#all
# all:	circularReadWrite
all:	charConvertint
# all:	sizeofStructUnion
# all:	numberNegAddPos

# target file link
circularReadWrite:	circularReadWrite.o
	$(CC)	$^	-o	$@

charConvertint:	charConvertint.o 
	$(CC)	$^	-o	$@

sizeofStructUnion:	sizeofStructUnion.o
	$(CC)	$^	-o	$@

numberNegAddPos:	numberNegAddPos.o
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

#clean
clean:	
	@echo	"cleanning compile file "
	-rm	*.o
	-rm	circularReadWrite  charConvertint
	-rm sizeofStructUnion numberNegAddPos
	@echo	"cleanning  target file"
.PHONY:	clean