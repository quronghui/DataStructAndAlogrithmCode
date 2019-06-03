# Data_Struct

## 三种基础的数据结构

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

