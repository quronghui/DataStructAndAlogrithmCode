//
// Created by quronghui on 2019/9/16.
//
// 题目：统计一个字符串的长度；模拟strlen；
// 注意：(1)scanf获取一个字符串时，遇到“空格”就会停止；
//      (2)fgets获取一个字符的时候，连着\n一起获取了，所以判断结束条件
#include <stdio.h>
#include <string.h>
int time(char *array)
{
    if(*array == '\0')
        return 0;
    int count=0;
    char *string = array;
    // fget（）读入字符串时，使用'\n'进行判断
    // scanf读入字符串时，使用'\0'进行判断；
    while (*string != '\n'){
        count++;
        string++;
    }
    return count;
}

int main()
{
    int size = 100;
    char array[size];
    // 通过fgets从缓存区中读取字符，包括回车'\n'
    fgets(array,size,stdin);

    // 这里使用scanf会出现问题，遇到空格会结束；
//    scanf("%s",array);

//    （1）way1：不能使用库函数
    int value = time(array);
//    （2）way2:可以使用库函数
//    int value = strlen(array) - 1;

    printf("%d\n",value);

}


