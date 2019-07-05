# Objs
all:	printZigzag

################ 编译条件 #############
CC	=	gcc
CFLAGS =	-g -Wall
INCLUDE = -I. 		# 目录
# 不同目录下的依赖文件库
# linkQueueInterface	=	linkQueueInterface.a	# 队列接口
# linkTreeInterface	=	linkTreeInterface.a		# 树接口

################# 目标文件的编译################
# printTree_fromTopToBottom:	printTree_fromTopToBottom.o $(linkQueueInterface) $(linkTreeInterface)
# 	$(CC)	$^ -o $@

printZigzag:	printZigzag.o link_stack.o link_binary_search_tree.o 
	$(CC)	$^ -o $@


################# .o 文件的编译################
# $(linkQueueInterface):
# 	(cd ../08_queue/link_queue_interface;$(MAKE))

# $(linkTreeInterface):
# 	(cd ../07_tree/linkBinaryTreeInterface;$(MAKE))
link_binary_search_tree.o: link_binary_search_tree.c tree_interface.h
	$(CC) $(CFLAGS) -c $(INCLUDE) $< -o $@

link_stack.o: link_stack.c link_stack_interface.h tree_interface.h
	$(CC) $(CFLAGS) -c $(INCLUDE) $< -o $@

printZigzag.o: printZigzag.c tree_interface.h link_stack_interface.h
	$(CC) $(CFLAGS) -c $(INCLUDE) $< -o $@


#clean
clean:	
	@echo "cleaning project"
	-rm  printZigzag
	# -rm  $(linkQueueInterface) $(linkTreeInterface)
	-rm *.o 
	@echo "cleaning complie"
.PHONY:	clean