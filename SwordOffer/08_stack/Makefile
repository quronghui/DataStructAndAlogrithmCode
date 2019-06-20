# 编译条件
CC	=	gcc
CFLAGS	=	-g -Wall

#Objs
all:	 link_stack 

######### objs 文件编译############

# static_array_stack 编译
# static_array_stack:	main.o static_array_stack.o 
# 	$(CC) $^ -o $@

# malloc_array_stack 编译
malloc_array_stack:	main.o malloc_array_stack.o 
	$(CC) $^ -o $@

# link_stack 编译
link_stack:	main.o link_stack.o 

############.o 文件编译#############

main.o: main.c stack_interface.h
	$(CC) $(CFLAGS) -c $< -o $@

static_array_stack.o: static_array_stack.c stack_interface.h
	$(CC) $(CFLAGS) -c $< -o $@

malloc_array_stack.o:	malloc_array_stack.c stack_interface.h
	$(CC) $(CFLAGS) -c $< -o $@

link_stack.o: link_stack.c stack_interface.h
	$(CC) $(CFLAGS) -c $< -o $@


# link_stack:	main.o link_stack.o 
# 	$(CC) $^ -o $@
# main.o: main.c stack_interface.h
# 	$(CC) $(CFLAGS) -c $< -o $@
# link_stack.o: link_stack.c stack_interface.h
# 	$(CC) $(CFLAGS) -c $< -o $@


#clean
clean:	
	@echo "cleaning project"
	-rm  static_arry_stack malloc_array_stack  link_stack
	-rm *.o 
	@echo "cleaning complie"
.PHONY:	clean