#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
using namespace std;
//===========Searching===================
int SequentialSearch(int a[], int n, int k){
    for (int i = 0; i < n; i++){
        if (a[i] == k) return i;
    }
    return -1;
}

int BinarySearch(int a[], int n, int k){
    int left = 0;
    int right = n-1;
    while (left <= right){
        int mid = (left + right) / 2;
        if (a[mid] == k)
            return mid;
        if (a[mid] < k) 
            left = mid+1;
        if (a[mid] > k)
            right = mid-1;
    }
    return -1;
}

int SequentialSearchWithSentinel(int a[], int n, int k){
    a[n] = k;
    int i = 0;
    while (a[i] != k)
        i++;
    if (i < n) return i;
    return -1;
}

int RecursiveBinarySearch(int a[], int left, int right, int key) {
    if(left <= right){
        int mid = (left + right)/2;
        if (a[mid] == key) return mid;
        else {
            if (a[mid] > key)
                return RecursiveBinarySearch(a, left, mid-1, key);
            else if (a[mid] < key)
                return RecursiveBinarySearch(a, mid+1, right, key);
        }
    }
    return -1;
}

int InterpolationSearch(int a[], int n, int k){
    int L = 0, R = n-1;
    while (L <= R){
        int M = ((k - a[L])*(R - L)) / (a[R] - a[L]) + L;
        if (a[M] == k)
            return M;
        if (a[M] < k)
            L = M+1;
        else R = M-1;
    }
    return -1;
}

//=============Sorting===================
void SwapInt(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}
void printArray(int a[], int n){
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
}

void SelectionSort(int a[], int n){
    for (int i = 0; i < n-1; i++){
        int IndxS = i;
        for (int j = i+1; j < n; j++){
            if (a[IndxS] > a[j])
                IndxS = j;
        }
        SwapInt(a[IndxS], a[i]);
    }
}

