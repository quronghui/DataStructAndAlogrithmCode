// 题目一：实现键盘输入一串数字，通过空格隔开；最后以回车结尾，将其保存到数组中；

#include <stdio.h>

/**********C实现***********/
void value_save_array()
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

/********C++ 实现题目一************/
//#include <iostream>
//using namespace std;
//void value_save_array_Cadd()
//{
//    int array[100];
//    int i = 0;
//    char c;
//
//    cin>>array[i++];
//    while((c=getchar())!='\n')
//    {
//        cin>>array[i++];
//    }
//    for(int j=0; j<i; j++)
//        cout << array[j];
//}

int main() {
//    printf("Hello, World!\n");
    value_save_array();
    return 0;
}
