#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

//==============Q1===================
bool question1(string s){
    char *str = new char[s.length()+1];
    strcpy(str,s.c_str());
    
    char *p = strtok(str, " !?.:,");
    vector <char*> a;
    
    while (p != NULL){
        a.push_back(p);
        p = strtok(NULL, " !?.:,");
    }
    for (int i = 0; i < a.size(); i++)
        for (int j = 0; j < strlen(a[i]); j++)
            a[i][j] = tolower(a[i][j]);
            
    for (int i = 0; i < a.size()/2; i++)
        if (strcmp(a[i],a[a.size() - i - 1]) != 0)
            return false;
    return true;
}

//==============Q2===================
typedef struct Node* Ref;
struct Node{
    int key;
    Ref next;
};
Ref createNode(int data){
    Ref newNode = new Node;
    newNode->key = data;
    newNode->next = NULL;
    return newNode;
}
void addTail(Ref &head, Ref &tail, int data){
    Ref p = createNode(data);
    if (head == NULL){
        head = tail = p; 
        return;
    }
    Ref i = head;
    while(i->next != NULL)
        i = i->next;
        
    i->next = p;
    tail = i->next;
}
void printList(Ref head){
    if (head == NULL){
        cout << "empty list!\n";
        return;
    }
    while (head != NULL){
        cout << head->key << " ";
        head = head->next;
    }
    cout << endl;
}

int question2(Ref head, Ref tail, Ref h, Ref t){
    int count = 0;
    
    for (Ref i = head; i != NULL; ){
        if (i->key == h->key){
            Ref j = i;
            Ref k = h;
            for ( ; j != NULL && k != NULL; j = j->next, k = k->next)
                if (j->key != k->key)
                    break;
            if (k == NULL)
                count++;
            i = j;
        }
        else 
            i = i->next;
    }
    return count;
}

//=============Q3===================
bool question3(float dollar, int noc){
    if (dollar < 0 || noc < 0) return false;
    if (dollar == 0 && noc == 0) return true;
    float coin[4] = {0.25, 0.1, 0.05, 0.01};
    
    bool checkFormed;
    for (int i = 0; i < 4; i++){
        checkFormed = question3(dollar - coin[i], noc - 1);
        if (checkFormed)
            return true;
    }
    return false;
}

int main()
{
    /*string s = "Information school graduate seeks graduate school information.";
    string s1 = "Herb the sage eats sage, the herb.";
    string s2 = "First ladies rule the State and state the rule: ladies first!";
    string s3 = "You can cage a swallow, can't you, but you can't swallow a cage, can you?";
    //getline(cin,str);
    cout << question1(s) << endl;
    cout << question1(s1) << endl;
    cout << question1(s2) << endl;
    cout << question1(s3) << endl;*/
    
    /* Ref start, end;
    start = end = NULL;
    int a[] = {5,3,3,7,7,9,3,7};
    int n = sizeof(a)/sizeof(a[0]);
    
    for (int i = 0; i < n; i++)
        addTail(start, end, a[i]);
    printList(start);
    
    int b[] = {3,7};
    int nb = sizeof(b)/sizeof(b[0]);
    Ref substart, subend;
    substart = subend = NULL;
    for (int i = 0; i < nb; i++)
        addTail(substart,subend, b[i]);
    printList(substart);
    
    cout << question2(start,end, substart, subend) << endl; */

    float Dollar;
    int numberOfCoins;
    cin >> Dollar >> numberOfCoins;

    cout << (question3(Dollar,numberOfCoins)? "Yes" : "No") << endl;

    return 0;
}
