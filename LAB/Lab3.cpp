#include <iostream>
#include <ctime>
using namespace std;

//===============1
void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

//===============2
int *sum(int *a, int *b){
    int *Sum = a;
    *Sum = *a + *b;
    return Sum;
}

//===============3
void inputArray(int *&a, int &n){
    cout << "Enter size of array: "; cin >> n;
    a = new int [n];
    cout << "Input Array: " << endl;
    for (int i = 0; i < n; i++){
        cout << "a[" << i << "] = ";
        cin >> a[i];
    }
}

//===============4
void printArray(int *a, int n){
    for(int i = 0; i < n; i++)
        cout << *(a+i) << " ";
    cout << endl;
}

//===============5
int *findMax(int *arr, int n){
    int max = arr[0];
    for (int i = 1; i < n; i++){
        if (arr[i] > max) 
            max = arr[i];
    }
    int *p2Max = &max;
    //return &max; 
    return p2Max;
}

//===============6
int * copyArray(int *arr, int n){
    int *p = new int[n];
    for (int i = 0; i < n; i++)
        *(p+i) = arr[i];
    return p;
}

//===============7
int *countEvens(int *arr, int n, int *&evens){
    int count = 0;
    for (int i = 0; i < n; i++)
        if (arr[i] % 2 == 0)
            count++;
    int *numEvens = &count;
    evens = new int[count];
    int j = 0;
    for (int i = 0; i < n; i++){
        if(arr[i] % 2 == 0){
            evens[j++] = arr[i];
        }
    }
    return numEvens;
}

int *genEvenSubarray(int *a, int n, int *count){
    int *mangChan = new int[*count];
    mangChan = countEvens(a,n,mangChan);
    return mangChan;
}

//==============8
int *findLargestTotalSubarray(int *a, int n, int &total, int &length){
    total = 0;
    int cur_sum = 0;
    int cur_length = 0;
    int idx;
    for (int i = 0; i < n-1; i++){
        cur_length = 1;
        cur_sum = a[i];
        for (int j = i+1; j < n; j++){
            cur_sum += a[j];
            cur_length++;
            if(cur_sum > total){
                total = cur_sum;
                length = cur_length;
                idx = i;
            }
        }
        
    }

    int *b = new int[length];
    for (int i = 0; i < length; i++){
        b[i] = a[idx++];
    }

    return b;
}

//==============9
int * findLongestAscendingSubarray(int *a, int n, int &length){
    int curLength = 0;
    length = 0;
    int idx;
    for (int i = 0; i < n - 1; i++){
        curLength = 1;
        for (int j = i + 1; j < n && a[j-1] <= a[j]; j++){
            curLength++;
        }
        if (curLength > length){
            idx = i;
            length = curLength;
        }
    }
    int *result = new int[length];
    for (int i = 0; i < length; i++)
        result[i] = a[idx++];

    return result;
}

//==============10
void swapArrays(int *&a, int *&b, int &na, int &nb){
    int *p = a;
    a = b;
    b = p;
    swap(na, nb);
}

//==============11
int *concatenate2Arrays(int *a, int *b, int na, int nb){
    int *c = new int[na + nb];
    int i = 0;
    for ( ; i < na; i++)
        c[i] = a[i];
    int b_index = 0;
    for ( ; i < na + nb; i++)
        c[i] = b[b_index++];
    return c;
}

//==============12
int *merge2Arrays(int *a, int *b, int na, int nb, int &nc) {
    nc = na + nb;
    int *m = new int[nc];
    int i, j, k;
    i = j = k = 0;
    do {
        for (; a[i] <= b[j] && i < na; i++)
            m[k++] = a[i];
        for (; a[i] > b[j] && j < nb; j++)
            m[k++] = b[j];
        if (j == nb){
            while(i < na)
                m[k++] = a[i++];
        }
        if (i == na){
            while(j < nb)
                m[k++] = a[i++];
        }
    }while(k < nc);
    return m;
}

