# compile condition
CC	=	gcc
CFLAGS	=	-g 	-Wall
INCLUDE	=	-I.

#all
# all:	grade
all:	calculation

# target file link

grade:	grade.o
	$(CC)	$^	-o	$@

calculation:	calculation.o
	$(CC)	$^	-o	$@

# *.o file compile

grade.o:	grade.c
	$(CC)	$(CFLAGS)	-c	$(INCLUDE)	$<	-o	$@

calculation.o:	calculation.c
	$(CC)	$(CFLAGS)	-c	$(INCLUDE)	$<	-o	$@

#clean
clean:	
	@echo	"cleanning compile file "
	-rm	*.o
	-rm	 grade calculation
	@echo	"cleanning  target file"
.PHONY:	clean