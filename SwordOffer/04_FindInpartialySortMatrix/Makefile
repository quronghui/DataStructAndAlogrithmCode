# 编译条件
CC	=	gcc
CFLAGS	=	-g -Wall

# Ojobs
# all:	find_in_matrix
all:	mallocTwoD_array
# all:	PrintMatrixClockwisely
# objs编译
find_in_matrix:	find_in_matrix.o 
	$(CC) $^ -o $@

mallocTwoD_array:	mallocTwoD_array.o 
	$(CC) $^ -o $@

PrintMatrixClockwisely:	PrintMatrixClockwisely.o 
	$(CC) $^ -o $@

# .o文件的编译
find_in_matrix.o:	find_in_matrix.c 
	$(CC) $(CFLAGS) -c $< -o $@

mallocTwoD_array.o: mallocTwoD_array.c
	$(CC) $(CFLAGS) -c $< -o $@
	
PrintMatrixClockwisely.o: PrintMatrixClockwisely.c
	$(CC) $(CFLAGS) -c $< -o $@

#clean
clean:	
	@echo "cleaning project"
	-rm find_in_matrix mallocTwoD_array
	-rm PrintMatrixClockwisely
	-rm *.o 
	@echo "cleaning complie"
.PHONY:	clean