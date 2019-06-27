# list

# 编译条件
CC	=	gcc
CFLAGS = -g -Wall

# objs
#all:	 double_list print_link_form_tail_to_head callback
all:	delete_oneListNode delete_repeatNode

# 编译

################## 目标函数的编译################### 

# one_list:	one_list.o
# 	$(CC) $^ -o $@

double_list:	double_list.o 
	$(CC) $^ -o $@

print_link_form_tail_to_head:	print_link_form_tail_to_head.o one_list.o
	$(CC) $^ -o $@

callback:	one_list.o	callback_use.o 
	$(CC) $^ -o $@

delete_oneListNode:	delete_oneListNode.o one_list.o 
	$(CC) $^ -o $@

delete_repeatNode:	delete_repeatNode.o one_list.o 
	$(CC) $^ -o $@

################## .o文件的编译#####################
double_list.o:	double_list.c 
	$(CC) $(CFLAGS) -c $< -o $@

print_link_form_tail_to_head.o: print_link_form_tail_to_head.c one_list.h
	$(CC) $(CFLAGS) -c $< -o $@

one_list.o:	one_list.c one_list.h
	$(CC) $(CFLAGS) -c $< -o $@

callback_use.o: callback_use.c one_list.h
	$(CC) $(CFLAGS) -c $< -o $@

delete_oneListNode.o: delete_oneListNode.c one_list.h
	$(CC) $(CFLAGS) -c $< -o $@

delete_repeatNode.o: delete_repeatNode.c one_list.h
	$(CC) $(CFLAGS) -c $< -o $@

#clean
clean:	
	@echo "cleaning project"
	-rm double_list print_link_form_tail_to_head callback
	-rm delete_oneListNode delete_repeatNode
	-rm *.o 
	@echo "cleaning complie"
.PHONY:	clean