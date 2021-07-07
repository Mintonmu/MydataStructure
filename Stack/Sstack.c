// !线性表实现一个sharestack
#include <stdio.h>
#include <stdbool.h>

typedef int ShareStackType;

#define ShareStackMaxSize 10

typedef struct
{
    ShareStackType data[ShareStackMaxSize];
    size_t top1;
    size_t top2;

} ShareStack;

void ShareStackInit(ShareStack *s)
{
    if (s)
    {
        s->top1 = -1;
        s->top2 = ShareStackMaxSize;
        for (size_t i = 0; i < ShareStackMaxSize; i++)
        {
            s->data[i] = 0;
        }
    }

    return;
}

bool ShareStackEmpty(ShareStack *s)
{
    if (s->top1 == -1 && s->top2 == ShareStackMaxSize)
    {
        return true;
    }
    return false;
}

bool ShareStackPush1(ShareStack *s, ShareStackType value)
{
    if (s->top1 == s->top2)
    {
        return false;
    }
    s->data[++s->top1] = value;
    return true;
}
bool ShareStackPush2(ShareStack *s, ShareStackType value)
{
    if (s->top2 == s->top1)
    {
        return false;
    }
    s->data[--s->top2] = value;
    return true;
}

bool ShareStackPop1(ShareStack *s, ShareStackType *x)
{
    if (!ShareStackEmpty(s))
    {

        *x = s->data[s->top1--];
        return true;
    }
    return false;
}

bool ShareStackPop2(ShareStack *s, ShareStackType *x)
{
    if (!ShareStackEmpty(s))
    {

        *x = s->data[s->top2++];
        return true;
    }
    return false;
}

bool GetTop1(ShareStack *s, ShareStackType *x)
{
    if (!ShareStackEmpty(s))
    {
        *x = s->data[s->top1];
        return true;
    }
    return false;
}

bool GetTop2(ShareStack *s, ShareStackType *x)
{
    if (!ShareStackEmpty(s))
    {
        *x = s->data[s->top2];
        return true;
    }
    return false;
}
void PrintShareStack(ShareStack *s)
{
    for (size_t i = 0; i < ShareStackMaxSize; i++)
    {
        printf("%d  ", s->data[i]);
    }
    printf("\n");
}

int main()
{
    ShareStack s;
    ShareStackInit(&s);

    ShareStackPush1(&s, 1);
    ShareStackPush1(&s, 2);
    ShareStackPush1(&s, 3);
    ShareStackPush1(&s, 5);

    ShareStackPush2(&s, 6);
    ShareStackPush2(&s, 7);
    ShareStackPush2(&s, 9);
    ShareStackPush2(&s, 8);

    ShareStackType x;
    ShareStackType y;
    // PrintShareStack(&s);
    // GetTop1(&s, &x);
    // GetTop2(&s, &y);
    // printf("%d\n", x);
    // printf("%d\n", y);
    ShareStackPop1(&s, &x);
    ShareStackPop2(&s, &y);
    // printf("%d\n", x);
    // printf("%d\n", y);

    GetTop1(&s, &x);
    GetTop2(&s, &y);
    printf("%d\n", x);
    printf("%d\n", y);
}