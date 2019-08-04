# compile condition
CC	=	gcc
CFLAGS	=	-g 	-Wall
INCLUDE	=	-I.

#all
all:	circularReadWrite

# target file link
circularReadWrite:	circularReadWrite.o
	$(CC)	$^	-o	$@

# *.o file compile
circularReadWrite.o: circularReadWrite.c
	$(CC)	$(CFLAGS)	-c	$(INCLUDE)	$<	-o	$@


#clean
clean:	
	@echo	"cleanning compile file "
	-rm	*.o
	-rm	circularReadWrite 
	@echo	"cleanning  target file"
.PHONY:	clean