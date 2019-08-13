# 编译条件
CC	=	gcc
CFLAGS	=	-g -Wall

#Objs
# all:	 link_stack 
# all:	array_malloc_stack
# all:	min_inStack 
all:	is_stackPopOrder

######### objs 文件编译############
# 需要单独测试 栈的数据结构的时候，在编写
link_stack:	link_stack.o main.o
	$(CC) $^ -o $@

min_inStack:	min_inStack.o link_stack.o
	$(CC) $^ -o $@

is_stackPopOrder:	is_stackPopOrder.o link_stack.o 
############.o 文件编译#############
main.o: main.c link_stack_interface.h
	$(CC) $(CFLAGS) -c $< -o $@

array_malloc_stack.o:	array_malloc_stack.c array_stack_interface.h
	$(CC) $(CFLAGS) -c $< -o $@

link_stack.o: link_stack.c link_stack_interface.h
	$(CC) $(CFLAGS) -c $< -o $@

min_inStack.o: min_inStack.c link_stack_interface.h
	$(CC) $(CFLAGS) -c $< -o $@

is_stackPopOrder.o: is_stackPopOrder.c link_stack_interface.h
	$(CC) $(CFLAGS) -c $< -o $@

#clean
clean:	
	@echo "cleaning project"
	-rm	 main
	-rm  array_malloc_stack  link_stack
	-rm  min_inStack is_stackPopOrder
	-rm *.o 
	@echo "cleaning complie"
.PHONY:	clean