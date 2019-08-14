# compile condition
CC	=	gcc
CFLAGS	=	-g 	-Wall
INCLUDE	=	-I.
LIB	=	-lm

#all
# all:	string_analysis
all:	secode

# target file link
string_analysis:	string_analysis.o
	$(CC)	$^	-o	$@

secode:	secode.o
	$(CC)	$^	-o	$@


# *.o file compile
string_analysis.o:	string_analysis.c
	$(CC)	$(CFLAGS)	-c	$(INCLUDE)	$<	-o	$@

secode.o:	secode.c
	$(CC)	$(CFLAGS)	-c	$(INCLUDE)	$<	-o	$@

#clean
clean:	
	@echo	"cleanning compile file "
	-rm	*.o
	-rm	 string_analysis secode
	@echo	"cleanning  target file"
.PHONY:	clean