# 编译条件
CC	=	gcc
CFLAGS	=	-g -Wall

# Objs
all:	string_replace match_string represent_number_string

# Objs 函数编译
string_replace:	string_replace.o 
	$(CC) $^ -o $@
match_string: match_string.o 
	$(CC) $^ -o $@
represent_number_string: represent_number_string.o 
	$(CC) $^ -o $@

# .o 文件的编译
string_replace.o:	string_replace.c 
	$(CC) $(CFLAGS) -c $< -o $@
match_string.o: match_string.c
	$(CC) $(CFLAGS) -c $< -o $@
represent_number_string.o: represent_number_string.c
	$(CC) $(CFLAGS) -c $< -o $@

#clean
clean:	
	@echo "cleaning project"
	-rm string_replace match_string represent_number_string
	-rm *.o 
	@echo "cleaning complie"
.PHONY:	clean