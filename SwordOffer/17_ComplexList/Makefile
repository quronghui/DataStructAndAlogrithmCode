# Objs
all:	complexListCopy

############ 编译条件 ###########
CC	=	gcc
CFLAGS	=	-g -Wall
INCLUDE	=	-I.

########## 目标文件编译 ##########
complexListCopy:	complexListCopy.o complexList.o 
	$(CC)	$^ -o $@


######### .o 文件的编译 ##########
complexList.o: complexList.c complexList.h
	$(CC) $(CFLAGS) -c $(INCLUDE) $< -o $@

complexListCopy.o: complexListCopy.c complexList.h
	$(CC) $(CFLAGS) -c $(INCLUDE) $< -o $@



#clean
clean:	
	@echo "cleanning project"
	-rm	complexListCopy
	-rm	*.o
	@echo "cleanning complie"
.PHONY:	clean