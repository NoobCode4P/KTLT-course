#include <iostream>
#include <cstring>
using namespace std;
//========1/9=========
char * CopyString(char s[]){
    int n = strlen(s);
    char *dup = new char[n+1];
    for (int i = 0; s[i]; i++){
        dup[i] = *(s+i);
        //dup++;
    }
    *(dup+n) = '\0';
    return dup;
}

//========2/9=========
int ex2(){
    int n;
    cout << "Enter a number: "; cin >> n;
    int *p = &n;
    cout << "You entered: " << *p << endl;
    return 0;
}

//========3/9=========
int ex3(){
    int iA, iB;
    cin >> iA >> iB;
    int *ptrA = &iA, *ptrB = &iB;
    cout << *ptrA << " " << *ptrB << endl;
    return 0;
}

//========4/9=========
int ex4(){
    char str[] = {"A string"};
    char * ptr = str;
    cout << "The letter at index 0: " << *ptr << ", The pointer position: " << &ptr << ", The letter t: " << *(ptr+3) << endl;
    ptr += 2;
    cout << "After updated by 2\n";
    cout << "The whole content: " << ptr << ", The letters r and g: " << *(ptr+2) << ", " << *(ptr+5) << endl;
    return 0;
}

//========5/9=========
int ex5(){
    char s[] = "abcde";
    char *cptr;
    cptr = s;
    for (int i = strlen(s)-1; i >= 0; i--)
        cout << *(cptr+i);
    cout << endl;
    return 0;
}

//========6/9=========
int countEven(int *a, int n){
    int count = 0;
    for (int i = 0; i < n; i++)
        if (*(a+i) % 2 == 0)
            count++;
    return count;
}

//========7/9========
double * maximum(double *a, int size){
    if (size == 0)
        return nullptr;
    double max = *(a+0);
    for (int i = 1; i < size; i++)
        if(max < *(a+i))
            max = *(a+i);
    double *p = &max;
    return p;
}

//========8/9========
int myStrlen(char *a){
    int count = 0; 
    while (*(a+count) != '\0')
        count++;
    return count;
}

//========9/9========
bool myStrContains(char *a, char key){
    int i = 0;
    while(*(a+i) != '\0'){
        if (*(a+i) == key)
            return true;
        i++;
    }
    return false;
}

//========10/9=======
void revString(char *ptr){
    int n = strlen(ptr);
    for (int i = 0; i < n/2; i++)
        swap(*(ptr+i),*(ptr+(n-1 - i)));
}

int main(){
    /* char str[] = {"hello world"};
    for (int i = 0; i<strlen(str); i++)
        cout << *(CopyString(str)+i);
    cout << endl; */

    ex2();
    int a[] = {2,3,1,4,2,5,6,12,14,8,9};
    int n = sizeof(a)/sizeof(a[0]);

    double b[] = {1.2,19,34.5,3,12.2,3.4};
    int nb = sizeof(b)/sizeof(b[0]);
    //cout << *maximum(b,nb) <<endl;
    char chr[] = {"Hello!"};
    //cout << myStrContains(chr,'z') << endl;
    //cout << myStrlen(chr) << endl;

    char s[10] = {"abcde"};
    // cout << "Before: "<< s << endl;
    // revString(s);
    // cout << "After: " << s << endl;


    return 0;
}