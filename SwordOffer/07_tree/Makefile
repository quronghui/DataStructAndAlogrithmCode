# 编译条件
CC = gcc
CFLAGS = -g -Wall

# Objs
all:	construct_binary_tree next_binary_tree_node link_binary_search_tree

#####################目标文件的编译##########
construct_binary_tree:	construct_binary_tree.o 
	$(CC) $^ -o $@

next_binary_tree_node:	next_binary_tree_node.o 
	$(CC) $^ -o $@

static_array_binary_tree:	static_array_binary_tree.o 
	$(CC) $^ -o $@

link_binary_search_tree:	link_binary_search_tree.o
	$(CC) $^ -o $@

############# .o文件的编译#####################
construct_binary_tree.o:	construct_binary_tree.c 
	$(CC) $(CFLAGS) -c $< -o $@

next_binary_tree_node.o:	next_binary_tree_node.c 
	$(CC) $(CFLAGS) -c $< -o $@

# static_array_binary_tree.o: static_array_binary_tree.c tree_interface.h
# 	$(CC) $(CFLAGS) -c $< -o $@

link_binary_search_tree.o: link_binary_search_tree.c tree_interface.h
	$(CC) $(CFLAGS) -c $< -o $@



#clean
clean:	
	@echo "cleaning project"
	-rm construct_binary_tree next_binary_tree_node
	-rm link_binary_search_tree
	-rm *.o 
	@echo "cleaning complie"
.PHONY:	clean