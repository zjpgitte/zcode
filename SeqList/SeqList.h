#include <iostream>
#include <assert.h>

using namespace std;

typedef int SLDateType;

typedef struct SeqList
{
    SLDateType *_a;
    int _size;
    int _capacity;
}SeqList;

//顺序表的初始化、增、删、查、改
void SeqListInit(SeqList *L);

void CheckSeqListCapacity(SeqList *L);

//头插
void SeqListPushFront(SeqList *L, SLDateType x);
//尾插
void SeqListPushTail(SeqList *L, SLDateType x);
//中间插入
void SeqListPushMid(SeqList *L, SLDateType x, int pos);

//头删
void SeqListPopFront(SeqList *L);
//尾删
void SeqListPopTail(SeqList *L);
//中间删除
void SeqListPopMid(SeqList *L, int pos);

//修改
void SeqListModify(SeqList *L, SLDateType x, int pos);

//打印
void SeqListPrint(SeqList *L);
