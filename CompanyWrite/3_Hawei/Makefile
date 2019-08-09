# compile condition
CC	=	gcc
CFLAGS	=	-g 	-Wall
INCLUDE	=	-I.

#all
all:	first

# target file link

first:	first.o
	$(CC)	$^	-o	$@

# *.o file compile

first.o:	first.c
	$(CC)	$(CFLAGS)	-c	$(INCLUDE)	$<	-o	$@

#clean
clean:	
	@echo	"cleanning compile file "
	-rm	*.o
	-rm	 first
	@echo	"cleanning  target file"
.PHONY:	clean