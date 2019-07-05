# 编译该子目录下的文件，并保存到一个函数库中，再将该库文件复制到上一级主目录当中。

############# 编译条件 ##########
CC	=	gcc
INCLUDE = -I.		# 子目录下的Makefile文件编译
CFLAGS =	-g -Wall

# 要使用Tab键，将文件定义为lib.a库
linkTreeInterface	=	linkTreeInterface.a

############## 目标库而生成和移动 ##############
$(linkTreeInterface):	$(linkTreeInterface)(link_binary_search_tree.o)
	(cp $(linkTreeInterface) ../../16_BinaryTreeAndQueue/)
	(cp $(linkTreeInterface) ../../08_queue/link_queue_interface/)


################# .o 文件编译################
link_binary_search_tree.o: link_binary_search_tree.c tree_interface.h
	$(CC) $(CFLAGS) -c $(INCLUDE) $< -o $@

#clean
clean:	
	@echo "cleaning project"
	-rm $(linkTreeInterface)
	-rm *.o 
	@echo "cleaning complie"
.PHONY:	clean