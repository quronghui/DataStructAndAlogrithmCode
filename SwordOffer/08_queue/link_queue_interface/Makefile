# 编译该子目录下的文件，并保存到一个函数库中，再将该库文件复制到上一级主目录当中。

############ 编译条件 #################
CC	=	gcc
INCLUDE = -I.		# 子目录下的Makefile文件编译
CFLAGS =	-g -Wall

# 要使用Tab键，将文件定义为lib.a库
linkQueueInterface	=	linkQueueInterface.a

############## 目标库而生成和移动 ##############
$(linkQueueInterface):	$(linkQueueInterface)(linkQueueInterface.o)		
	(cp $(linkQueueInterface) ../)	
	(cp $(linkQueueInterface) ../../16_BinaryTreeAndQueue/)			

################# .o 文件编译################
linkQueueInterface.o: link_queue.c link_queue_interface.h
	$(CC) $(CFLAGS) -c $(INCLUDE) $< -o $@


#clean
clean:	
	@echo "cleaning project"
	-rm $(linkQueueInterface)
	-rm *.o 
	@echo "cleaning complie"
.PHONY:	clean