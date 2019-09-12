// stdin:标准输入，一般指键盘输入到缓冲区里的东西
// 当输入的类型和scanf取的类型不一致时，就会将该内容阻塞
// scanf():以键盘(stdin)为输入源
void std_stdin()
{
    int a,b,c,ret;
    ret = scanf("%d %d %d",&a,&b,&c);
    printf("First input number: %d\n",ret);
    printf("First number value: %d %d %d \n",a,b,c);

    ret = scanf("%d %d %d",&a,&b,&c);
    printf("Second input number: %d\n",ret);
}

// sscanf：以固定字符串为输入源,提取需要格式的字符转
void std_sscanf()
{
    char buf[100];
    sscanf("hello", "%s",buf);
    printf("buf : %s\n", buf);  // 输出hello
    // %[1-9a-z]:支持合集操作
    sscanf("123456abcdefgABCDEFG","%[1-9a-z]",buf);
    printf("buf : %s\n", buf);  // 输出123456abcdefg
}

// getchar():读入字符
void std_getcahr()
{
    int array[100];
    int i=0;
    int num;
    while (1){
        scanf("%d",&num);
        char c = getchar();
        array[i++] = num;
        if(c == '\n')
            break;
    }
    for(int j=0; j<i; j++)
        printf("%d ",array[j]);
}

// fgets(): 从stream中读取最多size-1大小的内容到s指定的buffer中，当遇到换行符或EOF时读取结束
// 不用担心溢出，只读size-1个字符
void std_fgets()
{
    int size = 10;
    char buff[size];
    // 只读size-1 个字节
    fgets(buff,size,stdin);     //从标准输入流中读入
    printf("%s", buff);
    // 加了while 就是一直读入，只要stdin有输入的时候，就会往buff中放
//    while (fgets(buff,size,stdin) != NULL) {
//        printf("Read line with len: %ld\n", strlen(buff));
//        printf("%s", buff);
//    }
}
