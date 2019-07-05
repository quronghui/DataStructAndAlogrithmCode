# Objs
# all:	printZigzag
all:	findPth_binaryTree

################ 编译条件 #############
CC	=	gcc
CFLAGS =	-g -Wall
INCLUDE = -I. 		# 目录

################# 目标文件的编译################


printZigzag:	printZigzag.o link_stack.o link_binary_search_tree.o 
	$(CC)	$^ -o $@

findPth_binaryTree:	findPth_binaryTree.o link_stack.o link_binary_search_tree.o 
	$(CC)	$^ -o $@

################# .o 文件的编译################

link_binary_search_tree.o: link_binary_search_tree.c tree_interface.h
	$(CC) $(CFLAGS) -c $(INCLUDE) $< -o $@

link_stack.o: link_stack.c link_stack_interface.h tree_interface.h
	$(CC) $(CFLAGS) -c $(INCLUDE) $< -o $@

printZigzag.o: printZigzag.c tree_interface.h link_stack_interface.h
	$(CC) $(CFLAGS) -c $(INCLUDE) $< -o $@

findPth_binaryTree.o: findPth_binaryTree.c tree_interface.h link_stack_interface.h
	$(CC) $(CFLAGS) -c $(INCLUDE) $< -o $@


#clean
clean:	
	@echo "cleaning project"
	-rm  printZigzag findPth_binaryTree
	-rm *.o 
	@echo "cleaning complie"
.PHONY:	clean