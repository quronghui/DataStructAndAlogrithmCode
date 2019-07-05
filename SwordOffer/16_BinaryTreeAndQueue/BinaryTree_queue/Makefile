# Objs
all:	printTree_fromTopToBottom printTreeLine

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

printTree_fromTopToBottom:	printTree_fromTopToBottom.o link_binary_search_tree.o link_queue.o 
	$(CC)	$^ -o $@

printTreeLine:	printTreeLine.o link_binary_search_tree.o link_queue.o
	$(CC)	$^ -o $@

################# .o 文件的编译################
# $(linkQueueInterface):
# 	(cd ../08_queue/link_queue_interface;$(MAKE))

# $(linkTreeInterface):
# 	(cd ../07_tree/linkBinaryTreeInterface;$(MAKE))
link_binary_search_tree.o: link_binary_search_tree.c tree_interface.h
	$(CC) $(CFLAGS) -c $(INCLUDE) $< -o $@

link_queue.o: link_queue.c link_queue_interface.h tree_interface.h
	$(CC) $(CFLAGS) -c $(INCLUDE) $< -o $@

printTree_fromTopToBottom.o:	printTree_fromTopToBottom.c tree_interface.h link_queue_interface.h
	$(CC) $(CFLAGS) -c $(INCLUDE) $< -o $@

printTreeLine.o: printTreeLine.c tree_interface.h link_queue_interface.h
	$(CC) $(CFLAGS) -c $(INCLUDE) $< -o $@


#clean
clean:	
	@echo "cleaning project"
	-rm  printTree_fromTopToBottom  printTreeLine
	# -rm  $(linkQueueInterface) $(linkTreeInterface)
	-rm *.o 
	@echo "cleaning complie"
.PHONY:	clean