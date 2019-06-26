# 编译条件
CC	=	gcc
CFLAGS	=	-g -Wall 

#Objs
all:	one_count

###########目标文件编译###########
one_count: one_count.o 
	$(CC) $^ -o $@ 

########## .o 文件的编译#########
one_count.o: one_count.c
	$(CC) $(CFLAGS) -c $< -o $@


#clean
clean:	
	@echo "cleaning project"
	-rm one_count
	-rm *.o 
	@echo "cleaning complie"
.PHONY:	clean