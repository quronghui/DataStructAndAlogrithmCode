/* 题目一: 实现一个循环缓冲区.  
     循环缓冲区是一个可以无限循环读写的缓冲区. 
     当缓冲区满了还继续写的话就会覆盖我们还没读取到的数据.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 循环缓冲区的初始化
typedef struct  RingBuf{
    char *Buf;
    unsigned int Size;
    unsigned int Rdld;
    unsigned int Wrld;
}RingBuf;

// 循环缓冲区的初始化
void    Init(RingBuf *ringbuf,   char *buf, unsigned int size)
{
    memset(ringbuf, 0, sizeof(RingBuf));
    ringbuf->Buf    =   buf;
    ringbuf->Size   =   size;
    ringbuf->Rdld   =   0;
    ringbuf->Wrld   =   strlen(buf);
}

// Write函数
void    Write(RingBuf *ringbuf,   char *buf, unsigned int len)
{
    unsigned int    pos =   ringbuf->Wrld;

    while( pos  +   len > ringbuf->Size  ){
        memcpy( (ringbuf->Buf + pos),    buf,   (ringbuf->Size - pos) );    // 进行数据的复制;
        buf += ringbuf->Size - pos;
        len -=  ringbuf->Size   -   pos;
        pos =   0;
    }

    memcpy( ringbuf->Buf + pos, buf, len );
    ringbuf->Wrld   =   pos    +   len;
}

// Print buffer
void Print(RingBuf  *ringbuf)
{
    for( int i=0; i < ringbuf->Size; i++ )
        printf("%d\t", ringbuf->Buf[i]);
    printf("\n");
}

// Test code
int main()
{
    RingBuf *ringbuf =  (RingBuf *)malloc( sizeof(RingBuf) );
    char string[] = "ABC";
    unsigned int size = 6;

    Init(ringbuf, string, size);

    char writeString[] = "1234567";
    Write(ringbuf, writeString, 7);
    Print(ringbuf);

    return 0;

}
