#include <iostream>
using namespace std;

//=============1a
void printMatrixA(int **a, int p, int q){
    for (int i = 0;  i < p; i++){
        for (int j = 0; j < q; j++)
            cout << a[i][j] << " ";
        cout << endl;
    }
}

//=============1b
int** generateCmatrix(int** a, int p, int q, int n){
    if (n > p || n > q) 
        return NULL;

    int **c = new int*[n];
    for (int i = 0; i < n; i++)
        c[i] = new int[2*n];
    
    int **Max = new int*[n];
    for (int i = 0; i < n; i++)
        Max[i] = new int[n];

    int **Min = new int*[n];
    for (int i = 0; i < n; i++)
        Min[i] = new int[n];

    int cursum = 0;
    int maxsum, minsum;
    maxsum = -999;
    minsum = 999;
    int minRowIndex = 0;
    int minColIndex = 0;
    int maxRowIndex = 0;
    int maxColIndex = 0;
    for (int i = 0; i <= p-n; i++){
        for (int j = 0; j <= q-n; j++){
            
            for (int row = i; row < i+n; row++){
                for (int col = j; col < j+n; col++){
                    cursum += a[row][col];
                }
            }
            if (cursum < minsum){
                minsum = cursum;
                minColIndex = j;
                minRowIndex = i;
            }
            if (cursum > maxsum){
                maxsum = cursum;
                maxColIndex = j;
                maxRowIndex = i;
            }
            
            cursum = 0;
        }
    }    
    int rowMin = 0;
    int colMin = 0;
    int rowMax = 0;
    int colMax = 0;
    for (int i = 0; i <= p-n; i++){
        for (int j = 0; j <= q-n; j++){
            if (i == minRowIndex && j == minColIndex){
                for(int k = i; k < i+n; k++){
                    for (int l = j; l < j+n; l++){
                        Min[rowMin][colMin++] = a[k][l];
                    }
                    rowMin++;
                    colMin = 0;
                }
            }
            if (i == maxRowIndex && j == maxColIndex){
                for(int k = i; k < i+n; k++){
                    for (int l = j; l < j+n; l++){
                        Max[rowMax][colMax++] = a[k][l];
                    }
                    rowMax++;
                    colMax = 0;
                }
            }
        }
    }
    
    for (int i = 0; i < n; i++){
        for (int j = 0; j < 2*n; j++){
            if (j < n){
                c[i][j] = Min[i][j];
            }
            else{
                c[i][j] = Max[i][j - n];
            }
        }
    }
    return c;
}
int **ExArray(){
    int ** a = new int*[6];
    for (int i = 0; i < 6; i++) 
        a[i] = new int[6];

    for (int i = 0; i < 6; i++){
        for (int j = 0; j < 6; j++){
            if (i < 3)
                a[i][j] = j+1;
            else {
                if (j < 3)
                    a[i][j] = 1;
                else 
                    a[i][j] = 3;
            }
        }
    }
    return a;
}
//=============2
bool isPrime(int n){
    if (n <= 1)
        return false;
    for (int i = 2; i*i <= n; i++)
        if (n % i == 0)
            return false;
    return true;
}

int sumofPrimeDivisor(int n, int i){
    if (n % i == 0){
        if (isPrime(i))
            return i + sumofPrimeDivisor(n,i+1);
        if (i*i > n) 
            return 0;
    }
    return sumofPrimeDivisor(n,i+1);
}

int main(){
    //int x; cin>>x;
    //cout << sumofPrimeDivisor(x,1) << endl;
    /* int b[][6] = {
        {1, 2, 3, 4, 5, 6},
        {1, 2, 3, 4, 5, 6},
        {1, 2, 3, 4, 5, 6},
        {1, 1, 1, 3, 3, 3},
        {1, 1, 1, 3, 3, 3},
        {1, 1, 1, 3, 3, 3},
    }; */
    
    int **a = ExArray();
    int **C = generateCmatrix(a,6,6,3);
    printMatrixA(a,6,6);
    cout << "============\n";
    printMatrixA(C,3,6);

    return 0;
}