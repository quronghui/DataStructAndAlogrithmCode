# 编译条件
CC	=	gcc
CFLAGS	=	-g -Wall 

#Objs
# all:	one_count
# all:	findNumsOnce xor_test
# all:	findAppearOnce
all:	addTwoNumber

###########目标文件编译###########
one_count: one_count.o 
	$(CC) $^ -o $@ 

findNumsOnce:	findNumsOnce.o 
	$(CC) $^ -o $@ 

xor_test:	xor_test.o 
	$(CC) $^ -o $@ 

findAppearOnce:	findAppearOnce.o 
	$(CC) $^ -o $@ 

addTwoNumber: addTwoNumber.o
	$(CC) $^ -o $@ 

########## .o 文件的编译#########
one_count.o: one_count.c
	$(CC) $(CFLAGS) -c $< -o $@

findNumsOnce.o: findNumsOnce.c
	$(CC) $(CFLAGS) -c $< -o $@
 
xor_test.o: xor_test.c
	$(CC) $(CFLAGS) -c $< -o $@

findAppearOnce.o: findAppearOnce.c
	$(CC) $(CFLAGS) -c $< -o $@

addTwoNumber.o:		addTwoNumber.c
	$(CC) $(CFLAGS) -c $< -o $@


#clean
clean:	
	@echo "cleaning project"
	-rm one_count	findNumsOnce
	-rm xor_test	findAppearOnce
	-rm	addTwoNumber
	-rm *.o 
	@echo "cleaning complie"
.PHONY:	clean