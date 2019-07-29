# 编译条件
CC	=	gcc
CFLAGS	=	-g -Wall 

#Objs
# all:	Dynamic_maxProduct Greedy_maxProduct
# all:	get_MaxValue_inMatrix
all:	longSubstring_withoutDup
###########目标文件编译###########
Dynamic_maxProduct:	Dynamic_maxProduct.o 
	$(CC) $^ -o $@

## 编译时，需要链接数学库 -lm
Greedy_maxProduct:	Greedy_maxProduct.o 
	$(CC) $^ -o $@ -lm

get_MaxValue_inMatrix:	get_MaxValue_inMatrix.o
	$(CC) $^ -o $@ -lm

longSubstring_withoutDup:	longSubstring_withoutDup.o
	$(CC) $^ -o $@ -lm


########## .o 文件的编译#########
Dynamic_maxProduct.o: Dynamic_maxProduct.c
	$(CC) $(CFLAGS) -c $< -o $@

Greedy_maxProduct.o: Greedy_maxProduct.c
	$(CC) $(CFLAGS) -c $< -o $@

get_MaxValue_inMatrix.o: get_MaxValue_inMatrix.c
	$(CC) $(CFLAGS) -c $< -o $@

longSubstring_withoutDup.o: longSubstring_withoutDup.c
	$(CC) $(CFLAGS) -c $< -o $@

#clean
clean:	
	@echo "cleaning project"
	-rm Dynamic_maxProduct Greedy_maxProduct
	-rm get_MaxValue_inMatrix longSubstring_withoutDup
	-rm *.o 
	@echo "cleaning complie"
.PHONY:	clean