//栈
#include <stdio.h>
#include <stdlib.h>

//声明结构
#define MAXSIZE 100
typedef int ElemType;

typedef struct
{
    ElemType* data;
    int top;                 /* ← 补上分号 */
} Stack;

//初始化
Stack* initStack(void)
{
    Stack* s = (Stack*)malloc(sizeof(Stack));
    if (s == NULL) return NULL;

    s->data = (ElemType*)malloc(sizeof(ElemType) * MAXSIZE);
    if (s->data == NULL)
    {
        free(s);
        return NULL;
    }
    s->top = -1;
    return s;
}

//销毁
void destroyStack(Stack* s)
{
    if (s == NULL) return;
    free(s->data);
    free(s);
}

//判空：只返回结果，不打印
int isEmpty(const Stack* s)
{
    return s->top == -1;
}

//判满
int isFull(const Stack* s)
{
    return s->top == MAXSIZE - 1;
}

//进栈
int push(Stack* s, ElemType e)
{
    if (isFull(s)) return 0;
    s->data[++s->top] = e;
    return 1;
}

//出栈
int pop(Stack* s, ElemType* e)
{
    if (isEmpty(s)) return 0;
    *e = s->data[s->top--];
    return 1;
}

//获取栈顶元素
int getTop(const Stack* s, ElemType* e)
{
    if (isEmpty(s)) return 0;
    *e = s->data[s->top];
    return 1;
}

int main(void)
{
    Stack* s = initStack();
    if (s == NULL)
    {
        printf("初始化失败\n");
        return 1;
    }

    push(s, 10);
    push(s, 20);
    push(s, 30);

    ElemType e;
    pop(s, &e);
    pop(s, &e);

    if (!isEmpty(s))
    {
        getTop(s, &e);
        printf("%d\n", e);
    }
    else
    {
        printf("空的\n");
    }

    destroyStack(s);
    return 0;
}