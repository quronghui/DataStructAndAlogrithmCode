# Objs
# all:	printZigzag
all:	BinaryTree_Con_DoubleList

################ 编译条件 #############
CC	=	gcc
CFLAGS =	-g -Wall
INCLUDE = -I. 		# 目录

################# 目标文件的编译################
BinaryTree_Con_DoubleList:	BinaryTree_Con_DoubleList.o link_binary_search_tree.o 
	$(CC)	$^ -o $@

################# .o 文件的编译################
link_binary_search_tree.o: link_binary_search_tree.c tree_interface.h
	$(CC) $(CFLAGS) -c $(INCLUDE) $< -o $@

BinaryTree_Con_DoubleList.o: BinaryTree_Con_DoubleList.c tree_interface.h
	$(CC) $(CFLAGS) -c $(INCLUDE) $< -o $@



#clean
clean:	
	@echo "cleaning project"
	-rm  BinaryTree_Con_DoubleList
	-rm *.o 
	@echo "cleaning complie"
.PHONY:	clean