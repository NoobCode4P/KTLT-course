#include <iostream>
#include <Windows.h>
using namespace std;
int factorial(int n){
	if (n == 1){
		return 1;
	}
	else return n*factorial(n - 1);
}

int power(int x, int n){
	if (n == 0) return 1;
	return power(x, n - 1)*x;
}

int cnt;
void evenDigit(int n) {
	if (n == 0) return;
	int x = n % 10;
	if (x % 2 == 0) {
		cnt++;
	}
	evenDigit(n / 10);
}

bool verifyEven(int n){
	if (n / 10 == 0)
		if (n % 2 == 0)
			return true;
		else 
			return false;
	if (n % 10 % 2 == 0)
		return verifyEven(n / 10);
	else
		return false;
}

int CountCommonDivisor(int a, int b, int i){
	if (i == a + 1) return 0;
	if (a % i == 0 && b % i == 0) return CountCommonDivisor(a, b, i + 1) + 1;
	else return CountCommonDivisor(a, b, i + 1);
}

int gcd(int a, int b) {
	if (b == 0) return a;
	return (b, a % b);
}
int lcm(int a, int b) {
	static int multiple = 0;
	multiple += min(a, b);
	if ((multiple % a == 0) && (multiple % b == 0))
		return multiple;
	else return lcm(a, b);
}

int reverse(int n, int x)
{
	if (n == 0) return x;
	return reverse(n / 10, x * 10 + (n % 10));
}

int binaryNumber(int n){
	if (n == 1){
		return 1;
	}
	return binaryNumber(n / 2) * 10 + (n % 2);
}

int fibo(int n){
	if (n <= 1)
		return n;
	return fibo(n - 1) + fibo(n - 2);
}

void permutation(char a[], int id, int n, char ans[], bool check[])
{
	if (id == n){
		cout << ans << '\n';
		return;
	}
	for (int i = 0; i < n; i++)
		if (!check[i]){
			check[i] = 1;
			ans[id] = a[i];
			permutation(a, id + 1, n, ans, check);
			check[i] = 0;
		}
}

int main(){
	//,x;
	//cin >> x>>n;
	//cout<<factorial(n);
	//cout<< power(x, n);
	//cout << CountCommonDivisor(n, x, 1);
	//evenDigit(n);
	//cout << cnt;
	/*if (verifyEven(n))
		cout << "true";
	else
		cout << "false";*/
	//cout << "GCD = " << gcd(n, x) << ", LCM = " << lcm(n, x) << endl;
	
	//cout << reverse(n, 0) <<endl;
	//cout << binaryNumber(n);
	//cout << fibo(n);

	char a[] = "ABCD";
	char ans[] = "ABCD";
	bool check[] = { 0, 0, 0, 0 };
	int n = 4;
	
	permutation(a, 0, n, ans, check);

	system("pause");
	return 0;
}