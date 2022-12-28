#include <iostream>
#include <ctime>
using namespace std;

struct NODE{
    int key;
    NODE *p_next;
};
//===========================SINGLY LINKED LIST WITHOUT P_TAIL=======================
//===========1
NODE *createNode(int data){
    NODE *p = new NODE;
    p->key = data;
    p->p_next = NULL;
    return p;
}

//==========2
void addHead(NODE *& pHead,int data){
    NODE *p = createNode(data);
    if (pHead == NULL){
        pHead= p;
    }
    else {
        p->p_next = pHead;
        pHead = p;
    }
}

//==========3
void addTail(NODE *& pHead,int data){
    NODE *p = createNode(data);
    NODE *last = pHead;
    if (pHead == nullptr){
        pHead = p;
        return;
    }
    while (last->p_next){
        last = last->p_next;
    }
    last->p_next = p;
    return;
}

//=========4
void removeHead(NODE *& pHead){
    if (pHead == NULL)
        return;
    NODE *p = pHead;        //temp pointer to free mem later
    pHead = p->p_next;
    delete p;
}

//=========5
void removeTail(NODE *& pHead){
    if (pHead == NULL)
        return;
    NODE *pTemp = pHead;
    while (pTemp->p_next->p_next != NULL) {
        pTemp = pTemp->p_next;
    }
    pTemp->p_next = nullptr;
}

//=========6
void removeAll(NODE *& pHead){
    if (pHead == nullptr)
        return;
    NODE *p = pHead;
    NODE *temp = nullptr;
    while (p != nullptr){
        temp = p->p_next;
        delete p;
        p = temp;
    }
    pHead = nullptr;
}

//=========7
void removeBefore(NODE *& pHead, int val){
    if (pHead == NULL)
        return;
    
    NODE *p = pHead;
    while (p->p_next->p_next != nullptr){
        if (p->p_next->p_next->key == val){
            NODE* temp = p->p_next;
            p->p_next = p->p_next->p_next;
            delete temp;
            return;
        }
        p = p->p_next;
    }
}

//=========8
void removeAfter(NODE *& pHead, int val){
    if (pHead == NULL || pHead->p_next == nullptr)
        return;

    NODE *p = pHead;
    while (p->p_next != nullptr) {
        if (p->key == val){
            NODE * temp = p->p_next;
            p->p_next = p->p_next->p_next;
            delete temp;
            return;
        }
        p = p->p_next;
    }
}

//=========9
bool addPos(NODE *& pHead, int data, int pos){
    if(pHead == NULL)
        return false;
    if (pos == 0){
        addHead(pHead, data);
        return true;
    }
    if(pos < 0)
        return false;
    NODE *p = pHead;
    int i = 0;
    for ( ;i < pos - 1 && p != nullptr; i++, p = p->p_next);

    if (i < pos - 1){
        cout << "Out of range" << endl;
        return false;
    }
    NODE * newNode = createNode(data);
    newNode->p_next = p->p_next;
    p->p_next = newNode;
    return true;
}

//========10
void removePos(NODE * &pHead, int pos){
    if (pHead == NULL)
        return;
    if (pos == 0){
        removeHead(pHead);
        return;
    }
    NODE *p = pHead;
    int i = 0;
    for (;i < pos - 1 && p != nullptr; i++, p = p->p_next);

    if(p == nullptr){
        cout << "Out of range" << endl;
        return;
    }
    //p is now the preceding node of pos
    NODE *temp = p->p_next;     //node at pos
    p->p_next = temp->p_next;
    delete temp;
}

//========11
void addBefore(NODE *& pHead, int data, int val){
    if (pHead == NULL)
        return;
    
    if (pHead->key == val){
        addHead(pHead, data);
        return;
    }
    NODE *newNode = createNode(data);
    NODE *p = pHead;
    
    while(p->p_next->key != val){
        p = p->p_next;
    }
    newNode->p_next = p->p_next;
    p->p_next = newNode;
}

//========12
void addAfter(NODE *& pHead, int data, int val){
    if (pHead == NULL)
        return;
    
    NODE *newNode = createNode(data);
    NODE *p = pHead;
    while(p->key != val && p != NULL){
        p = p->p_next;
    }
    if (p == NULL){
        cout << "No value found!" << endl;
        return;
    }
    newNode->p_next = p->p_next;
    p->p_next = newNode;
}

//========13
void printList(NODE *pHead){
    NODE *p = pHead;
    while(p != nullptr){
        cout << p->key << " ";
        p = p->p_next;
    }
    cout << endl;
}

//========14
int countElements(NODE *pHead){
    NODE *p = pHead;
    int count = 0;
    while(p != nullptr){
        count++;
        p = p->p_next;
    }
    return count;
}

