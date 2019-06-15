# list

# 编译条件
CC	=	gcc
CFLAGS = -g -Wall

# objs
all:	one_list double_list

# 编译
one_list:	one_list.o
	$(CC) $^ -o $@
one_list.o:	one_list.c 
	$(CC) $(CFLAGS) -c $< -o $@

double_list:	double_list.o 
	$(CC) $^ -o $@
double_list.o:	double_list.c 
	$(CC) $(CFLAGS) -c $< -o $@

#clean
clean:	
	@echo "cleaning project"
	-rm one_list double_list
	-rm *.o 
	@echo "cleaning complie"
.PHONY:	clean