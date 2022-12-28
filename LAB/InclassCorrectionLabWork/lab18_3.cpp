#include <iostream>
#include <ctime>
using namespace std;
int* countEvens(int* a, int n, int* &evens){
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] % 2 == 0)
			cnt++;
	}
	evens = &cnt;
	return evens;
}
int* genEvenSubarray(int* a, int n, int*& cnt) {
	int t = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] % 2 == 0)
			t++;
	}
	cnt = &t;
	int *evens = new int[t];
	int j = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] % 2 == 0) {
			evens[j] = a[i];
			j++;
		}
	}
	
	return evens;
}
int* findLargestTotalSubarray(int* a, int n, int &total, int &length)
{
	int *ans = new int[n];
	int *len = new int[n];
	int *sum = new int[n];
	int id = 0;
	total = 0; length = 0;
	for (int i = 0; i < n; i++){
		*(sum + i) = *(a + i);
		*(len + i) = 1;
		if (i > 0 && *(sum + (i - 1)) + *(a + i)>*(sum + i)){
			*(sum + i) = *(sum + (i - 1)) + *(a + i);
			*(len + i) = *(len + (i - 1)) + 1;
		}
		if (*(sum + i) > total){
			total = *(sum + i);
			length = *(len + i);
			id = i;
		}
	}

	int cnt = 0;
	for (int i = id - length + 1; i <= id; i++){
		cout << *(a + i) << ' ';
		*(ans + (cnt++)) = *(a + i);
	}
	return ans;
}

int* findLongestAscendingSubarray(int* a, int n, int &length){
	int cur_length = 0, index = 0;
	for (int i = 0; i < n - 1; i++){
		cur_length = 1;
		for (int j = i + 1; j < n; j++){
			if (a[j - 1] <= a[j]){
				cur_length++;
			}
			else{
				break;
			}
		}
		if (cur_length > length){
			length = cur_length;
			index = i;
		}
	}
	int *b = new int[length];
	for (int i = 0; i < length; i++){
		b[i] = a[index + i];
	}
	return b;
}

void inputArray(int *&a, int &n) {
	cin >> n;
	a = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
}

void swapArray(int *&a, int *&b, int &n, int &m) {
	int * p = a;
	a = b;
	b = p;
	swap(n, m);
}

void outputArray(int * a, int n) {
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
}

int* merge2Arrays(int* a, int* b, int na, int nb, int&nc)
{
	int * s = new int[na + nb];
	int i = 0, j = 0, k = 0;

	while (i < na && j < nb)
	{
		if (a[i] < b[j])
		{
			s[k] = a[i];
			i++;
		}
		else
		{
			s[k] = b[j];
			j++;
		}
		k++;
	}

	while (i < na)
	{
		s[k] = a[i];
		i++;
		k++;
	}

	while (j < nb)
	{
		s[k] = b[j];
		j++;
		k++;
	}
	nc = na + nb;
	return s;
}

int main() {
	//srand(time(0));
	//int n;
	//cin >> n;
	//int *a = new int[n];
	//for (int i = 0; i < n; i++) {
	//	a[i] = rand() % 10;
	//}
	//for (int i = 0; i < n; i++)
	//	cout << a[i] << " ";
	//cout << '\n';
	///*int *cnt;
	//cnt = countEvens(a, n, cnt);
	//cout << "Number of evens = " << *cnt << '\n';*/

	//int *cnt1;
	//int *evens = genEvenSubarray(a, n, cnt1);
	//int k = *cnt1;
	//for (int i = 0; i < k; i++) {
	//	cout << evens[i] << " ";
	//}
	//cout << endl;
	int a[] = {4,3,2,1,-1};
	int n = sizeof(a)/sizeof(a[0]), total = 0, length = 0;
	int *b = findLongestAscendingSubarray(a, n, length);
	for (int i = 0; i < length; i++){
		cout << b[i] << " ";
	}
	cout << endl;
	/* int *b = findLargestTotalSubarray(a, n, total,length);
	for (int i = 0; i < length; i++){
		cout << b[i] << " ";
	}
	cout << endl;
	cout << total << endl; */
	/*int n, m;
	int *a, *b;
	cout << "Nhap mang A: ";
	inputArray(a, n);
	cout << "Nhap mang B: ";
	inputArray(b, m);
	swapArray(a, b, n, m);
	cout << "Mang A: "; outputArray(a, n);
	cout << endl;
	cout << "Mang B: "; outputArray(b, m);*/

	/* int * a, *b, m, n, nc;
	inputArray(a, n);
	inputArray(b, m);
	int * g = merge2Arrays(a, b, n, m, nc);
	outputArray(g, nc);
	system("pause"); */
	return 0;
}