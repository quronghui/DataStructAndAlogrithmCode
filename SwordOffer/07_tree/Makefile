# 编译条件
CC = gcc
CFLAGS = -g -Wall

# Objs
# all:	link_binary_search_tree   
# all:	next_binary_tree_node construct_binary_tree
# all:	Substructure_inTree
# all:	mirror_recursively_binatyTree
# all:	is_Symmetrical
all:	verify_sequenceOfBST
#####################目标文件的编译##########
construct_binary_tree:	construct_binary_tree.o 
	$(CC) $^ -o $@

next_binary_tree_node:	next_binary_tree_node.o 
	$(CC) $^ -o $@

# 数组构建二叉树，同一套功能函数
# static_array_binary_tree:	static_array_binary_tree.o 
# 	$(CC) $^ -o $@

link_binary_search_tree:	link_binary_search_tree.o  
	$(CC) $^ -o $@

Substructure_inTree:	Substructure_inTree.o 
	$(CC) $^ -o $@

mirror_recursively_binatyTree:	mirror_recursively_binatyTree.o 
	$(CC) $^ -o $@

is_Symmetrical:	is_Symmetrical.o link_binary_search_tree.o  
	$(CC) $^ -o $@

verify_sequenceOfBST:	verify_sequenceOfBST.o 
	$(CC) $^ -o $@

############# .o文件的编译#####################
construct_binary_tree.o:	construct_binary_tree.c tree_interface.h
	$(CC) $(CFLAGS) -c $< -o $@

next_binary_tree_node.o:	next_binary_tree_node.c 
	$(CC) $(CFLAGS) -c $< -o $@

# 数组构建二叉树：使用的是同一套接口定义：所以需要隐藏一个；
# static_array_binary_tree.o: static_array_binary_tree.c tree_interface.h
# 	$(CC) $(CFLAGS) -c $< -o $@

link_binary_search_tree.o: link_binary_search_tree.c tree_interface.h 
	$(CC) $(CFLAGS) -c $< -o $@

Substructure_inTree.o: Substructure_inTree.c
	$(CC) $(CFLAGS) -c $< -o $@

mirror_recursively_binatyTree.o: mirror_recursively_binatyTree.c tree_interface.h
	$(CC) $(CFLAGS) -c $< -o $@

is_Symmetrical.o: is_Symmetrical.c tree_interface.h
	$(CC) $(CFLAGS) -c $< -o $@

verify_sequenceOfBST.o: verify_sequenceOfBST.c
	$(CC) $(CFLAGS) -c $< -o $@

#clean
clean:	
	@echo "cleaning project"
	-rm construct_binary_tree next_binary_tree_node
	-rm link_binary_search_tree  Substructure_inTree
	-rm  mirror_recursively_binatyTree is_Symmetrical
	-rm verify_sequenceOfBST
	-rm *.o 
	@echo "cleaning complie"
.PHONY:	clean