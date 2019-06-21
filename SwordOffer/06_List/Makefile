# list

# 编译条件
CC	=	gcc
CFLAGS = -g -Wall

# objs
all:	 double_list print_link_form_tail_to_head callback

# 编译

# one_list.o:	one_list.c one_list.h
# 	$(CC) $(CFLAGS) -c $< -o $@

################## 目标函数的编译################### 

# one_list:	one_list.o
# 	$(CC) $^ -o $@

double_list:	double_list.o 
	$(CC) $^ -o $@

print_link_form_tail_to_head:	print_link_form_tail_to_head.o one_list.o
	$(CC) $^ -o $@

callback:	one_list.o	callback_use.o 
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


#clean
clean:	
	@echo "cleaning project"
	-rm double_list print_link_form_tail_to_head callback
	-rm *.o 
	@echo "cleaning complie"
.PHONY:	clean