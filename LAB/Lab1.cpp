#include <iostream>
#include <cmath>
#include <cstring>
#include <locale>
#include <fstream>
using namespace std;

const int MAX = 100;

//==============Function==============
void LinearEquation(int a, int b){
    cout << "a = "; cin >> a; 
    cout << "b = "; cin >> b;
    cout << "Solving: " << a << "x + " << b << " = 0" << endl;
    cout << "<=> x = " << -float(b)/a << endl;
}

void QuadraticEquation(int a, int b, int c){
    cout << "a = "; cin >> a;
    cout << "b = "; cin >> b;
    cout << "c = "; cin >> c;
    cout << "Solving (" << a << ")x^2 + (" << b << ")x + (" << c << ") = 0" << endl; 
    bool all = false, root;
    int NumOfRoot = 0;
    float x, x1, x2;
    if (a == 0){
        if (b == 0){
            if (c == 0){
                all = true;
                root = true;
            }
            else 
                root = false;
        }
        else {
            root = true;
            NumOfRoot = 1;
            x = -float(c)/b;
        }
    }
    else {
        int delta = b*b - 4*a*c;
        if (delta > 0){
            root = true;
            NumOfRoot = 2;
            x1 = (-float(b) + sqrt(float(delta)))/ (2*a);
            x2 = (-float(b) - sqrt(float(delta)))/ (2*a);
        }
        else if (delta == 0){
            root = true;
            x = -float(b)/(2*a);
        }
        else root = false;
    }

    if (root){
        if (all){
            cout << "The Equation is true with every real number x!" << endl;
            return;
        }
        else if (NumOfRoot == 1)
            cout << "This Equation has 1 root x = " << x << endl;
        else if (NumOfRoot == 2)
            cout << "This Equation has 2 roots x1 = " << x1 << ", x2 = " << x2 << endl;
        else cout << "This Equation has a double root x1 = x2 = " << x << endl;
    }
    else cout << "This Equation has no root!" << endl;
    return;
}

bool isPrime(int a){
    if (a < 2) return false;
    else {
        int count = 0;
        for (int i = 2; i <= sqrt(a); i++)
            if (a % i == 0) count++;
        return count == 0;
    }
    return false;
}

int countPrime(int a, int b){
    if (a > b){
        int temp = a;
        a = b;
        b = temp;
    }
    int count = 0;
    for (int i = a; i <= b; i++)
        if (isPrime(i)) count++;
    return count;
}

int sumDigits(int n){
    cin >> n;
    int sum = 0;
    while (n > 0){
        sum += (n % 10);
        n /= 10;
    }
    cout << sum << endl;
    return 0;
}

int countInteger(int N, int k){
    cin >> N >> k;
    int count = 0;
    for (int i = 0; i < N; i++)
        if (i % k == 0) count++;
    cout << count << endl;
    return 0;
}

void Triangle(float a, float b, float c){
    cin >> a >> b >> c;
    if (a + b > c && a + c > b && b + c > a){
        if (a*a + b*b == c*c || a*a + c*c == b*b || b*b + c*c == a*a){
            if (a == b || b == c || c == a)
                cout << "Right isosceles triangle" << endl;
            else cout << "Right triangle" << endl;
        }
        else if (a == b || b == c || c == a){
            if (a == b && b == c)
                cout << "Equilateral triangle" << endl;
            else cout << "Isosceles triangle" << endl;
        }
        else cout << "Normal triangle" << endl;
    }
    else cout << "Unable to form a triangle" << endl;
}

//==================2. Array & String====================
//=========1D Array=========
void inputArray(float A[], int n){
    for (int i = 0; i < n; i++)
        cin >> A[i];
}

void printArray(float A[], int n){
    for (int i = 0; i < n; i++) cout << A[i] << " ";
    cout << endl;
}

int countArrayPrime(float A[], int n){
    int count = 0;
    for (int i = 0; i < n; i++)
        if (isPrime(A[i])) count++;
    return count;
}

float sumArray(float A[], int n){
    float sum = 0;
    for (int i = 0; i < n; i++)
        sum += A[i];
    return sum;
}

