#include <stdio.h>
#include <malloc.h>
//宏定义线性表的相关数据
#define elementType int
#define initsize 100
//定义线性表节点

typedef struct{
    elementType* data;
    int MaxSize,length;
}SeqList;
//线性表的基本操作： 创建 销毁 查空 输出(表长与具体内容)  /  增 删 改 查（按值 按位）

void InitList(SeqList &L){
    //分配内存
    L.data = (elementType*)malloc(sizeof(elementType)*initsize);  //malloc（） 直接分配 大小是sizeof(type)*初始长度 然后转化成指针类型
    L.MaxSize = initsize;  
    L.length = 0;  //没数据 所以线性表长度为0 内存不代表长度
}

void DestroyList(SeqList &L){
    if(L.data != nullptr){
    free(L.data); //还需要收回内存
    }
    L.data = (elementType*)nullptr;
    L.MaxSize = 0;
    L.length = 0;
}

void IsEmptyList(SeqList &L){
    if (L.length == 0 ){
        printf("The list is empty");
    }else{
        printf("The list is not empty");
    }
}

void PrintList(SeqList &L){
    printf("All the elements in the SqList are:\n");
    for(int i = 0 ; i < L.length ; i++){
        printf("%d ",L.data[i]);
    }
}

void ListLength(SeqList &L){
    printf("The length of the list is : %d",L.length);
}

void ListAppend(elementType SeqListData,SeqList &L){  //增加元素到线性表末尾
    if(L.length < L.MaxSize){
        if( L.data[L.length] == SeqListData){
             L.length++;
        }else{
            printf("IAppend Error! Can't insert the data!");
        }
    }else{
        printf("Append Error!The SqList is full.");
    }
}

void ListInsert(SeqList &L,int i,elementType SeqListData){  
    if(L.length < L.MaxSize ){
        if(i > 0 && i <= L.length + 1){
            for(int locate = L.length - 1; locate >= i - 1 ; locate-- ){     
                L.data[locate+1] = L.data[locate];
            }    
            L.length ++;
            L.data[i - 1 ] = SeqListData;
        }else{
            printf("Insert Error! Not a valid location!");
        }
    }else{
        printf("Insert Error!The SqList is full.");
    }
}

void ListDelete(SeqList &L,int i){  
    if(L.length > 0){
        if( i > 0 && i <= L.length){
        for(int locate = i - 1 ; locate < L.length - 1; locate ++ ){
            L.data[locate] = L.data[locate+1];
        }
        L.length --;
    }
        else{
            printf("Delete Error! Not a valid location!");
        }
    }else{
        printf("Delete Error!The SqList is empty.");
    }
}

void ListEdit(SeqList &L, int i, elementType SeqListData){  
    if(i > 0 && i <= L.length){
        L.data[i-1] = SeqListData;
    }else{
        printf("Edit Error! Not a valid location!");
    }
}

void ListSearchByPos(SeqList &L, int i){
    if(i > 0 && i <= L.length){
        printf("The data in the locate %d is : %d",i,L.data[i-1]);
    }else{
        printf("Search Error! Not a valid location!"); 
    }
}

void ListSearchByVal(SeqList &L, elementType SeqListData){
    printf("Search Complete,The valiable numbers in the SqList are the ");
    for(int i = 0 ; i < L.length ; i++){
        if(L.data[i] == SeqListData){
            printf("%d ",i + 1);
        }
    }
       printf("ones");
}
