#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100
typedef int ElemType;

typedef struct
{
    ElemType data[MAXSIZE];
    int front;
    int rear;
}Queue;

void initQueue(Queue* Q)
{
    Q->front = 0;
    Q->rear = 0;

}

int isEmpty(Queue* Q)
{
    if(Q->front == Q->rear)
    {
        printf("空的\n");
        return 1;
    }
    else
    {
        return 0;
    }
}

ElemType dequeue(Queue* Q)
{
    if(Q->front == Q->rear)
    {
        printf("空的\n");
        return 0;
    }
        ElemType e = Q->data[Q->front];
        Q->front++;
        return e;
}

//判断并解决假溢出
int queueFull(Queue* Q)
{
    if(Q->front > 0)
    {
        int step = Q->front;
        for(int i = Q->front;i<Q->rear;i++)
        {
            Q->data[i-step] = Q->data[i];
        }
        Q->front = 0;
        Q->rear = Q->rear - step;
        return 1;
    }
    else
    {
        printf("真的满了\n");
        return 0;
    }
}

//入队
int enQueue(Queue* Q,ElemType e)
{
    if(Q->rear >= MAXSIZE)
    {
        if(!queueFull(Q))
        {
            return 0;
        }
    }
   Q->data[Q->rear] = e;
   Q->rear++;
   return 1;
}

//获取队头元素
int getHead(Queue* Q,ElemType* e)
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
    Queue q;
    initQueue(&q);

    for(int i =1;i<=5;i++)
    {
        enQueue(&q,i);
    }

    printf("出队:%d\n",dequeue(&q));
    printf("出队:%d\n",dequeue(&q));
    printf("出队:%d\n",dequeue(&q));

   //再次入队触发假溢出的前移处理
   for(int i = 6;i <= 8;i++)
   {
    enQueue(&q,i);
   }

   //打印队头元素
   ElemType e;
   if(getHead(&q,&e))
   {
    printf("队头元素:%d\n",e);
   }

   //全部出队
   while(!isEmpty(&q))
   {
    printf("出队:%d\n",dequeue(&q));
   }
   return 0;
}