bool isIncreasing(float A[], int n){
    if (n < 2) return true;
    for (int i = 0; i < n-1; i++) 
        if (A[i] > A[i+1]) return false;
    return true;
}
bool isDecreasing(float A[], int n){
    if (n < 2) return true;
    for (int i = 0; i < n-1; i++)
        if (A[i] < A[i+1]) return false;
    return true;
}

//=========2D Array=========
void input2DArray(float A[][MAX], int m, int n){
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++){
            cout << "A[" << i << "," << j << "] = ";
            cin >> A[i][j];
        }
}

void print2DArray(float A[][MAX], int m, int n){
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++)
            cout << A[i][j] << " ";
        cout << endl;
    }
}

void rotate2DArray(float A[][MAX], int m, int n){
    for (int j = 0; j < n; j++){
        for (int i = m-1; i >= 0; i--)
            cout << A[i][j] << " ";
        cout << endl;
    }
}

void sum2DArray(float A[][MAX], float B[][MAX], float result[][MAX], int m, int n){
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            result[i][j] = A[i][j] + B[i][j];
    cout << "\n========Sum of 2D Arrays========" << endl;
    print2DArray(result,m,n);
}

void multiple2DArray(float A[][MAX], float B[MAX][MAX], float result[][MAX], int m, int n, int p){
    //                  A[m][n]  x   B[n][p]
    for (int i = 0; i < m; i++){
        for (int j = 0; j < p; j++){
            result[i][j] = 0;
            for (int k = 0; k < n; k++)
                result[i][j] += A[i][k] * B[k][j];
        }
    }
    print2DArray(result,m,p);
}

bool isDiagonalMatrix(float A[][MAX], int m, int n){
    // check UpperTriangularMatrix
    for (int i = 1; i < m; i++){
        for (int j = 0; j < i && j < n; j++)
            if (A[i][j] != 0) return false;
    }
    // check LowerTriangularMatrix
     for (int j = 1; j < n; j++){
        for (int i = 0; i < j && i < m; i++)
            if (A[i][j] != 0) return false;
    }
    return true;
}
bool isUpperTriangularMatrix(float A[][MAX], int m, int n){
    for (int i = 1; i < m; i++){
        for (int j = 0; j < i && j < n; j++)
            if (A[i][j] != 0) return false;
    }
    return true;
}
bool isLowerTriangularMatrix(float A[][MAX], int m, int n){
    for (int j = 1; j < n; j++){
        for (int i = 0; i < j && i < m; i++)
            if (A[i][j] != 0) return false;
    }
    return true;
}

//===========String===========
void inputString(char c[MAX]){
    cin.getline(c,MAX);
}
void printString(char c[MAX]){
    cout << c << endl;
}

bool isPalindrome(char c[MAX]){
    int n = strlen(c);
    for (int i = 0, j = n-1; i < j; i++, j--)
        if (c[i] != c[j]) return false;
    return true;
}

int countCapital(char c[MAX]){
    int n = strlen(c);
    int countCapital = 0;
    for (int i = 0; i < n; i++)
        if (c[i] >= 'A' && c[i] <= 'Z')
            countCapital++;
    return countCapital;
}

int countAppearance(char c[MAX], char k){
    int n = strlen(c);
    int count = 0;
    for (int i = 0; i < n; i++)
        if (c[i] == k) count++;
    return count;
}

int countWord(char c[MAX]){
    int n = strlen(c);
    int countSpace = 0;
    for (int i = 0; i < n; i++)
        if (c[i] == ' ') countSpace++;
    return countSpace+1;
}

