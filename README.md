# Data_Struct

## Data Struct And Algorithm C description
### Link_list

1. link_list  --  pointer

   ```
   /* link_list */
   /* 定义了位置和链表的结构体指针 */
   /* 头文件也可用在数组的实现中 */
   
   /*link_list.c 
   *   1) 结构体数组中的数据在链表中怎么存储；
   *       是不是只能一个个的读入
   *   2) 指针结构体：定义了一个position 和 list 的结构体
   *   3)malloc(sizeof(struct node))创建元素的存储空间；如果是			  malloc(sizeof(pointer) 只是指针的存储空间
   *   4)删除整个链表,释放链表的每一个元素,将List 置Null；此时定义另外一个指针完成  每个元素释放的工作
   */
   ```

2. link_list  --  array

   ```
    /* cursor.h */
    /* 链表游标实现的方法 */
   
   /* cursor.c 
   *   1)链表的游标实现;
   *   2) 指针的空用NULL; 数组的空用0
   *   3) 数组中的链表：作为下标使用
   */
   ```

### stack

1. stack -- pointer

   ```
   /* stack.c
   *   1) 入栈和出栈：都是在栈顶进行操作的；
   *   2）入栈：新元素加入，分配存储空间；
   *   3）top 指向栈顶的，栈顶都是header 空指针，元素的操作都是检查第二个栈；
   *   4) 站的空间地址：由高位指向低位的
   */
   ```

2. stack -- arrray

   ```
   /*
   *   array_stack.h
   *   栈：通过数组实现
   *   1) 数组定义：定义到结构体中，定义成指针数组；
   *   2) 数组做右值的时候，自动转换成指针；数组取元素，其实也是地址取元素
   *   3)int TopOfStack; //表示数组的下标地址；int型能够自加；类似于next 
   */
   
   /*
   *   array_stack.c
   *   栈：通过数组实现
   *       除了数据的操作是通过数组的形式：下标进行访问元素
   *   1) 数组大小,通过变量传进去；和malloc 创建的内存单元
   *   2) s->TopOfStack 表示的是下标，数组下标的错误应该是负数; 判断栈数组是空的还是满的；通过下标判断
   *   3) s->array[ ++s->TopOfStack ] 通过数组的方式：进行出栈和进栈
   */
   ```

### queue

1. queue -- array

   ```
   /*
   *   array_queue.c
   *   1)判断队列是否为空、满：定义了一个标志位，有数就加1
   *   2)初始化时：q->front = 1;q->rear = 0 因为队尾rear还保存一个元素，满足出队
   */
   ```


## Tree

### tree

```
/* 
*   tree.c
*   二叉查找树：用关键字表示
*   1)find tree:查找到叶子节点，还没的话，返回NULL
*   2)find_min _max: 递归和非递归的方式进行实现；
*       非递归：考虑base基准情况
*   3) insert: 插入元素的关键字时：考虑tree是否为空；tree不为空时，元素是否已存在
*   4) delete_x: 遍历得到元素位置，还得考虑该位置包含两个child和一个child的情况。
*/
```

### tree_AVL

```
/*
*   tree_avl.c
*	1)任意节点的 左子树和右子树高度最多差1的二叉查找树
*/
```

## Hash 散列函数

```
/*
*   hashval.c 
*   1) 散列函数最好的选择；
*   2) nextprime：空间大小是素数，减小不同的key分配到同一空间
*   3) 分散链表的初始化：分配三个存储空间
*/

```

## priority queue

### binary heap

```
/* 
*    binary_heap.c
*   1) 数组实现二叉堆的存储
×   2）二叉堆的性质：任意节点的关键字都小于其后裔的关键字
*   
*/
```

### left_heap

```
/*
*   left_heap.c
*   1) 通过指针实现堆树的合并merge；
*	2) 任意节点X，左儿子的Npl >= 右儿子的Npl
*/
```

### binomial_queue

```
二项队列：二项树的合并
```



