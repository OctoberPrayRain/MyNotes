#include <iostream>
using namespace std;

typedef struct StackNode{
    int data;//栈节点的数据内容
    struct StackNode *next; //栈节点的next指针    
}StackNode,*LinkStack;

bool InitStack(LinkStack &S){
    S = new StackNode;
    S->next = nullptr;
    return true;
}
//初始化栈

bool DestroyStack(LinkStack &S){
    StackNode *p = S->next;
    while(p != nullptr){
        StackNode *q = p->next;
        delete p;
        p = q;
    }
    //销毁栈内元素

    delete S; //销毁整个栈
    S = nullptr; //将栈指向nullptr
    return true;
}
//销毁栈

bool ClearStack(LinkStack &S){
    if(S->next == nullptr)
        return true;

    StackNode *p = S->next;
    while(p != nullptr){
        StackNode *q = p->next;
        delete p;
        p = q;
    }
    //销毁栈内元素 实际上和Destroy的步骤差不多
    S->next = nullptr; //不销毁栈即可
    return true;
}
//清空栈

bool StackEmpty(LinkStack S){
    return S->next == nullptr;
}
//判断栈是否为空 最简单

int StackLength(LinkStack S){
    StackNode *p = S->next;
    int j = 0; //创建计数器
    while(p != nullptr){
        p = p->next;
        j++;
    }
    return j;
}
//求栈目前的长度

bool GetTop(LinkStack S, int &e){
    if(S->next == nullptr)
        return false;
    e = S->next->data;
    return true;
}
//返回栈顶元素

bool Push(LinkStack &S ,int e){
    StackNode* p = new StackNode();
    //开辟一个新的节点内存
    p->data = e;
    p->next = S->next;
    S->next = p;
    return true;
}
//如果头节点在栈顶则这么写就行 入栈

bool Pop(LinkStack &S , int &e){
    if(S->next == nullptr)
        return false;
    StackNode *p = S->next;
    e = p->data;
    
    StackNode *q = p->next;
    delete(p);
    S->next = q;
    return true;
}
//出栈

bool StackTraverse(LinkStack S){
    StackNode *p = S->next;
    while(p != nullptr){
        cout << p->data << " ";
        p = p->next;
    }
    return true;
}
//遍历栈