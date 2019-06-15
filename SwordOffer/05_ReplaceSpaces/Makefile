# 编译条件
CC	=	gcc
CFLAGS	=	-g -Wall

# Objs
all:	string_replace

# 编译
string_replace:	string_replace.o 
	$(CC) $^ -o $@
string_replace.o:	string_replace.c 
	$(CC) $(CFLAGS) -c $< -o $@

#clean
clean:	
	@echo "cleaning project"
	-rm string_replace
	-rm *.o 
	@echo "cleaning complie"
.PHONY:	clean