## Sword Offer

### 03_DuplicationArray

1. duplicate_array.c

   ```
   // 面试题3（一）：找出数组中重复的数字
   // 题目：在一个长度为n的数组里的所有数字都在0到n-1的范围内。数组中某些数字是重复的，但不知道有几个数字重复了，
   // 也不知道每个数字重复了几次。请找出数组中任意一个重复的数字。例如，如果输入长度为7的数组{2, 3, 1, 0, 2, 5, 3}，
   // 那么对应的输出是重复的数字2或者3
   
   /*
   *   找出数组中重复的数字
   *   1) 题目中提示：n个数，每个数的范围是 0-(n-1)
   *   2) 关键：找下标和对应数组值的关系。
   *   3) 方法：
           a. 将数组排序，然后遍历一遍便能得出结果，时间效率是O(nlog(n))
           b. 创建哈希表，需要额外的空间，空间效率O(n)
           c. 判断条件：下标和值对应相等，不相等则进行交换；需要对原来数组进行改变
       4. code：选择最优的方法进行编码
           a. 属于参数的判断，鲁棒性的测试
   */
   ```

2. duplicate_no_edit_array.c

   ```
   // 面试题3（二）：不修改数组找出重复的数字
   // 题目：在一个长度为n+1的数组里的所有数字都在1到n的范围内，所以数组中至
   // 少有一个数字是重复的。请找出数组中任意一个重复的数字，但不能修改输入的
   // 数组。例如，如果输入长度为8的数组{2, 3, 5, 4, 3, 2, 6, 7}，那么对应的
   // 输出是重复的数字2或者3。
   
   /*
   *   1.题目中的提示：n+1个数，数的范围1-n (和前面的题目类似)
   ×   2.题目中要求：不修改数组
   *   3.方法：
           a. 允许使用额外空间：创建一个数组O(n)将原来数组中的元素m,复制到下标为m的位置
           b. 不允许额外空间：二分查找法，将数组从中间数字m分开，查找1-m，m - n 元素的个数；
   */
   ```

### 04_FindInpartialySortMatrix

1. find_in_matrix.c

   ```
   // 面试题4：二维数组中的查找
   // 题目：在一个二维数组中，每一行都按照从左到右递增的顺序排序，每一列都按
   // 照从上到下递增的顺序排序。请完成一个函数，输入这样的一个二维数组和一个
   // 整数，判断数组中是否含有该整数。
   
   /*
   *   1.题目提示：
           row : left to right  递增   每一行最后的值是最大值
           col : up to down 递增       每一列最小的值是最小值
       2.方法：
           每次取矩阵右上角的值value和number比较；
           value > number: col-1
           value < number: row-1
   */
   ```

### 05_ReplaceSpaces

1. string_replace.c

   ```
   // 面试题5：替换空格
   // 题目：请实现一个函数，把字符串中的每个空格替换成"%20"。例如输入“We are happy.”，
   // 则输出“We%20are%20happy.”。
   
   /*
   *   1.题目注意：
           a.字符串隐含一个 '\0'
           b.是否允许额外的空间；直接复制插入值
       2.方法：
           字符串
           a.遍历一遍统计空格数，计算出替换后总的大小；
           b.设置两个指针分别指向末尾，由后往前进行替换
           c.保证字符串的长度足够大
   */
   ```

### 06_List

1. one_list.c

   ```
   /*
   *   题目：单链表 节点的插入和删除
   *   1) 每插入一个节点，都要为新节点分配内存；
   *   2) 删除节点，需要将其free，避免野指针；
       Parameter：
           a) **phead 头指针：定义为指向指针的指针, 防止（*root）根指针为空时，的内存地址被直接修改；
           b) 单链表：头指针是要保存数据的，和双向链表有点区别。    
   */
   ```

