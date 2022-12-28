#include <iostream>
#include <algorithm>
#include <string>
#include <iomanip>
using namespace std;

void printArray(int a[], int n){
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
}

int LinearSearch(int a[], int n, int k){
    a[n] = k;
    int i;
    for (i = 0; a[i] != k; i++){}
    if (i < n) return i;
    return -1;
}

//==========2===========
void remove(int a[], int n, int removeItem){
    if (n < 1){
        cout << "The array is empty" << endl;
        return;
    }
    else if (LinearSearch(a,n,removeItem) == -1){
        cout << "The value does not exist" << endl;
        return;
    }
    else{
        for (int i = 0; i < n; i++){
            if (LinearSearch(a,n,removeItem) == i){
                for (int j = i; j < n; j++)
                    a[j] = a[j+1];
                n--;
                break;
            }
        }
        printArray(a,n);
    }
}

//==========3===========
void removeAt(int a[], int n, int index){
    if (n < 1){
        cout << "The array is empty!" << endl;
        return;
    }
    else if (index >= n){
        cout << "The index is out of range!" << endl;
        return;
    }
    else {
        for (int i = 0; i < n; i++){
            if (i == index){
                for (int j = i; j < n; j++)
                    a[j] = a[j+1];
                n--;
            }
        }
        printArray(a,n);
    }
}

//==========4===========
void removeAll(int a[], int n, int removeItem){
    if (n < 1){
        cout << "The array is empty!" << endl;
        return;
    }
    else if (LinearSearch(a,n,removeItem) == -1){
        cout << "The value does not exist!" << endl;
        return;
    }
    else {
        for (int i = 0; i < n; i++){
            if (LinearSearch(a,n,removeItem) == i){
                for (int j = i; j < n; j++)
                    a[j] = a[j+1];
                n--;
            }
        }
        printArray(a,n);
    }
}

//==========5===========
struct element{
    int value, index, count;
};
void swapElement(element *a, element *b){
    element temp = *a;
    *a = *b;
    *b = temp;
}
void InterchangeSort_AscendingOrder(element a[], int n){
    for (int i = 0; i < n-1; i++){
        for (int j = i + 1; j < n; j++){
            if (a[i].value > a[j].value)
                swapElement(&a[i], &a[j]);
            else if (a[i].value == a[j].value && a[i].index > a[j].index)
                swapElement(&a[i], &a[j]);
        }
    }
}
bool Larger(element a, element b){
    return a.value < b.value;
}
void sortByDecreasingFrequency(int a[], int n){
    element temp[n];
    //=========================Assigning to temp array=========================
    for (int i = 0; i < n; i++){
        temp[i].value = a[i];
        temp[i].index = i;
        temp[i].count = 1;
    }
    //stable_sort(temp,temp+n,Larger);
    InterchangeSort_AscendingOrder(temp, n);
    for (int i = 0; i < n;){
        int j = i+1;
        while (temp[i].value == temp[j].value){
            temp[i].count++;
            temp[j].count = 0;
            j++;
        }
        i = j;
    }
    //===================Delete elements that have 0 count=======================
    int sizetemp = n;
    for (int i = 0; i < sizetemp; i++){
        if (temp[i].count == 0){
            for (int j = i; j < sizetemp; j++)
                temp[j] = temp[j+1];
            sizetemp--;
            i--;
        }
    }
    // for (int j = 0; j < sizetemp; j++)
    //     cout << "value: " << temp[j].value << "  index: " << temp[j].index <<"  count: "<< temp[j].count << endl;

    //=========================Sorting temp array by frequency (& index if the same frequency)===============
    for (int i = 0; i < sizetemp-1; i++){
        for (int j = i+1; j < sizetemp; j++){
            if (temp[i].count < temp[j].count)
                swapElement(&temp[i],&temp[j]);
            else if(temp[i].count == temp[j].count && temp[i].index > temp[j].index)
                swapElement(&temp[i],&temp[j]);
        }
    }
    /* cout << "================\n";
    for (int j = 0; j < sizetemp; j++)
        cout << "value: " << temp[j].value << "  index: " << temp[j].index <<"  count: "<< temp[j].count << endl; */

    //========================Assigning back from temp array to a[]=====================================
    for (int i = 0, index = 0; i < sizetemp; i++){
        for (int j = 0; j < temp[i].count; j++){
            a[index++] = temp[i].value;
        }
    }
    printArray(a,n);
}