//========15
int countAppearance(NODE *pHead, int value){
    NODE *p = pHead;
    int count = 0;
    while(p != nullptr){
        if(p->key == value)
            count++;
        p = p->p_next;
    }
    return count;
}

//========16
NODE *reverseListWithoutChangingOriginalList(NODE *pHead){
    if (pHead == NULL)
        return NULL;
    NODE *newHead = nullptr;
    NODE *p = pHead;
    while(p != NULL){
        addHead(newHead, p->key);
        p = p->p_next;
    }
    return newHead;
}
NODE *reverseList(NODE *& pHead){
    if (pHead == NULL)
        return NULL;
    
    NODE *current = pHead;
    NODE *next = NULL, *prev = NULL;
    while(current != NULL){
        next = current->p_next;
        current->p_next = prev;
        prev = current;
        current = next;
    }
    pHead = prev;
    return pHead;
}
/*
#include <iostream>
using namespace std;

struct Node{
    int key;
    Node *next;
};
Node *createNode(int so){
    Node *p = new Node;
    p->key = so;
    p->next = NULL;
    return p;
}
void addTail(Node *&head, int val){
    Node *p = createNode(val);
    if (head == NULL){
        head = p;
        return;
    }
    Node * i = head;
    while(i->next != NULL)
        i = i->next;
    i->next = p;
}
void printKey(Node *head){
    if (head == NULL){
        cout << "Empty list\n";
        return;
    }
    Node* i= head;
    while(i != NULL){
        cout << i->key << " ";
        i = i->next;
    }
    cout << endl;
}

int main()
{
    int a[] = {4,5,21,28,29,18,60,73,86};
    int n = sizeof(a)/sizeof(a[0]);
    Node *p = NULL;
    for (int i = 0; i < n; i++){
        addTail(p,a[i]);
    }
    printKey(p);
    Node* iter = p;
    int sum = 0;
    /*iter->next->next = iter;
    cout << iter->next->next->next->next->key << endl;
    
    //cout << iter->next->next->next->next->next->next->next->key << endl;
    while(iter->key < iter->next->key){
        iter = iter->next;
        sum += iter->key;
    }
    cout << sum;
    

    return 0;
}
*/

//=======17
void removeDuplicate(NODE *& pHead){
    for (NODE *i = pHead; i->p_next != nullptr && i != NULL; i = i->p_next){
        for (NODE *j = i; j->p_next != nullptr; ){
            if (i->key == j->p_next->key){
                NODE *temp = j->p_next;
                j->p_next = temp->p_next;
                delete temp;
            }// once a key is deleted, pointer p should remain unchanged to check the rest
            else
                j = j->p_next;
        }
    }
}

//=======18
bool removeElement(NODE *&pHead, int k){
    if(pHead == NULL)
        return true;

    bool flagForCheckAppearance = false;
    while(pHead->key == k){
        flagForCheckAppearance = true;
        removeHead(pHead);
    }
    
    for (NODE *i = pHead; i != NULL && i->p_next != NULL; ){
        if (i->p_next->key == k){
            NODE * temp = i->p_next;
            i->p_next = temp->p_next;
            delete temp;
            flagForCheckAppearance = true;
        }// i remains unchanged to check the next one, to which has just been pointed by i
        else
            i = i->p_next;
    }
    return flagForCheckAppearance;
}


int main(){
    int n;
    cin >> n;
    NODE *start = new NODE[n];
    start = nullptr;
    srand(time(NULL));

    for (int i = 0; i < n; i++)
        addTail(start, rand() % 10);
    cout << "Before: \n";
    printList(start);

    int a,b,c,d,e,f;

    /*cout << "value to append: "; cin >> a;
    cout << "value to push: "; cin >> b;
    addTail(start,a);
    addHead(start,b);
    cout << "After: \n";
    printList(start);

    cout << "deleting the 1st node....\n";
    removeHead(start);
    cout << "deleting the last node....\n";
    removeTail(start);
    printList(start);*/

    /* cout << "Remove an integer before: "; cin >> a;
    removeBefore(start,a);
    cout << "Remove an integer after: "; cin >> b;
    removeAfter(start,b);
    cout << "After: ";
    printList(start);  */

    /* cout << "Add an integer before: "; cin >> a;
    addBefore(start,50,a);
    cout << "Add an integer after: "; cin >> b;
    addAfter(start,99,b);
    cout << "After: ";
    printList(start); */

    int x; cin >> x;
    //cout << countAppearance(start,x) << endl;
    
    cout << "After: \n";
    //NODE *p = reverseListWithoutChangingOriginalList(start);
    // printList(p);
    //removeDuplicate(start);
    //removeElement(start,x);
    //addPos(start,999,x);
    printList(start);

    return 0;
}