2. double_list.c

   ```
   /*
   *   题目：双链表 节点的插入和删除
   *   1) 双链表的插入有四种情况：
   *       a.插入到链表中间；b.插入到起始位置；  
   *       c.插入到末尾节点；d.插入到空链表中;   
   *   2)Parameter:
           *phead; 头指正；
           *fwd: 前向指针
           *bwd: 后向指针   
           *preview 插入节点的前驱节点；
           *pNode : 插入节点的后一个节点；
       3)双链表 需要 根节点, 保存两个指针
           a. root->pwd：指向最后一个节点； 第一个节点的 fwd = null; 这样才能从头后者末尾开始访问
           b. fwd 指向第一个节点； 
           c. pwd 指向最后一个节点；
       4) 链表通过画图，得到控制条件
           a.  先遍历找出插入点的位置： 
           a.  previous != pHead
           b.  pNode != Null 
   */
   ```

3. print_link_form_tail_to_head.c

   ```
   // 面试题6：从尾到头打印链表
   // 题目：输入一个链表的头结点，从尾到头反过来打印出每个结点的值。
   
   /*
   *   1.题目要求：from tail to head print link
   *   2.ways:
           a. 栈的方法：
           b. 栈也是递归
       3. Parament
           *pHead: 链表的地址
   
   */
   ```

### 07_tree

1. construct_binary_tree.c

   ```
   // 面试题7：重建二叉树
   // 题目：输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。假设输入的前序遍历和中序遍历的结果中都不含重复的数字。
   //例如输入前序遍历序列{1, 2, 4, 7, 3, 5, 6, 8}和中序遍历序列{4, 7, 2, 1, 5, 3, 8, 6}，则重建出二叉树并输出它的头结点。
   
   /*
   *   1.题目信息：
           a. 根据两个数组，构建一颗二叉树；
           b. 不含重复的数字。
       2.解题目思路
           a. 前序遍历数组和中序遍历数组 与树的关系；
       3. Construct_Parameter:
           *preorder   前序遍历数组；
           *inorder    中序便利的数组；
           length      作为数组访问的下标，数组长度
       4. ConstructTree_Parameter
           *startPreorder -- preorder          指向前序数组第一个元素
           *endPreorder -- preorder+length-1   指向前序数组最后一个元素
           *startInorder  --  inorder          指向中序数组第一个元素
           *endInorder  --  inorder+length-1   指向中序数组最后一个元素
       5. 递归的条件
           a.根据前序遍历的第一个值，在中序遍历中找出位置； 
           b.根据中序遍历的root，划分出左右子树的长度；
           c.递归划分 ConstructTree_Parameter 四个参数，完成二叉树的构建
   */
   ```

2. next_binary_tree_node.c

   ```
   // 面试题8：二叉树的下一个结点
   // 题目：给定一棵二叉树和其中的一个结点，如何找出中序遍历顺序的下一个结点？
   // 树中的结点除了有两个分别指向左右子结点的指针以外，还有一个指向父结点的指针。
   
   /*
   *   1.题目提示：
           a. 中序遍的规则：父节点在中间访问；
           b. 每个节点有一个指向父节点的指针；
       2.解题思路:通过举例子得出具体情况
           a.pNode 节点有右子树：下一个节点是它右子树的最左节点；
           b.pNode 节点没有右子树：
               b1. pNode是它父节点的 左子节点： 下一个节点是它的父节点
               b2. pNode是它父节点的 右子节点： 先找到一个是 它 父节点的左子节点的节点；
                   如果存在，那么这个节点的父节点便是下一个节点
               b3. 注意b1.b2最后的情况都是父节点的情况
       3.GetNext_Parameter
           pNode: 树中的节点
       4.辅助函数
           CreateBinaryTreeNode : 创建每一个节点，按照广度优先的方式排列
           ConnectTreeNode：       通过一个父节点，两个儿子节点，创建树的整个连接
           PrintTree 打印树中的节点： 父节点加两个子节点的方式打印
           DestoryTree：           释放整棵树
   */
   ```

   