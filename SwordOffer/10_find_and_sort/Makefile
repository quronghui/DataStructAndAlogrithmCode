# 编译条件
CC	=	gcc
CFLAGS	=	-g -Wall
INCLUDE	=	-I.
#Objs
# all:	 quick_sort rotating_array
# all:	moreHalfNum
all:	getLeastNumber
###########目标文件编译###########
quick_sort:	quick_sort.o 
	$(CC) $^ -o $@

rotating_array:	rotating_array.o
	$(CC) $^ -o $@

moreHalfNum:	moreHalfNum.o quick_sort.o 
	$(CC) $^ -o $@

getLeastNumber:	getLeastNumber.o quick_sort.o 
	$(CC) $^ -o $@

########## .o 文件的编译#########
quick_sort.o: quick_sort.c
	$(CC) $(CFLAGS) -c $(INCLUDE) $< -o $@

rotating_array.o:	rotating_array.c 
	$(CC) $(CFLAGS) -c $(INCLUDE) $< -o $@

moreHalfNum.o: moreHalfNum.c quick_sort.h
	$(CC) $(CFLAGS) -c $(INCLUDE) $< -o $@

getLeastNumber.o: getLeastNumber.c quick_sort.h
	$(CC) $(CFLAGS) -c $(INCLUDE) $< -o $@

#clean
clean:	
	@echo "cleaning project"
	-rm  quick_sort rotating_array
	-rm moreHalfNum getLeastNumber
	-rm *.o 
	@echo "cleaning complie"
.PHONY:	clean