//==============13
void print2DArray(int **a, int n, int m){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++)
            cout << a[i][j] << " ";
        cout << endl;
    }
}
void AlloMem2DArray(int **a, int n, int m){
    a = new int*[n];
    for (int i = 0; i < n; i++)
        a[i] = new int[m];
}
void generateMatrix1(int ** &A, int &length, int &width){
    cout << "Length: "; cin >> length;
    cout << "Width: "; cin >> width;
    A = new int*[length];
    for (int i = 0; i < length; i++)
        A[i] = new int[width]; 

    srand(time(NULL));

    for (int i = 0; i < length; i++)
        for (int j = 0; j < width; j++)
            A[i][j] = rand() % (50 - 20 + 1) + 20;
    
}

//==============14
int ** generateMatrix2(int *a, int *b, int na, int nb){
    int **c = new int*[na];
    for (int i = 0; i < na; i++)
        c[i] = new int[nb];

    for (int i = 0; i < na; i++)
        for (int j = 0; j < nb; j++)
            c[i][j] = a[i] * b[j];
    return c;
}

//===============15
void swapRows(int **a, int length, int width){
    //swap 2 1st rows
    for (int i = 0; i < width; i++)
        swap(a[0][i],a[1][i]);
}

void swapColumns(int **a, int length, int width){
    //swap 1st and 3rd columns
    for (int i = 0; i < length; i++)
        swap(a[i][0], a[i][2]);
}

//=============16
int **transposeMatrix(int **a, int length, int width){
    int **b = new int*[width];
    for (int i = 0; i < width; i++)
        b[i] = new int [length];
    //            TRANSPOSE
    //  1   2   3           1   4   7
    //  4   5   6           2   5   8
    //  7   8   9           3   6   9

    //  1   2           1   3   5
    //  3   4           2   4   6
    //  5   6

    for (int i = 0; i < width; i++)
        for (int j = 0; j < length; j++)
            b[i][j] = a[j][i];
    return b;
}

//=============17
int **concatenate2MatricesH(int **a, int **b, int length, int width){
    int **c = new int*[length];
    for (int i = 0; i < length; i++)
        c[i] = new int [width*2];

    for (int i = 0; i < length; i++){
        for (int j = 0; j < width*2; j++){
            if(j < width)
                c[i][j] = a[i][j];
            else
                c[i][j] = b[i][j-width];
        }
    }
    return c;
}

int **concatenate2MatricesV(int **a, int **b, int length, int width){
    int **c = nullptr;
    AlloMem2DArray(c, length*2, width);
    for (int i = 0; i < length*2; i++){
        for (int j = 0; j < width; j++){
            if (i < length)
                c[i][j] = a[i][j];
            else 
                c[i][j] = b[i-length][j];
        }
    }
    return c;
}

//============18
bool multiple2Matrices(int **a, int **b, int lengtha, int widtha, int lenghtb, int widthb){
    if (widtha != lenghtb)
        return false;
    //widtha == lengthb
    int **mul = new int *[lengtha];
    for (int i = 0; i < lengtha; i++)
        mul[i] = new int [widthb];

    for (int i = 0; i < lengtha; i++){
        for (int j = 0; j < widthb; j++){
            mul[i][j] = 0;
            for (int k = 0; k < widtha; k++)
                mul[i][j] += (a[i][k] * b[k][j]);
        }
    }
    print2DArray(mul, lengtha,widthb);

    for (int i = 0; i < lengtha; i++)
        delete[] mul[i];
    delete [] mul;

    return true;
}

//============19
int ** findSubMatrix(int **a, int length, int width, int &length_, int &width_){
    if (length_ > length || width_ > width)
        return NULL;
    else if (length_ == length && width_ == width)
        return a;
    
    int **ans = new int*[length_];
    for (int i = 0; i < length_; i++)
        ans[i] = new int [width_];
    
    int StartRowIndex, StartColumnIndex;
    int curTotal, LargestTotal = -999;
    for (int i = 0; i <= length - length_; i++){
        for (int j = 0; j <= width - width_; j++){
            curTotal = 0;
            for (int k = i; k < i + length_; k++){
                for (int l = j; l < j + width_; l++)
                    curTotal += a[k][l];
            }
            if (curTotal > LargestTotal){
                LargestTotal = curTotal;
                StartColumnIndex = j;
                StartRowIndex = i;
            }
        }
    }
    int row = 0, column = 0;
    for (int i = 0; i <= length - length_; i++){
        for (int j = 0; j <= width - width_; j++){
            if (i == StartRowIndex && j == StartColumnIndex){
                for (int k = i; k < i + length_; k++){
                    for (int l = j; l < j + width_; l++)
                        ans[row][column++] = a[k][l];
                    row++;
                    column = 0;
                }
                break;
            }
        }
    }
    return ans;
}

