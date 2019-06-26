# 编译条件
CC	=	gcc
CFLAGS	=	-g -Wall

#Objs
all:	 quick_sort rotating_array

###########目标文件编译###########
quick_sort:	quick_sort.o 
	$(CC) $^ -o $@

rotating_array:	rotating_array.o
	$(CC) $^ -o $@

########## .o 文件的编译#########
quick_sort.o: quick_sort.c
	$(CC) $(CFLAGS) -c $< -o $@

rotating_array.o:	rotating_array.c 
	$(CC) $(CFLAGS) -c $< -o $@


#clean
clean:	
	@echo "cleaning project"
	-rm  quick_sort rotating_array
	-rm *.o 
	@echo "cleaning complie"
.PHONY:	clean