# 编译条件
CC	=	gcc
CFLAGS	=	-g -Wall
INCLUDE	=	-I.
#Objs
# all:	 quick_sort rotating_array
# all:	moreHalfNum
# all:	getLeastNumber
# all:	inversePair_mergeSort
# all:	missingNumber_increasingArray
# all:	value_incArray
all:	sort

###########目标文件编译###########
quick_sort:	quick_sort.o 
	$(CC) $^ -o $@

rotating_array:	rotating_array.o
	$(CC) $^ -o $@

moreHalfNum:	moreHalfNum.o quick_sort.o 
	$(CC) $^ -o $@

getLeastNumber:	getLeastNumber.o quick_sort.o 
	$(CC) $^ -o $@

inversePair_mergeSort:	inversePair_mergeSort.o 
	$(CC) $^	-o 	$@

missingNumber_increasingArray:	missingNumber_increasingArray.o 
	$(CC) $^	-o 	$@

value_incArray:	value_incArray.o 
	$(CC) $^	-o 	$@

sort:	sort.o
	$(CC) $^	-o 	$@

########## .o 文件的编译#########
quick_sort.o: quick_sort.c
	$(CC) $(CFLAGS) -c $(INCLUDE) $< -o $@

rotating_array.o:	rotating_array.c 
	$(CC) $(CFLAGS) -c $(INCLUDE) $< -o $@

moreHalfNum.o: moreHalfNum.c quick_sort.h
	$(CC) $(CFLAGS) -c $(INCLUDE) $< -o $@

getLeastNumber.o: getLeastNumber.c quick_sort.h
	$(CC) $(CFLAGS) -c $(INCLUDE) $< -o $@

inversePair_mergeSort.o: inversePair_mergeSort.c
	$(CC) $(CFLAGS) -c $(INCLUDE) $< -o $@

missingNumber_increasingArray.o: missingNumber_increasingArray.c
	$(CC) $(CFLAGS) -c $(INCLUDE) $< -o $@

value_incArray.o: value_incArray.c
	$(CC) $(CFLAGS) -c $(INCLUDE) $< -o $@

sort.o	:	sort.c sort.h
	$(CC) $(CFLAGS) -c $(INCLUDE) $< -o $@

#clean
clean:	
	@echo "cleaning project"
	-rm  quick_sort rotating_array
	-rm moreHalfNum getLeastNumber
	-rm inversePair_mergeSort missingNumber_increasingArray
	-rm	value_incArray sort
	-rm *.o 
	@echo "cleaning complie"
.PHONY:	clean