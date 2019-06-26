# 编译条件
CC	=	gcc
CFLAGS	=	-g -Wall 

#Objs
all:	Dynamic_maxProduct Greedy_maxProduct

###########目标文件编译###########
Dynamic_maxProduct:	Dynamic_maxProduct.o 
	$(CC) $^ -o $@

## 编译时，需要链接数学库 -lm
Greedy_maxProduct:	Greedy_maxProduct.o 
	$(CC) $^ -o $@ -lm

########## .o 文件的编译#########
Dynamic_maxProduct.o: Dynamic_maxProduct.c
	$(CC) $(CFLAGS) -c $< -o $@

Greedy_maxProduct.o: Greedy_maxProduct.c
	$(CC) $(CFLAGS) -c $< -o $@

#clean
clean:	
	@echo "cleaning project"
	-rm Dynamic_maxProduct Greedy_maxProduct
	-rm *.o 
	@echo "cleaning complie"
.PHONY:	clean