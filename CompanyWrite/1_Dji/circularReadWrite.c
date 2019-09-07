/* 题目一: 实现一个循环缓冲区.  
     循环缓冲区是一个可以无限循环读写的缓冲区. 
     当缓冲区满了还继续写的话就会覆盖我们还没读取到的数据.
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//#include "ring_buffer.h"

typedef struct ring_buffer_t ring_buf;
struct ring_buffer_t
{
    unsigned char  *buffer_ptr;
    unsigned short buffer_size;
    unsigned short rd_index;
    unsigned short wr_index;
};

/* initialize read and write index */
void ring_buffer_init(ring_buf *rb,unsigned char *pool,unsigned short size)
{
    /* initialize read and write index */
    rb->rd_index = 0;
    rb->wr_index = 0;

    /* set buffer pool and size */
    rb->buffer_ptr = pool;
    rb->buffer_size = size;
}

// 判断读写空间的大小
static  int ring_buffer_count(ring_buf *rb)
{
    if(rb->wr_index >= rb->rd_index)
        return (rb->wr_index - rb->rd_index);
    else
        return ( (rb->wr_index + rb->buffer_size) - rb->rd_index);
}

// ring_buffer_write
unsigned short ring_buffer_write(struct ring_buffer_t *rb,unsigned char *psrc,unsigned short wr_len)
{
    unsigned short free_count = 0;
    signed short over_flow_cnt = 0;

    free_count = rb->buffer_size - ring_buffer_count(rb);
    if(free_count > 0)
    {
        if(wr_len > free_count)
        {
            wr_len = free_count;
        }
        over_flow_cnt = rb->wr_index + wr_len - rb->buffer_size;
        if(over_flow_cnt <= 0)
        {
            memcpy((unsigned char *)&rb->buffer_ptr[rb->wr_index],psrc,wr_len);
            rb->wr_index += wr_len;
        }
        else
        {
            memcpy(rb->buffer_ptr + rb->wr_index ,psrc,wr_len - over_flow_cnt);
            memcpy(rb->buffer_ptr + rb->wr_index + (wr_len - over_flow_cnt) ,psrc,over_flow_cnt);
            rb->wr_index = over_flow_cnt;
        }
    }
    else
        wr_len = 0;

    return wr_len;
}

// ring_buffer_read
unsigned short ring_buffer_read(struct ring_buffer_t *rb,unsigned char *pdest,unsigned short rd_len)
{
    unsigned short valid_count = 0;
    signed short over_flow_cnt = 0;

    valid_count = ring_buffer_count(rb);
    if(valid_count > 0)
    {
        if(rd_len > valid_count)
        {
            rd_len = valid_count;
        }
        over_flow_cnt = rb->rd_index + rd_len - rb->buffer_size;
        if(over_flow_cnt <= 0)
        {
            memcpy(pdest,(unsigned char *)&rb->buffer_ptr[rb->rd_index],rd_len);
            rb->rd_index += rd_len;
        }
        else
        {
            memcpy(pdest,(unsigned char *)&rb->buffer_ptr[rb->rd_index],rd_len - over_flow_cnt);
            memcpy(pdest + rd_len - over_flow_cnt,rb->buffer_ptr,over_flow_cnt);
            rb->rd_index = over_flow_cnt;
        }
    }
    else
    {
        rd_len = 0;
        pdest[0] = 0;
    }

    return rd_len;
}

// Print buffer
void ring_print(ring_buf  *rb)
{
    for(int i=0; i<rb->buffer_size; i++)
        printf("%d\t", rb->buffer_ptr[i]);
    printf("\n");
}

//

int main() {
    ring_buf *ringhuf = (ring_buf *)malloc(sizeof(ring_buf));
    char string[10] = {0};
    unsigned int  size = 3;

    ring_buffer_init(ringhuf, string, size);    // init

    // write
    char write_string[] = {1, 2, 3, 4};
    ring_buffer_write(ringhuf, write_string, strlen(write_string));
    ring_print(ringhuf);

    // read
    char read_string[10] = {0};
    unsigned int  read_size = 3;
    ring_buffer_read(ringhuf, read_string, read_size);
    for(int i=0; i<read_size ; i++)
        printf("%d\t", read_string[i]);

    printf("Hello, World!\n");
    return 0;
}