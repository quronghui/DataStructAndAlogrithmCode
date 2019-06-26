# 编译条件
CC	=	gcc
CFLAGS	=	-g -Wall

#Objs
all:	 Fibonacci 

###########目标文件编译###########
Fibonacci:	Fibonacci.o 
	$(CC) $^ -o $@


########## .o 文件的编译#########
Fibonacci.o: fibonacci.c
	$(CC) $(CFLAGS) -c $< -o $@

#clean
clean:	
	@echo "cleaning project"
	-rm  Fibonacci
	-rm *.o 
	@echo "cleaning complie"
.PHONY:	clean