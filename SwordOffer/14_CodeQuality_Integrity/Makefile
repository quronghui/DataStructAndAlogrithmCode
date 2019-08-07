# 编译条件
CC	=	gcc
CFLAGS	=	-g -Wall 

#Objs
all:	math_funcation_pow print_oneToMaxBit_number

###########目标文件编译###########
math_funcation_pow: math_funcation_pow.o 
	$(CC) $^ -o $@ 

########## .o 文件的编译#########
math_funcation_pow.o: math_funcation_pow.c
	$(CC) $(CFLAGS) -c $< -o $@

#clean
clean:	
	@echo "cleaning project"
	-rm math_funcation_pow 
	-rm print_oneToMaxBit_number
	-rm *.o 
	@echo "cleaning complie"
.PHONY:	clean