//==========6===========
void NumberOfInversions(int a[], int n){
    int count = 0;
    for (int i = 0; i < n-1; i++){
        for (int j = i+1; j < n; j++)
            if (a[i] > a[j]) count++;
    }
    cout << count << endl;
}

//==========7===========
void printArrayOfString (string a[], int n){
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
}
void SortStringAlphabetically(string a[], int n){
    for (int i = 0; i < n-1; i++){
        for (int j = i+1; j < n; j++){
            if (a[i] > a[j]){
                string temp = a[i]; 
                a[i] = a[j]; 
                a[j] = temp;
            }
        }
    }
    printArrayOfString(a,n);
}
bool is_ArrayofString_SortedAlphabetically(string a[], int n){
    int count = 0;
    for (int i = 0; i < n-1; i++) {
        if (a[i] <= a[i+1])
            count++;
    }
    return count == n-1;
}
void outputDistinctStringifSorted(string a[], int n){
    if (is_ArrayofString_SortedAlphabetically(a,n))
        for (int i = 0; i < n; ){
            int count = 1;
            int j = i+1;
            while(a[i] == a[j]){
                count++;
                j++;
            }
            cout << a[i] << ": " << count << " ";
            i = j;
        }
    else cout << "The array is not sorted alphabetically\n";
}

