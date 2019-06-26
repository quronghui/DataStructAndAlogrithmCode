# 编译条件
CC	=	gcc
CFLAGS	=	-g -Wall

#Objs
all:	 matrix_path moving_count

###########目标文件编译###########
matrix_path:	matrix_path.o 
	$(CC) $^ -o $@

moving_count:	moving_count.o
	$(CC) $^ -o $@

########## .o 文件的编译#########
matrix_path.o: matrix_path.c
	$(CC) $(CFLAGS) -c $< -o $@

moving_count.o: moving_count.c
	$(CC) $(CFLAGS) -c $< -o $@


#clean
clean:	
	@echo "cleaning project"
	-rm  matrix_path moving_count
	-rm *.o 
	@echo "cleaning complie"
.PHONY:	clean