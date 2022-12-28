#include <iostream>
#include <ctime>
using namespace std;

//===============================DOUBLY LINKED LIST WITHOUT TAIL=================
struct d_NODE{
    int key;
    d_NODE* pNext;
    d_NODE* pPrev;
};
//================1
d_NODE *createD_Node(int data){
    d_NODE *newNode = new d_NODE;
    newNode->key = data;
    newNode->pNext = NULL;
    newNode->pPrev = NULL;
    return newNode;
}

//================2
void addHead(d_NODE *& head, int data){
    d_NODE *newHead = createD_Node(data);
    if (head == NULL){
        head = newHead;
        return;
    }
    newHead->pNext = head;
    head->pPrev = newHead;
    head = newHead;
}

//================3
void addTail(d_NODE *& head, int data){
    d_NODE *newTail = createD_Node(data);
    if (head == NULL){
        head = newTail;
        return;
    }
    d_NODE *iter = head;
    while(iter->pNext != NULL){
        iter = iter->pNext;
    }
    iter->pNext = newTail;
    newTail->pPrev = iter;
}

//================4
void removeHead(d_NODE *& head){
    if (head == NULL)
        return;
    d_NODE *p = head;
    head = p->pNext;
    p->pNext->pPrev = NULL;
    delete p;
}

//================5
void removeTail(d_NODE *& head){
    if (head == NULL) 
        return;
    d_NODE *iter = head;
    while (iter->pNext != NULL){
        iter = iter->pNext;
    }
    d_NODE *p = iter;
    p->pPrev->pNext = NULL;
    delete p;
}

//================6
void removeAll(d_NODE *& head){
    if (head == NULL)
        return;
    d_NODE *p = head;
    while(p != NULL){
        d_NODE *temp = p->pNext;
        delete p;
        p = temp;
    }
    head = NULL;
}

//===============7
void removeBefore(d_NODE *& head, int val){
    if (head == NULL)
        return;
    d_NODE *iter = head;
    while (iter != NULL && iter->key != val){
        iter = iter->pNext;
    }
    iter->pPrev->pNext = iter->pNext;
    iter->pNext->pPrev = iter->pPrev;
    delete iter;
}

//===============8
void removeAfter(d_NODE *& head, int val){
    if (head == NULL)
        return;
    d_NODE *iter = head;
    while(iter != NULL && iter->key != val)
        iter = iter->pNext;
    
    d_NODE *temp = iter->pNext;
    temp->pNext->pPrev = iter;
    iter->pNext = temp->pNext;
    delete temp;
}

//=============9
bool addPos(d_NODE *& head, int data, int pos){
    if (head == NULL)
        return false;
    if (pos == 0) {
        addHead(head,data);
        return true;
    }
    
    d_NODE *iter = head;
    int index = 0;
    for (; index < pos-1 && iter != NULL; index++, iter = iter->pNext);

    if(index < pos-1 || pos < 0){
        cout << "Out of range!\n";
        return false;
    }

    d_NODE *newNode = createD_Node(data);
    newNode->pNext = iter->pNext;
    newNode->pPrev = iter;
    iter->pNext->pPrev = newNode;
    iter->pNext = newNode;
    return true;
}

//=============10
void removePos(d_NODE *& head, int pos){
    if(head == NULL)
        return;
    if (pos == 0){
        removeHead(head);
        return;
    }

    d_NODE *iter = head;
    int index = 0;
    for (; index < pos-1 && iter != NULL; index++, iter = iter->pNext);

    if (index < pos-1 || pos == 0){
        cout << "Out of range!\n";
        return;
    }
    d_NODE* temp = iter->pNext;
    iter->pNext = temp->pNext;
    temp->pNext->pPrev = iter;
    delete temp;
}

//==============11
void addBefore(d_NODE *& head, int data, int val){
    if (head == NULL)
        return;
    
    if (head->key == val){
        addHead(head,data);
        return;
    }
    d_NODE *newNode = createD_Node(data);
    d_NODE *iter = head;
    while(iter != NULL && iter->key != val)
        iter = iter->pNext;

    if (iter == NULL){
        cout << "Value cannot be found!\n";
        return;
    }    
    newNode->pNext = iter;
    newNode->pPrev = iter->pPrev;
    iter->pPrev->pNext = newNode;
    iter->pPrev = newNode;
}

//=============12
void addAfter(d_NODE *& head, int data, int val) {
    if (head == NULL)
        return;
    
    d_NODE *newNode = createD_Node(data);
    d_NODE *iter = head;
    for (; iter != NULL && iter->key != val; iter = iter->pNext);
    
    if (iter == NULL) {
        cout << "Value cannot be found!" << endl;
        return;
    }
    newNode->pNext = iter->pNext;
    newNode->pPrev = iter;
    iter->pNext->pPrev = newNode;
    iter->pNext = newNode;
}

//=============13
void printList(d_NODE *head){
    if (head == NULL){
        cout << "List is empty!" << endl;
        return;
    }
    d_NODE *p = head;
    while(p != NULL){
        cout << p->key << " ";
        p = p->pNext;
    }
    cout << endl;
}

//===========14
int countElements(d_NODE *head){
    int count = 0;
    d_NODE *p = head;
    while(p != NULL){
        count++;
        p = p->pNext;
    }
    return count;
}

//==========15
int countAppearance (d_NODE *head, int value){
    int count = 0;
    d_NODE *p = head;
    while (p != NULL){
        if (p->key == value)
            count++;
        p = p->pNext;
    }
    return count;
}

//==========16
d_NODE *reverseList(d_NODE *&head){
    if (head == NULL)
        return NULL;
    
    d_NODE *current = head;
    d_NODE *prev = NULL;
    while(current != NULL){
        prev = current->pPrev;
        current->pPrev = current->pNext;
        current->pNext = prev;
        current = current->pPrev;
    }
    head = prev->pPrev;
    return head;
}

//===========17
void removeDuplicate(d_NODE *&head){
    for (d_NODE * i = head; i->pNext != NULL; i = i->pNext){
        for (d_NODE *j = i->pNext; j != NULL; ){
            if(i->key == j->key){
                d_NODE *temp = j;
                if (j->pPrev != NULL)
                    j->pPrev->pNext = j->pNext;
                if (j->pNext != NULL)
                    j->pNext->pPrev = j->pPrev;
                j = temp->pNext;
                delete temp;
            }
            else 
                j = j->pNext;
        }
    }
}

//===========18
bool removeElement(d_NODE *& head, int value){
    if (head == NULL) 
        return true;

    bool checkforAppearace = false;
    d_NODE *iter = head;
    while (iter != NULL){
        if (iter->key == value){
            if (iter == head)
                removeHead(iter);
            else {
                d_NODE *temp = iter;
                if (iter->pNext != NULL)
                    iter->pNext->pPrev = iter->pPrev;
                if (iter->pPrev != NULL)
                    iter->pPrev->pNext = iter->pNext;
                iter = temp->pNext;
                delete temp;
            }
            checkforAppearace = true;
        }
        else 
            iter = iter->pNext;
    }
    return checkforAppearace;
}

int main(){
    d_NODE *start = NULL;
    int n; cin >> n;
    
    srand(time(NULL));
    for (int i = 0; i < n; i++)
        addTail(start,rand() % 10);
    
    printList(start);
    //int k; cin >> k;
    cout << "After: ";

    //d_NODE *p = reverseList(start);
    //printList(p);
    removeDuplicate(start);
    printList(start);
    

    return 0;
}