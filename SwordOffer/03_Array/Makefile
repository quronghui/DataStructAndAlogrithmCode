# Makefile
# 编译条件
CC	=	gcc
CFLAGS = -Wall -g 

# 目标文件
#all:	duplicate_array duplicate_no_edit_array
#all:	reorder_OddEven_array 
# all:	maxSum_continueArray
# all:	uglyNumber
# all:	twoNumberWithSum
all:	continueSeqWithSum

# Objs编译
duplicate_array:	duplicate_array.o
	$(CC) $^ -o $@

duplicate_no_edit_array:	duplicate_no_edit_array.o
	$(CC) $^ -o $@

reorder_OddEven_array:	reorder_OddEven_array.o 
	$(CC) $^ -o $@

maxSum_continueArray:	maxSum_continueArray.o
	$(CC) $^ -o $@

uglyNumber:	uglyNumber.o 
	$(CC) $^ -o $@

twoNumberWithSum:	twoNumberWithSum.o 
	$(CC) $^ -o $@

continueSeqWithSum:	continueSeqWithSum.o 
	$(CC) $^ -o $@

## .o 文件编译
duplicate_array.o:	duplicate_array.c
	$(CC) $(CFLAGS) -c $< -o $@

duplicate_no_edit_array.o:	duplicate_no_edit_array.c
	$(CC) $(CFLAGS) -c $< -o $@

reorder_OddEven_array.o: reorder_OddEven_array.c
	$(CC) $(CFLAGS) -c $< -o $@

maxSum_continueArray.o: maxSum_continueArray.c
	$(CC) $(CFLAGS) -c $< -o $@

uglyNumber.o: uglyNumber.c
	$(CC) $(CFLAGS) -c $< -o $@

twoNumberWithSum.o: twoNumberWithSum.c
	$(CC) $(CFLAGS) -c $< -o $@

continueSeqWithSum.o: continueSeqWithSum.c
	$(CC) $(CFLAGS) -c $< -o $@

# clean
clean:
	@echo "cleaning project"
	-rm duplicate_array duplicate_no_edit_array
	-rm reorder_OddEven_array maxSum_continueArray
	-rm	uglyNumber	twoNumberWithSum	continueSeqWithSum
	-rm *.o
	@echo "cleaning complie"
.PHONY:	clean