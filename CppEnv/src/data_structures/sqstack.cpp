#include <iostream>
using namespace std;

#define MAXSIZE 100 //顺序栈存储空间的初始分配量

typedef struct Stack{
    int *base;//栈底指针 
    int *top;//栈顶指针
    int stacksize;//栈可用的最大容量
}SqStack;
//栈的结构体定义

//以下是ADT实现
bool InitStack(SqStack &S){
    S.stacksize = MAXSIZE;
    S.base = new int[MAXSIZE];
    S.top = S.base;
    return true;
}
//顺序栈 直接给出数组连续空间

bool DestroyStack(SqStack &S){
    if(S.base == nullptr)
        return false;
    delete[] S.base;
    S.base = nullptr;
    S.top = nullptr;
    S.stacksize = 0;
    return true;
}
//销毁栈

bool ClearStack(SqStack &S){
    S.top = S.base;
    return true;
}
//清空栈 多余数据不用管它 后续会覆写

bool StackEmpty(SqStack &S){
    if(S.top == S.base)
        return true;
    return false;
}
//判断栈是否为空

int StackLength(SqStack S){
    return S.top - S.base;
}
//求栈的长度

bool GetTop(SqStack S, int &e){
    if(S.top == S.base)
        return false;
    e = *(S.top - 1);
    return true;
}
//求栈顶的元素值

bool Push(SqStack &S, int e){
    if(S.top - S.base == MAXSIZE)
        return false;
    *S.top = e;
    S.top++;
    return true;
}
//给新元素入栈

bool Pop(SqStack &S, int &e){
    if(S.top == S.base)
        return false;
    e = *(S.top - 1);
    S.top--;
    return true;
}
//出栈元素

bool StackTraverse(SqStack S){
    int *p = S.base;
    while(p != S.top){
        cout << *p <<" "; 
        p++;
    }
    return true;
}
//遍历栈