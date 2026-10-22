//寰幆闃熷垪
#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100
typedef int ElemType;

typedef struct
{
    ElemType *data;
    int front;
    int rear;
}circularQueue;

//初始化
circularQueue* initQueue()
{
    circularQueue* q = (circularQueue*)malloc(sizeof(circularQueue));
    q->data = (ElemType*)malloc(sizeof(ElemType)*MAXSIZE);
    q->front = 0;
    q->rear = 0;
    return q;
}

//入队
int enqueue(circularQueue* Q,ElemType e)
{
    if((Q->rear+1)%MAXSIZE == Q->front)//牺牲一个位置用于区分空和满
    {
        printf("满了\n");
        return 0;
    }
    Q->data[Q->rear] = e;
    Q->rear = (Q->rear + 1)%MAXSIZE;
    return 1;
}

//出队
int dequeue(circularQueue* Q,ElemType* e)
{
    if(Q->front == Q->rear)
    {
        printf("空的\n");
        return 0;
    }
    *e = Q->data[Q->front];
    Q->front = (Q->front + 1)%MAXSIZE;
    return 1;
}

//获取队头元素
int getHead(circularQueue* Q,ElemType* e)
{
    if(Q->front == Q->rear)
    {
        printf("空的\n");
        return 0;
    }
    *e = Q->data[Q->front];
    return 1;
}

int main()
{
    circularQueue*q = initQueue();
    ElemType e;

    //循环队列最多存放MAXSIZE-1个元素
    for(int i = 1;i<=5;i++)
    {
        enqueue(q,i);
    }

    while(dequeue(q,&e))
    {
        printf("出队%d\n",e);
    }

    free(q->data);
    free(q);
    return 0;
}