int main(){
    // int *a, n;
    // inputArray(a,n);
    // printArray(a,n);
    // delete [] a;

    /* int a1[] = {3,4,7,5,10,1,5,2,9,8};
    int n1 = sizeof(a1) / sizeof(a1[0]);

    int a2[] = {4,1,23,45,25,12,3};
    int n2 = sizeof(a2) / sizeof(a2[0]);

    int *Pa1 = a1;
    int *Pa2 = a2; */

    //cout << *findMax(a,n) << endl;
    //printArray(copyArray(a,n),n);

    /* int *EvenArray;
    int soSochan = *countEvens(a,n,EvenArray);
    cout << "The number of EVEN numbers: "<< soSochan << endl;
    EvenArray = genEvenSubarray(a,n,countEvens(a,n,EvenArray));
    for (int i = 0; i < *countEvens(a,n,EvenArray); i++)
        cout << *(EvenArray+i) << " ";
    cout << endl;
    delete [] EvenArray; */

    /* swapArrays(Pa1,Pa2,n1,n2);
    printArray(Pa1,n1);
    printArray(Pa2,n2); */

    /* int *concatenate = concatenate2Arrays(a1,a2,n1,n2);
    printArray(concatenate, n1+n2); */

    /* int mang1[] = {3,7,8,9,16,17};
    int solg1 = sizeof(mang1) / sizeof(mang1[0]);
    int mang2[] = {2,6,9,10,11,12};
    int solg2 = sizeof(mang2) / sizeof(mang2[0]);

    int solgmoi;
    int *Merge = merge2Arrays(mang1,mang2,solg1,solg2,solgmoi);
    printArray(Merge,solgmoi); */

    /* int **B = nullptr;
    int row, col;
    generateMatrix1(B,row,col);
    print2DArray(B,row,col);
    
    delete[] B; */

    /* int a[] = {3,4,5};
    int na = sizeof(a)/sizeof(a[0]);
    int b[] = {7,6,2,8};
    int nb = sizeof(b)/sizeof(b[0]);

    int **C = generateMatrix2(a,b,na,nb);
    print2DArray(C,na,nb);
    cout << "========\n";
    swapRows(C,na,nb);
    print2DArray(C,na,nb);
    cout << "========\n";
    swapColumns(C,na,nb);
    print2DArray(C,na,nb);
    delete[]C; */

    /* int a[][3] = {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };
    int b[3][2] = {
        {1,2},
        {3,4},
        {5,6},
    };
    int n,m;
    cin >> n >> m;
    int **pa = new int *[n];
    for (int i = 0; i < n; i++)
        pa[i] = new int[m];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> pa[i][j];
    
    int **c = transposeMatrix(pa,n,m);
    print2DArray(c,m,n);
    delete[]c; */

    /* int a[][4]= {
        {1,4,2},
        {3,7,9},
        {12,5,8}
    };
    int b[][4]= {
        {3,4,2},
        {21,7,9},
        {87,3,0}
    };
    int **pa = nullptr;
    
    int **pb = nullptr;

    AlloMem2DArray(pa,3,4);
    AlloMem2DArray(pb,3,4);
    //pa = &a[0];
    int **c = concatenate2MatricesH(pa,pb,3,3); */

    int a[] = {14,2,3,1,99,21};
	int n = sizeof(a)/sizeof(a[0]), total = 0, length = 0;
	//int *b = findLongestAscendingSubarray(a, n, length);

    //int arr[] = {-2,-3,4,-1,-2,1,5,-3};
    //int arr[] = {-3,2,7,6,-5,15};
    int arr[] = {-4,-5,-6};
    int narr = sizeof(arr)/sizeof(arr[0]);
    int *b = findLargestTotalSubarray(arr,narr,total,length);
	for (int i = 0; i < length; i++){
		cout << b[i] << " ";
	}
	cout << endl;


    return 0;
}