#include <iostream>
#include <cstring>
using namespace std;

//====1
//S = 1 + 2 + 3 +...+n
int sum(int n){
    if (n == 1)
        return 1;
    return sum(n-1) + n;
}

//=====2
//n! = 1.2.3.4....n
int factorial(int n){
    if (n == 1) return 1;
   return factorial(n-1)*n;
}

//=====3
//x^n
int powerof(int x, int n){
    if (n == 0)
        return 1;
    return powerof(x,n-1) * x;
}

//======4
int countDigit(int n){
    if (n < 10)
        return n!=0;
    return 1 + countDigit(n/10);
}

//======5
int countOddDigit(int n){
    if (n < 10)
        return n % 2 != 0; 
    int count = ((n%10) % 2 != 0) ? 1 : 0; 
    return count + countOddDigit(n/10);
}

//======6
bool isEveryDigitEven(int n){
    if (n < 10)
        return n % 2 == 0;
    return ((n % 10) % 2 == 0) && isEveryDigitEven(n/10);
}

//======7
int CountCommonDivisor(int a, int b){
    static int i = 1;
    if (i > a || i > b) return 0;
    if (a % i == 0 && b % i == 0){
        i += 1;
        return CountCommonDivisor(a,b) + 1;
    }
    i += 1;
    return CountCommonDivisor(a,b);
}

//======8
int GCD(int a, int b){
    if (a % b == 0)
        return b;
    return GCD(b,a % b);
}
int LCM(int a, int b){
    static int multiple = min(a,b);
    if (multiple % a == 0 && multiple % b == 0)
        return multiple;
    multiple += min(a,b);
    return LCM(a,b);
}

//======9
int reverseInt(int n){
    static int result = 0;
    static int pos = 1;     //10^0
    /* while (n > 0){
        result = result*10 + n%10;
        n /= 10;
    }
    return result; */
    if (n > 0){
        reverseInt(n/10);
        result +=  (n % 10)*pos;
        pos *= 10;
    }
    return result;
}

//=======10
int BinaryOf(int n){
    if (n == 1)
        return 1;
    return BinaryOf(n / 2) * 10 + n % 2;
}
void Dec_Bin(int n, string &str){
    if (n <= 1){
        str += to_string(n);
        return;
    }
    Dec_Bin(n/2, str);
    if (n % 2 == 0){
        str += '0';
    }
    else 
        str += '1';       
}

//=======11
//i_th FIBONACCInum
int fibo(int n){
    if (n <= 1)
        return n!=0;
    return fibo(n-1) + fibo(n-2);
}

//======12
void StrPermutation(char a[], int left, int right){
    if (left == right){
        cout << a << " ";
        return;
    }
    for (int i = left; i <= right; i++){
        swap(a[i],a[left]);

        StrPermutation(a, left + 1, right);

        swap(a[i], a[left]);
    }
}
/*int count1(int n, int m, int max)
{
    if (n==0) return 1;
    if (n<m) return 0;
    int sum=0;
    for (int i=m;i<=max;i++)
        sum+=count1(n-i,m,i);
    return sum;
}

int main()
{
    cout<<count1(6,1,4);
    
    return 0;
}*/

int main(){
    int x,y;
    //cin>>x >> y;
    //string str;

    //cout << sum(x) << endl;
    //cout << factorial(x) << endl;
    //cout << powerof(x,1) << endl;
    //cout << countDigit(x) << endl;
    //cout << countOddDigit(x) << endl;
    //cout << isEveryDigitEven(x) << endl;
    //cout << CountCommonDivisor(x,y)<<endl;
    //cout << GCD(x,y)<<endl;
    //cout << LCM(x,y) << endl;
    //cout << reverseInt(x) << endl;
    /* cout << BinaryOf(y) << endl;
    Dec_Bin(x,str);
    cout << str << endl; */
    //cout << fibo(x) << endl;

    char Str[5];
    cout << "String: "; cin >> Str;
    StrPermutation(Str, 0, strlen(Str)-1);
    
    cout << endl;

    return 0;
}