# 编译条件
CC	=	gcc
CFLAGS =	-g -Wall

#Objs
all:	link_queue

################# 目标文件的编译################

# static_array_queue:	main.o static_array_queue.o 
# 	$(CC) $^ -o $@

# malloc_array_queue:	main.o malloc_array_queue.o 
# 	$(CC) $^ -o $@

link_queue:	main.o link_queue.o 
	$(CC) $^ -o $@

################# 目标.o 文件的编译################

main.o: main.c queue_interface.h
	$(CC) $(CFLAGS) -c $< -o $@

static_array_queue.o: static_array_queue.c queue_interface.h
	$(CC) $(CFLAGS) -c $< -o $@

malloc_array_stack.o: malloc_array_stack.c queue_interface.h
	$(CC) $(CFLAGS) -c $< -o $@

link_queue.o: link_queue.c queue_interface.h
	$(CC) $(CFLAGS) -c $< -o $@

#clean
clean:	
	@echo "cleaning project"
	-rm static_array_queue malloc_array_queue link_queue
	-rm *.o 
	@echo "cleaning complie"
.PHONY:	clean