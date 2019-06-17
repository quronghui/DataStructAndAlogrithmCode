# 编译条件
CC = gcc
CFLAGS = -g -Wall

# Objs
all:	construct_binary_tree next_binary_tree_node

# 编译
construct_binary_tree:	construct_binary_tree.o 
	$(CC) $^ -o $@
construct_binary_tree.o:	construct_binary_tree.c 
	$(CC) $(CFLAGS) -c $< -o $@

next_binary_tree_node:	next_binary_tree_node.o 
	$(CC) $^ -o $@
next_binary_tree_node.o:	next_binary_tree_node.c 
	$(CC) $(CFLAGS) -c $< -o $@

#clean
clean:	
	@echo "cleaning project"
	-rm construct_binary_tree next_binary_tree_node
	-rm *.o 
	@echo "cleaning complie"
.PHONY:	clean