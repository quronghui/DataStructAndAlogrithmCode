# compile condition
CC	=	gcc
CFLAGS	=	-g 	-Wall
INCLUDE	=	-I.

#all
all:	grade

# target file link

grade:	grade.o
	$(CC)	$^	-o	$@

# *.o file compile

grade.o:	grade.c
	$(CC)	$(CFLAGS)	-c	$(INCLUDE)	$<	-o	$@

#clean
clean:	
	@echo	"cleanning compile file "
	-rm	*.o
	-rm	 grade
	@echo	"cleanning  target file"
.PHONY:	clean