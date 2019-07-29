# specify all source files here
# SRCS	=	double_list.c 	print_link_form_tail_to_head.c 	one_list.c	callback_use.c	\
# 					delete_oneListNode.c	delete_repeatNode.c  FindKth_ToTail.c 	EnterNode_LoopList.c 	\
# 					reverseList.c	reverseList_FromTailH.c	merge_orderList.c 	firstCommonNode_inList.c	numberOfK_InSortArray.c \

SRCS	=	double_list.c				

# specify target here (name of executable)
# TARG	=	double_list		print_link_form_tail_to_head 	callback	delete_oneListNode	\
# 					delete_repeatNode		FIndKth_ToTail		EnterNode_LoopList		reverseList		\
# 					reverseList_FromTailH		merge_orderList		firstCommonNode_inList		numberOfK_InSortArray

TARG	=	double_list 

# specify compiler, compile flags, and needed libs
CC	=	gcc
CFLAGS = -g -Wall
LIBS 	=	-lm 

# this translates	.c	file	in	src	list to .o's
OBJS	=	$(SRCS:	.c=.o)

#	all is not really	needed	, but is used to generate the target
all:	$(TARG)

# this generates the target executable
$(TARG):	$(OBJS)
	$(CC)	$(OBJS)		-o 	$(TARG)	

# this is a generic rule for .o files
%.o:	%.c 
	$(CC)	$(CFLAGS)	-c 	$<	$@

# ################## 目标函数的编译################### 

# # one_list:	one_list.o
# # 	$(CC) $^ -o $@

# double_list:	double_list.o 
# 	$(CC) $^ -o $@

# print_link_form_tail_to_head:	print_link_form_tail_to_head.o one_list.o
# 	$(CC) $^ -o $@

# callback:	one_list.o	callback_use.o 
# 	$(CC) $^ -o $@

# delete_oneListNode:	delete_oneListNode.o one_list.o 
# 	$(CC) $^ -o $@

# delete_repeatNode:	delete_repeatNode.o one_list.o 
# 	$(CC) $^ -o $@

# FindKth_ToTail:	FindKth_ToTail.o one_list.o 
# 	$(CC) $^ -o $@

# EnterNode_LoopList:	EnterNode_LoopList.o one_list.o 	 
# 	$(CC) $^ -o $@

# reverseList:	reverseList.o one_list.o 
# 	$(CC) $^ -o $@

# reverseList_FromTailH:	reverseList_FromTailH.o one_list.o reverseList.o FindKth_ToTail.o
# 	$(CC) $^ -o $@

# merge_orderList:	merge_orderList.o one_list.o 
# 	$(CC) $^ -o $@

# firstCommonNode_inList:	firstCommonNode_inList.o one_list.o 
# 	$(CC) $^	-o	 $@

# numberOfK_InSortArray:	numberOfK_InSortArray.o 
# 	$(CC) $^	-o	 $@


# ################## .o文件的编译#####################
# double_list.o:	double_list.c 
# 	$(CC) $(CFLAGS) -c $< -o $@

# print_link_form_tail_to_head.o: print_link_form_tail_to_head.c one_list.h
# 	$(CC) $(CFLAGS) -c $< -o $@

# one_list.o:	one_list.c one_list.h
# 	$(CC) $(CFLAGS) -c $< -o $@

# callback_use.o: callback_use.c one_list.h
# 	$(CC) $(CFLAGS) -c $< -o $@

# delete_oneListNode.o: delete_oneListNode.c one_list.h
# 	$(CC) $(CFLAGS) -c $< -o $@

# delete_repeatNode.o: delete_repeatNode.c one_list.h
# 	$(CC) $(CFLAGS) -c $< -o $@

# FindKth_ToTail.o: FindKth_ToTail.c FindKth_ToTail.h one_list.h
# 	$(CC) $(CFLAGS) -c $< -o $@

# EnterNode_LoopList.o: EnterNode_LoopList.c one_list.h
# 	$(CC) $(CFLAGS) -c $< -o $@

# reverseList.o: reverseList.c one_list.h
# 	$(CC) $(CFLAGS) -c $< -o $@

# reverseList_FromTailH.o: reverseList_FromTailH.c one_list.h FindKth_ToTail.h reverseList.h
# 	$(CC) $(CFLAGS) -c $< -o $@

# merge_orderList.o: merge_orderList.c one_list.h
# 	$(CC) $(CFLAGS) -c $< -o $@

# firstCommonNode_inList.o: firstCommonNode_inList.c one_list.h
# 	$(CC) $(CFLAGS) -c $< -o $@

# numberOfK_InSortArray.o: numberOfK_InSortArray.c
# 	$(CC) $(CFLAGS) -c $< -o $@


#clean
clean:	
	@echo "cleaning project"
	# -rm double_list print_link_form_tail_to_head callback
	# -rm delete_oneListNode delete_repeatNode
	# -rm FIndKth_ToTail EnterNode_LoopList
	# -rm reverseList reverseList_FromTailH
	# -rm merge_orderList firstCommonNode_inList
	-rm *.o 	$(OBJS)	$(TARG)
	@echo "cleaning complie"
.PHONY:	clean