//==========8===========
void InputScores(int a[], int &n){
    int i = 0, score;
    cout << "Input scores(Limit: 100). Enter -999 to stop inputting." << endl;
    while (cin >> score){
        if (score > 100){
            cout << "Score is over 100. Invalid scores!\nEnter again: ";
            cin >> score;
        }
        if (score < 0 && score != -999){
            cout << "Score is below 0. Invalid scores!\nEnter again: ";
            cin >> score;
        }
        else if (score == -999) break;
        else {
            a[i] = score;
            i++;
        }
    }
    n = i;
}
void swapNum(int * a, int * b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
void heapify(int a[],int n, int i){
    int largest = i;
    int left = 2*i+1;
    int right = 2*i+2;
    if (left < n && a[left] >  a[largest])
        largest = left;
    if (right < n && a[right] > a[largest])  
        largest = right;
    if (largest > i){
        swapNum(&a[i],&a[largest]);
        heapify(a,n,largest);
    }
    
}
void HeapSort(int a[], int n){
    // Build a MaxHeap from index n/2
    for (int i = n/2; i >= 0; i--)
        heapify(a,n,i);

    for (int i = n-1; i >= 0 && n > 0; i--){
        swapNum(&a[0],&a[i]);
        n--;
        heapify(a,n,0);
    }

}
void PrintTestScores(int a[], int n){
    InputScores(a,n);
    HeapSort(a,n);
    cout << "Test Scores " << setw(12) << " Count\n";
    for (int i = 0; i < n; ){
        int count = 1;
        int j = i + 1;
        while (a[i] == a[j]){
            count++;
            j++;
        }
        cout << setw(7) << a[i] << setw(14) << count << endl;
        i = j;
    }
}

//==========9===========
const int ArraySize = 5;
#include <cstdlib>
#include <ctime>
#include <locale>
void SelectionSort(int a[], int n){
    for (int i = 0; i < n-1; i++){
        int smallest = i;
        for (int j = i+1; j < n; j++){
            if (a[smallest] > a[j])
                smallest = j;
        }
        swapNum(&a[smallest],&a[i]);
    }
}
void Generate_5_Distinct_LotteryNums_And_Sort(int a[]){
    int n = ArraySize;
    int min = 1;
    int max = 40;
    srand(time(NULL));
    for (int i = 0; i<n; i++){
        a[i] = rand() %(max - min + 1 ) + min ;
    }
    SelectionSort(a,n);
}
void Get_5_Distinct_LotteryNums_From_Player(int b[]){
    cout << "Enter 5 distinct integers from 1 to 40: " << endl;
    int i = 0;
    int option;
    while (i < ArraySize){
        cin >> option;
        if (option < 1 || option > 40){
            cout << "Please choose again: ";
            continue;
        }
        else{
            int CountSameNum = 0;
            if (i > 0){
                for (int j = 0; j <= i; j++){
                    if (option == b[j]){
                        cout << "You have already chosen this number. Please choose again: ";
                        CountSameNum++;
                        break;
                    }
                }
            }
            if (CountSameNum == 0)
                b[i++] = option;
        }
    }
}
bool checkLotteryNums(int a[], int b[]){
    int i = 0;
    int count = 0;
    while (i < ArraySize){
        for (int j = 0; j < ArraySize; j++){
            if (a[i] == b[j])
                count++;
        }
        i++;
    }
    return count == ArraySize;
}
int WeeklyLotteryProgram(){
    int Random[ArraySize], Selection[ArraySize];
    char response;
    cout << "Do you want to play Lottery? (Y/y)/(N/n): ";
    cin >> response;
    while (tolower(response) == 'y'){
        Generate_5_Distinct_LotteryNums_And_Sort(Random);
        Get_5_Distinct_LotteryNums_From_Player(Selection);
        if (checkLotteryNums(Random,Selection))
            cout << "=======You win!========" << endl;
        else {
            cout << "=======You lose!=======" << endl;
            cout << "The lottery numbers are: ";
            printArray(Random,ArraySize);
            cout << "And you chose: ";
            printArray(Selection,ArraySize);
        }
        cout << "Do you want to play again? (Y/y)/(N/n):";
        cin >> response;
    }
    cout << endl;
    return 0;
}

//========10===========
void DutchNationalFlagSort0_1_2(int a[], int n){
    int low = 0, mid = 0;
    int high = n-1;
    while (mid <= high){
        switch(a[mid]){
            case 0:
                swapNum(&a[low++], &a[mid++]);
                break;
            case 1: 
                mid++;
                break;
            case 2:
                swapNum(&a[high--], &a[mid]);
                break;
        }
    }
    printArray(a,n);
}

int main(){
    int a1[] = {2,3,2,4,5,3,6};
    int n1 = sizeof(a1)/sizeof(a1[0]);
    //remove(a1,n1,3);
    //removeAt(a1,n1,7);
    //removeAll(a1,n1,2);
    int a2[] = {2,5,2,8,5,6,8,8};
    int n2 = sizeof(a2)/sizeof(a2[0]);
    int a3[] = {2,5,2,6,-1,9999999,5,8,8,8};
    int n3 = sizeof(a3)/sizeof(a3[0]);
    //sortByDecreasingFrequency(a3,n3);

    int a4[] = {8,4,2,1};
    int n4 = sizeof(a4)/sizeof(a4[0]);
    int a5[] = {3,1,2};
    int n5 = sizeof(a5)/sizeof(a5[0]);
    //NumberOfInversions(a4,n4);

    string a6[] = {"Farm","Zoo","Car","Apple","Bee","Golf","Bee","Dog","Golf","Zoo","Zoo","Bee","Bee","Apple"};
    int n6 = sizeof(a6)/sizeof(a6[0]);
    /* SortStringAlphabetically(a6,n6);
    outputDistinctStringifSorted(a6,n6); */

    int a7[] = {55,80,78,92,95,55,78,53,92,65,78,95,85,92,85,95,95};
    int n7 = sizeof(a7) / sizeof(a7[0]);
    int a8[101],n8;
    //PrintTestScores(a8,n8);

    //WeeklyLotteryProgram();

    int a9[] = {1,2,0,2,1,1,0,0,2,1,2,0,2,1};
    int n9 = sizeof(a9)/sizeof(a9[0]);
    DutchNationalFlagSort0_1_2(a9, n9);
    
    return 0;
}
