# 编译条件
CC	=	gcc
CFLAGS	=	-g -Wall

# Ojobs
all:	find_in_matrix

# 编译
find_in_matrix:	find_in_matrix.o 
	$(CC) $^ -o $@
find_in_matrix.o:	find_in_matrix.c 
	$(CC) $(CFLAGS) -c $< -o $@

#clean
clean:	
	@echo "cleaning project"
	-rm find_in_matrix
	-rm *.o 
	@echo "cleaning complie"
.PHONY:	clean