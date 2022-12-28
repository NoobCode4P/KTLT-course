#include <iostream>
#include <fstream>
//#include <string>
using namespace std;

//======1a
void printList(int **a, int p, int q){
    for (int i = 0; i < p; i++){
        for (int j = 0; j < q; j++)
            cout << a[i][j] << " ";
        cout << endl;
    }
}

//======1b
int ucln(int a, int b){
    while(a % b != 0){
        int sodu = a % b;
        a = b;
        b = sodu;
    }
    return b;
}
int ** generateMatrix(int p, int q){
    int **a = new int*[p];
    for (int i = 0; i < p; i++)
        a[i] = new int[q];

    int value = 1;
    for (int i = 0; i < p; i++){
        for(int j = 0; j < q; j++){
            a[i][j] = value;
        }
        value++;
    }
    return a;
}
int **createNewMatrix(int **a, int p, int q){
    int n = ucln(p,q);

    int **c = new int*[p/n];
    for (int i = 0; i < n; i++)
        c[i] = new int[q/n];

    for (int i = 0; i < p/n; i++){
        for (int j = 0; j < q/n; j++)
            c[i][j] = 0;
    }
    int row = 0, col = 0;
    for (int i = 0; i < p; i++){
        if(i > 0 && i % n == 0)
            row++;    
        for (int j = 0; j < q; j++){
            if (j % n == 0 && j > 0)
                col++;
            c[row][col] += a[i][j];
        }
        col = 0;
    }
    return c;
}

//======2
int count2(int n, int m){
    if (n == 1)
        return 1;

    int count = 0;
    for (int i = m; i > 1; i--){
        if (n % i == 0)
            count += count2(n/i, i);
    }
    return count;
}
/*#include <iostream>
using namespace std;
#define MAX 10000
int ways;
int curmulti=1;
int a[MAX];
int i = 0;
void Try(int k, int n) {
    for(int j=k;j<i;j++) {
        if(curmulti*a[j]<=n) {
            curmulti *= a[j];
            if(curmulti == n)
                ways++;
            else
                Try(j,n);
            curmulti /= a[j];
        }else
            break;
    }
}
int main() {
    int n,m;
    cin >> n >> m;
    for(int j=2;j<=m;j++) {
        if(n%j==0)
            a[i++] = j;
    }
    Try(0,n);
    cout << ways;
    return 0;
}*/

//======3
struct Info{
    string name;
    int height;
    int weight;
};
struct NODE{
    Info key;
    NODE *Next;
};
//======4a
struct People{
    NODE *head;
    NODE *tail;
};
NODE * makeNode(string ten, int cao, int nang){
    NODE *p = new NODE;
    p->key.name = ten;
    p->key.height = cao;
    p->key.weight = nang;
    p->Next = NULL;
    return p;
}
void appendList(People &list, string ten, int cao, int nang){
    NODE *p = makeNode(ten,cao,nang);
    if(list.head == NULL){
        list.head = list.tail = p;
        return;
    }
    list.tail->Next = p;
    list.tail = p;
}
//======4b
People readfile(){
    ifstream in("people.txt");
    if(!in){
        cout << "Unable to open file\n";
        exit(1);
    }
    string ten;
    string cao;
    string nang;
    People List = {NULL,NULL};
    while(!in.eof()){
        getline(in, ten,'-');
        getline(in,cao,'-');
        getline(in,nang);

        appendList(List,ten,stoi(cao),stoi(nang));
    }
    in.close();
    return List;
}
//======4c
void printPeople(People P){
    if(P.head == NULL){
        cout << "Empty list\n";
        return;
    }
    NODE *i = P.head;
    while(i != NULL){
        cout << i->key.name << endl;
        i = i->Next;
    }
}
//=====4d
void removeLastPersonWithHeightGreaterThanX(People &P, int X){
    if (P.head == NULL){
        cout << "Empty list\n";
        return;
    }

    NODE *i = P.head;
    People largerthanX = {NULL,NULL};
    while(i != NULL){
        if (i->key.height > X)
            appendList(largerthanX,i->key.name,i->key.height,i->key.weight);
        i = i->Next;
    }

    NODE *lastperson = largerthanX.tail;
    i = P.head;

    while(i->Next->key.name != lastperson->key.name)
        i = i->Next;

    NODE *temp = i->Next;
    i->Next = temp->Next;
    delete temp;
}


int main(){
    /* int a[][9] = {
        {1,1,1,1,1,1,1,1,1},
        {2,2,2,2,2,2,2,2,2},
        {3,3,3,3,3,3,3,3,3},
        {4,4,4,4,4,4,4,4,4},
        {5,5,5,5,5,5,5,5,5},
        {6,6,6,6,6,6,6,6,6}
    }; */

    /* int **a = generateMatrix(6,9);
    cout << "Matrix A: \n";
    printList(a,6,9);
    int **sum = createNewMatrix(a,6,9);
    
    cout << "Matrix sum: \n";
    int n = ucln(6,9);
    printList(sum,6/n,9/n);
 */

   /*  People dsach = readfile();
    printPeople(dsach);
    cout << "==========Removing...." << endl;
    removeLastPersonWithHeightGreaterThanX(dsach,190);
    printPeople(dsach);
 */
    cout << count2(100,11) << endl;
    return 0;
}