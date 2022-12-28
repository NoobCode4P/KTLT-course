#include <iostream>
#include <cmath>
using namespace std;

//===========1/9===============
struct Car{
    string carMake;
    string carModel;
    int yearModel;
    double cost;
};
void ex1(){
    Car a = {"Ford","Mustang",1968,20000};
    Car array[5];
    array[0] = {"Ford","Taurus",1997,21000};
    array[1] = {"Honda","Accord",1992,11000};
    array[2] = {"Lamborghini","Countach",1997,200000};
}

//==========2/9================
struct TempScale{
    double fahrenheit;
    double celcius;
};

struct Reading{
    int windSpeed;
    double humidity;
    TempScale temperature;
};

void showReading(Reading a){
    cout << a.windSpeed << endl;
    cout << a.humidity << endl;
    cout << a.temperature.fahrenheit << endl;
    cout << a.temperature.celcius << endl;
}

void referReading(Reading &a){
    cout << "Windspeed: "; cin >> a.windSpeed;
    cout << "Humidity: "; cin >> a.humidity;
    cout << "Temperature(F degree): "; cin >> a.temperature.fahrenheit;
    cout << "Temperature(C degree): "; cin >> a.temperature.celcius;
}

Reading getReading(){
    Reading a;
    referReading(a);
    return a;
}

void recordReading(Reading *p){
    cout << "Windspeed: "; cin >> p->windSpeed;
    cout << "Humidity: "; cin >> p->humidity;
    cout << "Temperature(F degree): "; cin >> p->temperature.fahrenheit;
    cout << "Temperature(C degree): "; cin >> p->temperature.celcius;
}

void ex2(){
    Reading a;
    a.windSpeed = 37;
    a.humidity = 32/100;
    a.temperature.fahrenheit = 32;
    a.temperature.celcius = 0;
}

//=============3/9================
struct ComplexNum{
    int real,imag;
};
void inputComplexNum(ComplexNum &a){
    cout << "Real part: "; cin >> a.real;
    cout << "Imaginary part: "; cin >> a.imag;
}
ComplexNum Sum(ComplexNum a, ComplexNum b){
    return {a.real + b.real, a.imag + b.imag};
}

ComplexNum Multiplication(ComplexNum a, ComplexNum b){
    return {a.real * b.real - a.imag * b.imag, a.real * b.imag + a.imag * b.real};
}

//============4/10================
typedef struct fraction{
    int num,den;
} frac;
void input2Frac(frac &a, frac&b){
    cout << "Numerator of the 1st fraction: "; cin >> a.num;
    cout << "Denominator of the 1st fraction: "; cin >> a.den;
    cout << "=======\n";
    cout << "Numerator of the 2nd fraction: "; cin >> b.num; 
    cout << "Denominator of the 2nd fraction: "; cin >> b.den;
}

frac Subtraction2Frac(frac a,frac b){
    frac result = {
        a.num * b.den - a.den * b.num,
        a.den * b.den
    };
    int x = result.num;
    int y = result.den;
    while (x % y != 0){
        int sodu = x % y;
        x = y;
        y = sodu;
    }
    int gcd = y;
    result.num /= gcd;
    result.den /= gcd;

    return result;
}

frac Addition2Frac(frac a, frac b) {
    frac result = {
        a.num * b.den + a.den * b.num,
        a.den * b.den
    };
    int x = result.num;
    int y = result.den;
    while (x % y != 0){
        int sodu = x % y;
        x = y;
        y = sodu;
    }
    int gcd = y;
    result.num /= gcd;
    result.den /= gcd;

    return result;
}

frac Multiplication2Frac(frac a, frac b){
    frac result = {
        a.num * b.num,
        a.den * b.den
    };
    int x = result.num;
    int y = result.den;
    while (x % y != 0){
        int sodu = x % y;
        x = y;
        y = sodu;
    }
    int gcd = y;
    result.num /= gcd;
    result.den /= gcd;

    return result;
}

frac Division2Frac(frac a, frac b){
    swap(b.den,b.num);
    frac result = {
        a.num * b.num,
        a.den * b.den
    };
    int x = result.num;
    int y = result.den;
    while (x % y != 0){
        int sodu = x % y;
        x = y;
        y = sodu;
    }
    int gcd = y;
    result.num /= gcd;
    result.den /= gcd;

    return result;
}

//===========5/10================
struct Employee{
    string name;
    int salary;
    int hour;
};
void ex5(){
    Employee list[10];
    for (int i = 0; i < 10; i++){
        if (list[i].hour == 8)
            list[i].salary += 50;
        else if(list[i].hour == 10)
            list[i].salary += 100;
        else if (list[i].hour >= 12)
            list[i].salary += 150;
    }
    for (int i = 0; i < 10; i++)
        cout << list[i].name << "\t" << list[i].salary << endl;
}

//===========6/10===============
struct point {
    float x, y;
    float distanceFrom(point);
};
float point :: distanceFrom(point b){
    return sqrt(pow(b.x - x,2) + pow(b.y - y,2));
}
void inputPoint(point &a){
    cout << "Input x = "; cin >> a.x;
    cout << "Input y = "; cin >> a.y;
}
struct Triangle{
    point A,B,C;
};
float Perimeter(Triangle t){
    float AB = t.B.distanceFrom(t.A);
    float AC = t.C.distanceFrom(t.A);
    float BC = t.B.distanceFrom(t.C);
    return AB + AC + BC;
}
float Area(Triangle t){
    float p = Perimeter(t) / 2;
    float AB = t.B.distanceFrom(t.A);
    float AC = t.C.distanceFrom(t.A);
    float BC = t.B.distanceFrom(t.C);
    return sqrt(p * (p - AB) * (p - AC) * (p - BC));
}
void ex6(){
    Triangle t;
    inputPoint(t.A);
    inputPoint(t.B);
    inputPoint(t.C);
    cout << "The perimeter is " << Perimeter(t) << ". The area is " << Area(t) << ".\n";
}

//==============7/10============
struct date{
    int day, month, year;
};
void inputDate(date &a){
    cout << "Day: "; cin >> a.day;
    cout << "Month: "; cin >> a.month;
    cout << "Year: "; cin >> a.year;
}

date AddDaysToTheDate(date a, int x){
    
}

int main(){
    /* Reading b;
    Reading *a = &b;
    recordReading(a);
    showReading(b); */
    /* ComplexNum a,b;
    inputComplexNum(a);
    inputComplexNum(b);
    ComplexNum sum = Sum(a,b);
    cout << sum.real << " + " << sum.imag << "i" << endl;
    ComplexNum mul = Multiplication(a,b);
    cout << mul.real << " + " << mul.imag << "i" << endl; */

    /* frac x,y;
    input2Frac(x,y);
    frac result = Division2Frac(x,y);

    cout << x.num << "/" << x.den << " - " << y.num << "/" << y.den  
        << " = " << result.num << "/" << result.den << endl; */

    ex6();

    return 0;
}