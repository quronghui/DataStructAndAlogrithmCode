# Makefile
# 编译条件
CC	=	gcc
CFLAGS = -Wall -g 

# 目标文件
all:	duplicate_array duplicate_no_edit_array

# 编译
duplicate_array:	duplicate_array.o
	$(CC) $^ -o $@
duplicate_array.o:	duplicate_array.c
	$(CC) $(CFLAGS) -c $< -o $@

duplicate_no_edit_array:	duplicate_no_edit_array.o
	$(CC) $^ -o $@
duplicate_no_edit_array.o:	duplicate_no_edit_array.c
	$(CC) $(CFLAGS) -c $< -o $@

# clean
clean:
	@echo "cleaning project"
	-rm duplicate_array duplicate_no_edit_array
	-rm *.o
	@echo "cleaning complie"
.PHONY:	clean