//===============3. Structure===============
//====1
struct time{
    int hour, min, sec;
};
void inputTime(struct time &t){
    cout << "Hour: "; cin >> t.hour;
    cout << "Minute: "; cin >> t.min;
    cout << "Second: "; cin >> t.sec;
    char response;
    cout << "Verify the time: " << t.hour << ":" << t.min << ":" << t.sec << ". (Y/y)/Other keys ";
    cin >> response;
    while (tolower(response) != 'y'){
        cout << "Hour: "; cin >> t.hour;
        cout << "Minute: "; cin >> t.min;
        cout << "Second: "; cin >> t.sec;
        cout << "Verify the time: " << t.hour << ":" << t.min << ":" << t.sec << ". (Y/y)/Other keys ";
        cin >> response;
    }
}
int ConvertToTotalSecs(struct time t){
    return t.hour*3600 + t.min*60 + t.sec;
}
struct time ConvertSecsToTime(int second){
    struct time t;
    if (second >= 0){
        t.hour = second / 3600;
        t.min = (second % 3600)/60;
        t.sec = second % 60;
    }
    return t;
}
void TimePassOfDayCalculation(struct time t){
    //convert time to seconds
    int totalsec = ConvertToTotalSecs(t);
    //convert seconds to min & sec
    cout << "Time of the day has passed: " << totalsec / 60 << " minute(s) & " << totalsec % 60 << " second(s)" << endl;
}
void WhichTimeisEarlier(struct time a, struct time b){
    int totalsec1 = ConvertToTotalSecs(a);
    int totalsec2 = ConvertToTotalSecs(b);
    if (totalsec1 > totalsec2) 
        cout << a.hour << ":" << a.min << ":" << a.sec << " is earlier" << endl;
    else if (totalsec1 < totalsec2) 
        cout << b.hour << ":" << b.min << ":" << b.sec << " is earlier" << endl;
    else 
        cout << a.hour << ":" << a.min << ":" << a.sec << " is as early as " << b.hour << ":" << b.min << ":" << b.sec<< endl;
}
void CalculateTheNextPointOfTimeWithAddingXMins(struct time t, int x){
    int total = ConvertToTotalSecs(t) + x*60;
    struct time tgian = ConvertSecsToTime(total);
    cout << tgian.hour << ":" << tgian.min << ":" << tgian.sec << endl;
}

//====2
struct fraction{
    int numerator, denominator;
};
void inputFraction(fraction &a){
    cout << "All inputs must be integers" << endl;
    cout << "Enter Numerator: "; cin >> a.numerator;
    cout << "Enter Denominator: "; cin >> a.denominator;
    char response;
    cout << "Is " << a.numerator << "/" << a.denominator << " the fraction you chose? (Y/y)/(N/n) ";
    cin >> response;
    while(tolower(response) != 'y'){
        cout << "Enter Numerator: "; cin >> a.numerator;
        cout << "Enter Denominator: "; cin >> a.denominator;
        cout << "Is " << a.numerator << "/" << a.denominator << " the fraction you chose? (Y/y)/(N/n) ";
        cin >> response;
    }
}
fraction SimplifyFraction(fraction &a){
    int b = a.numerator, c = a.denominator;
    while (b % c != 0){
        int d = b % c;
        b = c;
        c = d;
    }
    int gcd = c;
    a.numerator /= gcd;
    a.denominator /= gcd;
    return a;
}
fraction SumOf2Fractions(fraction a, fraction b) {
    fraction result;
    result.numerator = a.numerator*b.denominator + a.denominator*b.numerator;
    result.denominator = a.denominator*b.denominator;
    SimplifyFraction(result);
    return result;
}
void Compare2Fractions(fraction a, fraction b) {
    float ValueOfa = float(a.numerator)/a.denominator;
    float ValueOfb = float(b.numerator)/b.denominator;
    if (ValueOfa < ValueOfb)
        cout << a.numerator << "/" << a.denominator << " < " << b.numerator << "/" << b.denominator << endl;
    else if (ValueOfa > ValueOfb)
        cout << a.numerator << "/" << a.denominator << " > " << b.numerator << "/" << b.denominator << endl;
    else cout << a.numerator << "/" << a.denominator << " = " << b.numerator << "/" << b.denominator << endl; 
}

