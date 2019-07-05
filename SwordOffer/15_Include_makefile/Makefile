#Objs
all:	array_queue

# 编译条件
CC	=	gcc
CFLAGS =	-g -Wall
INCLUDE = -I. -Iarray	# 目录

array_malloc_queue	=	array_malloc_queue.a		# 子目录下Makefile 最后生成的文件名

################# 目标文件的编译################
array_queue:	main.o $(array_malloc_queue)
	$(CC)  $^ -o $@

################# 目标.o 文件的编译################

$(array_malloc_queue):		# 子目录下Make编译文件
	(cd array;$(MAKE))

# 不用加array_queue_interface.h文件，我们在生成目标文件时进行链接
main.o: main.c 
	$(CC) $(CFLAGS) -c $(INCLUDE) $< -o $@


#clean
clean:	
	@echo "cleaning project"
	-rm  array_queue $(array_malloc_queue)
	-rm *.o 
	@echo "cleaning complie"
.PHONY:	clean