void InsertionSort(int a[], int n){
    for (int i = 1; i < n; i++){
        int key = a[i];
        int j = i-1;
        while (j >= 0 && a[j] > key){
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = key;
    }
}

void BubbleSort(int a[], int n){
    for (int i = 1; i < n; i++){
        for (int j = n-1; j >= i; j--){
            if (a[j] < a[j-1])
                SwapInt(a[j], a[j-1]);
        }
    }
}

void InterchangeSort(int a[], int n){
    for (int i = 0; i < n-1; i++){
        for (int j = i+1; j < n; j++)
            if (a[i] > a[j])
                SwapInt(a[i],a[j]);
    }
}

void InsertionSortWithSentinel(int a[], int n){
    int sto = a[0];
    for (int i = 1; i < n; i++){
        int key = a[i];
        int j = i-1;
        a[0] = key;
        while (key < a[j]){
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = key;
    }
    int index = 1;
    while(a[index] < sto){
        a[index - 1] = a[index];
        index++;
    }
    a[index - 1] = sto;
}

void BinaryInsertionSort(int a[], int n){
    int key;
    for (int i = 1; i < n; i++){
        key = a[i];
        int left = 0, right = i-1, mid;
        while (left <= right){
            mid = (left + right) / 2;
            if (key < a[mid])
                right = mid - 1;
            else
                left = mid + 1;
        }
        for (int j = i-1; j >= left; j--)
            a[j+1] = a[j];
        
        a[left] = key;
    }
}

void ImprovedBubbleSort(int a[], int n){
    for (int i = 1; i < n; i++){
        int count = 0;
        for (int j = n; j >= i; j--){
            if (a[j] < a[j-1]){
                SwapInt(a[j], a[j-1]);
                count++;
            }
        }
        if (count == 0) return;
    }
}

void ShakerSort(int a[], int n){
    int l = 1, r = n-1;
    int i,j;
    while (l <= r){
        for (i = r; i >= l; i--){
            if (a[i] < a[i-1])
                SwapInt(a[i],a[i-1]);
        }
        l = i+1;
        for (j = l; j < r; j++){
            if (a[j] > a[j+1])
                SwapInt(a[j],a[j+1]);
        }
        r = j-1;
    }
}

//====================Practical Problem==========================
struct info{
    char pos[3];
    string name;
    int year;
    string team;
    string club;
};

void SetUpList(char *file, info players[], int &n){
    ifstream in(file);
    if (!in.is_open()){
        cout << "Cannot read file!" << endl;
        return;
    }
    int i = 0;
    while (!in.eof()){
        char Pos[3];
        in.getline(Pos,3,'/');

        string Name;
        getline(in, Name, '/');

        string Year;
        getline(in, Year, '/');

        string Team;
        getline(in, Team, '/');

        string Club;
        getline(in,Club);

        strcpy(players[i].pos, Pos);
        players[i].name = Name;
        players[i].year = stoi(Year);
        players[i].team = Team;
        players[i].club = Club;


        i++;
    }
    in.close();
    n = i;
}

void SwapPlayers(info &a, info &b){
    info temp = a;
    a = b;
    b = temp;
}
string LastName(string a){
    int indxOfLastWhitespace = a.find_last_of(" ");
    string lastname = a.substr(indxOfLastWhitespace+1);
    return lastname;
}
void SortPlayersByYear_Of_Birth_AndThenBy_LastName(info a[], int n){
    //Selection sort
    for(int i = 0; i < n-1; i++){
        int pos = i;
        for (int j = i+1; j < n; j++){
            if (a[j].year < a[pos].year)
                pos = j;
            if (a[j].year == a[pos].year){
                if (LastName(a[pos].name) > LastName(a[j].name))
                    pos = j;
            }
        }
        SwapPlayers(a[pos],a[i]);
    }
    for (int i = 0; i < n; i++)
        cout << a[i].year <<  " " << a[i].name << endl;
}

int main(){
    int a[] = {3,5,6,7,11,23,24,26,30,31,33,39,40};
    int a1[] = {3,5,4,2,12,2,6,10,35,1,7,5,8};
    int n = sizeof(a)/sizeof(a[0]);
    int n1 = sizeof(a1)/sizeof(a1[0]);
    int x; cin >> x;
    //cout << InterpolationSearch(a,n,x) << endl;
    cout << RecursiveBinarySearch(a,0,n-1,x) << endl;
    // SelectionSort(a1,n1);
    // InsertionSort(a1,n1);
    // BubbleSort(a1,n1);
    // InterchangeSort(a1,n1);
    // InsertionSortWithSentinel(a1,n1);
    // ShakerSort(a1,n1);
    // BinaryInsertionSort(a1,n1);
    // ImprovedBubbleSort(a1,n1);
    // printArray(a1,n1);

    char filename[] = {"Players.txt"};
    info list[100];
    int size;
    //SetUpList(filename,list,size);
    //SortPlayersByYear_Of_Birth_AndThenBy_LastName(list,size);


    // for (int i=0;i<size;i++)
    //     cout << list[i].name << endl;

    // cout << "Players born in 1994: " << endl;
    // for (int i = 0; i < size; i++){
    //     if (list[i].year == 1994)
    //         cout << "Name: " << list[i].name <<  endl;

    // }

/*
    cout << "Players play for Manchester United club: " << endl;
    for (int i = 0; i < size; i++){
        if (list[i].club == "Manchester United")
            cout << "Name: " << list[i].name << "\tPosition: " << list[i].pos  << "\tClub: " << list[i].club << endl;

    }

    cout << "FW players play for Manchester City: " << endl;
    for (int i = 0; i < size; i++){
        if (list[i].pos == "FW" && list[i].club == "Manchester City")
            cout << "Name: " << list[i].name << "\tPosition: " << list[i].pos  << "\tClub: " << list[i].club << endl;

    } */

    return 0;
}