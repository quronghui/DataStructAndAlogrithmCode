# 编译条件
CC	=	gcc
CFLAGS	=	-g -Wall
LIB	=	-lm

#Objs
# all:	 Fibonacci 
# all:	dicesProbability
# all:	continueCard
# all:	lastNumberCricle
all:	accumulate
###########目标文件编译###########
Fibonacci:	Fibonacci.o 
	$(CC) $^ -o $@

dicesProbability:	dicesProbability.o 
	$(CC) $^ -o $@	$(LIB)

continueCard:	continueCard.o 
	$(CC) $^ -o $@

lastNumberCricle:	lastNumberCricle.o 
	$(CC) $^ -o $@

accumulate:	accumulate.o 
	$(CC) $^ -o $@

########## .o 文件的编译#########
Fibonacci.o: fibonacci.c
	$(CC) $(CFLAGS) -c $< -o $@

dicesProbability.o: dicesProbability.c
	$(CC) $(CFLAGS) -c $< -o $@

continueCard.o: continueCard.c
	$(CC) $(CFLAGS) -c $< -o $@

lastNumberCricle.o: lastNumberCricle.c
	$(CC) $(CFLAGS) -c $< -o $@

accumulate.o: accumulate.c
	$(CC) $(CFLAGS) -c $< -o $@

#clean
clean:	
	@echo "cleaning project"
	-rm  Fibonacci	dicesProbability
	-rm continueCard	lastNumberCricle
	-rm	accumulate
	-rm *.o 
	@echo "cleaning complie"
.PHONY:	clean