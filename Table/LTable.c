// ! 线性表用顺序存储实现
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define MaxSize 50
#define InitSize 100
typedef int ElemType;

typedef struct
{
    ElemType data[MaxSize];
    int length;
} SqList;

typedef struct
{
    ElemType *data;
    int length;
} SeqList;

void initialize(SqList *L)
{
    L->length = 0;
    for (size_t i = 0; i < MaxSize; i++)
    {
        L->data[i] = 0;
    }
}
void initializes(SeqList *L)
{
    L->length = 0;
    L->data = (ElemType *)realloc(0, L->length * InitSize);
}
int Length(SqList L)
{
    return L.length;
}
void destroy(SqList *L)
{
    for (size_t i = 0; i < L->length; i++)
    {
        L->data[i] = 0;
    }
    L->length = 0;
}
void destroys(SqList *L)
{
    free(L->data);
    L->length = 0;
}

bool Empty(SqList L)
{

    return L.length == 0;
}

int LocateElement(SqList L, ElemType data)
{
    int index = 0;
    for (size_t i = 0; i < L.length; i++)
    {
        if (data == L.data[i])
        {
            index = i;
            return index;
        }
    }

    return index;
}

ElemType GetElem(SqList L, int i)
{
    return L.data[i - 1];
}

bool ListInsert(SqList *L, int i, ElemType data)
{

    if (i < 1 || i > L->length + 1)
        return false;

    if (L->length >= MaxSize)
        return false;

    for (size_t j = L->length; j >= i; j--)
    {
        L->data[j] = L->data[j - 1];
    }
    L->data[i - 1] = data;
    L->length++;
    return true;
}

bool ListDelete(SqList *L, int i, ElemType *data)
{
    if (i < 1 || i > L->length + 1)
        return false;

    if (L->length >= MaxSize)
        return false;

    for (size_t j = i; i < L->length; j++)
    {
        L->data[j - 1] = L->data[j];
    }
    L->length--;

    return true;
}

void printList(SqList L)
{
    printf("data:");
    for (size_t i = 0; i < L.length; i++)
    {
        printf("%2d ", L.data[i]);
    }
    printf("\n");
    printf("length:%d\n", Length(L));
}
int main(int argc, char **argv)
{

    SqList sq;
    initialize(&sq);

    ListInsert(&sq, 1, 123);
    ListInsert(&sq, 2, 456);
    ListInsert(&sq, 3, 789);
    ListInsert(&sq, 4, 135);
    ListInsert(&sq, 5, 246);
    ListInsert(&sq, 6, 111);

    printList(sq);

    return 0;
}