//====3
struct point{
    float x,y;
};
string WhichQuadrant(point a){
    string quadrant;
    if (a.x * a.y > 0){
        if (a.x > 0)
            quadrant = "up-right";
        else quadrant = "down-left";
    }
    else if (a.x * a.y < 0){
        if (a.x > 0)
            quadrant = "down-right";
        else quadrant = "up-left";
    }
    else {
        if (a.x == 0 && a.y == 0)
            quadrant = "Origin";
        else{
            if (a.x == 0){
                if (a.y > 0) quadrant = "positive side of y-axis";
                else quadrant = "negative side of y-axis";
            }
            else {
                if (a.x > 0) quadrant = "positive side of the x-axis";
                else quadrant = "negative side of the x-axis";
            }
        }
    }
    return quadrant;
}
float CalculateDistance(point a, point b) {
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}
point Midpoint_of2DifferentPoints(point a, point b){
    point mid;
    mid.x = (a.x + b.x)/2;
    mid.y = (a.y + b.y)/2;
    return mid;
}
bool check3CollinearPoints(point a, point b, point c){
    return ((c.y - b.y) * (b.x - a.x) == (b.y - a.y) * (c.x - b.x));
}

//===============4. File=================
//======1
int InputFileFunction(char a[]){
    ofstream out("input1.txt");
    if (out.is_open()){
        int n; cin >> n;
        out << n << endl;
        string equation;
        for (int i = 1; i <= n; i++){
            cout << "Enter equation " << i  << ": ";
            cin >> equation;
            out << equation << endl;
        }
    }
    else {
        cout << "Unable to open file!" << endl;
        return 0;
    }
    return 0;
}
void ResultOfEquation(char a[]){
    ifstream in("input1.txt");
    ofstream out("output1.txt");
    if(!out.is_open()){
        cout << "Unable to open file output1.txt!" << endl;
        return;
    }
    if (!in.is_open()){
        cout << "Unable to open file input1.txt!" << endl;
        return;
    }
    int n;
    in >> n;
    while (!in.eof()){
        float num1, num2;
        char sign;
        in >> num1;
        in >> sign;
        in >> num2;
        switch(sign){
            case '+':
                out << num1 << " + " << num2 << " = " << num1+num2 << endl;
                break;
            case '-':
                out << num1 << " - " << num2 << " = " << num1-num2 << endl;
                break;
            case '*':
                out << num1 << " x " << num2 << " = " << num1*num2 << endl;
                break;
            case '/':
                out << num1 << " / " << num2 << " = " << num1/num2 << endl;
                break;
        }
    }
    in.close();

}

//======2
int countAppearancesOfAWord(char a[]){
    string key;
    cout << "Enter a word: "; cin >> key;
    ifstream in("Players.txt");
    if (!in.is_open()){
        cout << "Unable to open input2.txt" << endl;
        return 0;
    }
    int count = 0;
    while (!in.eof()){
        string word;
        in >> word;
        if (word == key)
            count ++;
    }
    in.close();
    cout << "Number of words: " << count << endl;
    return 0;
}


int main(){
    
    //QuadraticEquation(a,b,c);
    //sumDigits(n);
    //Triangle(a,b,c);
    /* float a[MAX][MAX];
    int m,n;
    cin >> m >> n;
    input2DArray(a,m,n);
    print2DArray(a,m,n);
    rotate2DArray(a,m,n); */

    /* cout << isUpperTriangularMatrix(a,m,n) << endl;
    cout << isLowerTriangularMatrix(a,m,n) << endl;
    cout << isDiagonalMatrix(a,m,n) << endl;  */
    /* har a[MAX];
    inputString(a);
    printString(a);
    //cout << isPalindrome(a) << endl;
    cout << countCapital(a) << endl; */

    /* fraction a,b;
    fraction sum;
    inputFraction(a);
    inputFraction(b);
    /* sum = SumOf2Fractions(a,b);
    cout << sum.numerator << "/" << sum.denominator << endl;
    Compare2Fractions(a,b); */

    /* struct time t1, t2;
    inputTime(t1);
    TimePassOfDayCalculation(t1);
    inputTime(t2);
    WhichTimeisEarlier(t1,t2);
    CalculateTheNextPointOfTimeWithAddingXMins(t1,12*60); */

    char inputfilename[MAX];
    //InputFileFunction(inputfilename);
    ResultOfEquation(inputfilename);
    //countAppearancesOfAWord(inputfilename);

    return 0;
}