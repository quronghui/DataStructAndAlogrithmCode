/*
*   unweight.c 无权最短路径算法伪代码
*   1) .h文件的数据结构定义不成功
*/

#include <stdio.h>
#include <stdlib.h>
#include "unweight.h"


void unweighted(table t)
{
    int CurrDist;
    int numvertex;
    vertex v, w;    /* 定义顶点 */

    for(CurrDist = 0; CurrDist < numvertex; CurrDist++)
        for each vertex v
            if( !t[v]  ) 
}