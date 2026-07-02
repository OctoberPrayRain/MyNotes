#include <iostream>
using namespace std;

typedef struct Node{
    int data;
    struct Node *next;
}LNode,*LinkList; //这样定义的时候是LNode *p和LinkList p 这样是符合习惯的

//接下来实现ADT

bool InitList(LinkList &L){
    L = new LNode;
    L->next = nullptr;
    return true;
}
//创建头节点，不存任何数据，同时一开始的next为nullptr

void DestroyList(LinkList &L){
    while(L != nullptr){
        Node* tmp;
        tmp = L->next;
        delete(L);
        L = tmp;
    }
}
//每次删除的都是第一个节点 用tmp存了第一个节点的next也就是第二个节点
//删除第一个节点后又把tmp赋值给L 那么原先的第二个节点又变成了现在的第一个节点 然后重复这个过程直到L为空

void ClearList(LinkList &L){
    Node* p = L->next;
    while(p != nullptr){
        Node* tmp;
        tmp = p->next;
        delete(p);
        p = tmp;
    }
    L->next = nullptr;
}
//保留头节点的DestroyList 先用一个p表示头节点的next节点，然后再重复销毁过程即可

bool ListEmpty(LinkList &L){
    if(L->next != nullptr){
        return false;
    }else{
        return true;
    }
}
//判断链表是不是空的 如果是空的就返回true 反之false

int ListLength(LinkList L){
    int length = 0;
    Node* p = L->next;
    while(p != nullptr){
        length++;
        p = p->next;
    }
    return length;
}
//跟ClearList的逻辑类似，先用一个p表示头节点的next节点，然后再重复遍历过程并计算长度

LNode* GetElem(LinkList L, int i , int &e){
    Node* p = L;
    int j = 0;
    while(p!=nullptr && j < i){
        p=p->next;
        j++;
    }

    if (p == nullptr || j > i) { 
        return nullptr; 
    }

    e = p->data;
    return p;
 }
 //获取对应位置的元素data值

LNode* LocateElem(LinkList &L,int e){

    Node* p = L->next;
    while(p!=nullptr && p->data != e){
        p = p->next;
    }
    return p;
}
//如果链表为空则while直接就不执行 所以不需要判断条件
//同时这里的e不需要&符号的原因是因为只要位置而不需要改变值

int PriorElem(LinkList &L,int cur_e,int &pre_e){
   Node* pre = L;
   Node* cur = L->next;
   while(cur != nullptr){
     if(cur->data == cur_e){
        if(pre == L){
            cout << "The element not found!" << endl;
            return 0;
        }else{
            pre_e = pre->data;
        return pre_e;
        }
   }
    pre = cur;
    cur = cur->next;
   }
   cout << "The element not found!" << endl;
   return 0;
}
//求前驱

int NextElem(LinkList &L,int cur_e,int & next_e){
   Node* p = L->next;
   while(p != nullptr){
    if(p->data == cur_e){
        if(p->next != nullptr){
        next_e = p->next->data;
        return next_e;
        }else{
            cout << "The element not found!" << endl;
            return 0;
        }
    }
    p = p->next;
   }
   cout << "The element not found!" << endl;
   return 0;
}
//求后继

bool ListInsert(LinkList &L, int i, int e){
  LNode* p = L;
  int j = 0;  //创建累加器

  while(p != nullptr && j < i - 1){
    p = p->next;  //遍历到目标节点的前驱节点
    j++; //累加器累加
  }

  if(p == nullptr){ //判断是否过大
    cout<< "Invalid Insert!" <<endl;
    return false;
  }

  LNode* q = new LNode;
  q->data = e;
  q->next = p->next;
  p->next = q;
  return true;
}
//插入节点

bool ListDelete(LinkList &L,int i,int &e){
   LNode* p = L;
   int j = 0; //创建累加器

   while(p != nullptr && j < i - 1){
    p = p->next;  //遍历到目标节点的前驱节点
    j++;
   }

   if(p == nullptr || p->next == nullptr){
    cout << "Invalid delete!" << endl;
    return false;
   }

   LNode* q = p->next;
   e = q->data;
   p->next=q->next;
   delete(q);
   return true;
}
//删除节点 其写法和插入差不多

void ListTraverse(LinkList L){
    LNode* p = L->next;
    while(p != nullptr){
        cout << p->data << " " << endl;
        p = p->next;
    }
}
//遍历节点