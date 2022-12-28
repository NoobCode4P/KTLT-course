#include <iostream>
using namespace std;

//===========================SINGLY LINKED LIST WITH P_TAIL=======================
struct NODE{
    int data;
    NODE *p_next;
};
struct List{
    NODE *Head;
    NODE *Tail;
};
NODE *createNode(int key){
    NODE *node = new NODE;
    node->data = key;
    node->p_next = NULL;
    return node;
}
void addHead(NODE *&head, int data){
    NODE *newHead = createNode(data);
    if (head == NULL){
        head = newHead;
        return;
    }
    newHead->p_next = head;
    head = newHead;
}

//========1
List *createList(NODE *p_node){
    List *list = new List;
    if (p_node == NULL){
        list->Head = NULL;
        list->Tail = NULL;
    }
    list->Head = p_node;
    while(p_node->p_next != NULL)
        p_node = p_node->p_next;
    list->Tail = p_node;
    return list;
}

//=======2
bool addHeadList(List *&L, int data){
    if(L->Head == NULL){
        addHead(L->Head, data);
        return true;
    }

    NODE *newHead = createNode(data);
    newHead->p_next = L->Head;
    return true;
}