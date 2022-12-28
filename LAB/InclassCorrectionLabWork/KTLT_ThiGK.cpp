#include <iostream>
#include <ctime>
#include <cstdlib>
#include <algorithm>
using namespace std;

void SwapInt(int &a, int &b){
    int t = a;
    a = b;
    b = a;
}

void sort1DArray(int *a, int n){
    
}

void Sort(int a[][3], int n, int m){
    for (int i = 0; i<n; i++)
        sort1DArray(a[i],m);
        //sort(a[i],a[i]+m);
}

void print2dArray(int a[][3], int n , int m){
    for (int i = 0; i<n; i++){
        for (int j = 0; j<m; j++)
            cout << *(*(a+i)+j) << " "; 
        cout << endl;
    }
}

void sortRowWise(int m[][3],int r, int c)
{
  // loop for rows of matrix
  for (int i = 0; i < r; i++)
  {
    // loop for column of matrix
    for (int j = 0; j < c; j++)
    {
      // loop for comparison and swapping
      for (int k = 0; k < c - j - 1; k++)
      {
        if (m[i][k] > m[i][k + 1])
        {
          // swapping of elements
          swap(m[i][k], m[i][k + 1]);
        }
      }
    }
  }
  // printing the sorted matrix
//   for (int i = 0; i < r; i++)
//   {
//     for (int j = 0; j < c; j++)
//       cout << m[i][j] << " ";
//     cout << endl;
//   }
}

void GenerateRandomNum(int a[][3], int n, int m){
    int min = 1, max = 99;
    srand(time(NULL));
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++)
            a[i][j] = rand() % (max - min +1) + min;
    }
}

int main()
{
    int n,m;
    n = m = 3;
    int a[][3] = {
        {72,55,18},
        {21,90,33},
        {65,89,42}
    };
    
    // int (*ptr)[m];
    // ptr = a;
    //GenerateRandomNum(a,n,m);
    cout << "Before: \n";
    print2dArray(a,n,m);
    //Print(a,n,m);
    cout << "After: \n";
    Sort(a,n,m);
    //sortRowWise(a,n,m);
    print2dArray(a,n,m);


    return 0;
}
