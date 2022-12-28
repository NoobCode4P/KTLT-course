#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

struct Player {
	string pos;
	string name;
	string year;
	string team;
	string club;
};

int ReadFile(Player player[]) {
	ifstream fin("Players.txt", ios::in);
	int i = 0;
	while(!fin.eof()){
		getline(fin, player[i].pos, '/');
		getline(fin, player[i].name, '/');
		getline(fin, player[i].year, '/');
		getline(fin, player[i].team, '/');
		getline(fin, player[i].club, '\n');
		++i;
	}
	fin.close();
	return i;
}
void findAllPlayersBorn1994(Player player[]) {
	//ofstream fout("PlayersBornIn1994.txt", ios::out);
	int n = ReadFile(player);

	// for (int i = 0; i < n; i++)
	// 	cout << player[i].name << endl;

	for (int i = 0; i < n; i++) {
		if (player[i].year == "1994") {
			cout << player[i].name << '\n';
		}
	}
	//fout.close();
}
string findLastName(string name)
{
	string ans = "";
	stringstream ss;
	ss << name;
	while (ss >> ans);
	return ans;
}
void Swap(Player &x, Player &y)
{
	Player tmp = x;
	x = y;
	y = tmp;
}
void sortThePlayers(Player player[])
{
	int n = ReadFile(player);
	for (int i = 0; i < n; i++){
		int id = i;
		for (int j = i+1; j < n; j++){
			if (player[j].year > player[id].year){
				id = j;
				continue;
			}
			if (player[j].year < player[id].year) continue;

			string tmpLastName = (player[j].name);
			if (tmpLastName<findLastName(player[id].name)) id = j;
		}
		Swap(player[i], player[id]);
	}
	for (int i = 0; i < n; i++) {
		cout << player[i].name << ' ' << player[i].year << '\n';
	}
}
int main() {
	Player player[81];
	findAllPlayersBorn1994(player);
	//sortThePlayers(player);
	return 0;
}
/*
void swap(int * &a, int * &b)
{
	int *t;
	t = a;
	a = b;
	b = t;
}

int *sum(int *a, int *b)
{
	int k;
	k = *a + *b;
	return &k;
}

void inputArray(int *&a, int & n) {
	cout << "Enter n: "; cin >> n;
	a = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
}

void outputArray(int *a, int n) {
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
}

int* findMax(int* a, int n){
	int res = a[0];
	for (int i = 0; i < n; i++){
		if (res < *(a + i)){
			res = *(a + i);
		}
	}
	return &res;
}


int* copyArray(int* a, int n){
	int *newArray = new int[n];
	for (int i = 0; i < n; i++){
		*(newArray + i) = *(a + i);
		//cout << *(a + i) << " ";
	}
	return newArray;
}

int* countEvens(int* arr, int n, int* evens){
	int countEven = 0;
	for (int i = 0; i < n; i++){
		if (*(arr + i) % 2 == 0)
			countEven++;
	}
	for (int i = 0, k=0; i < n; i++){
		if (*(arr + i) % 2 == 0)
			evens[k] = arr[i], k++;
	}
	return &countEven;
}


int main()
{
	/*
	int x, y, *a = &x, *b = &y;
	cout << "Enter 2 integers: ";
	cin >> x >> y;
	swap(a, b);
	cout << *a << " " << *b<<endl;
	cout << *a << "+" << *b << "=" << *sum(a, b);
	
	int n;
	int *a;
	inputArray(a, n);
	//outputArray(a, n);
	int evens[90],k;
	k = *countEvens(a, n, evens);
	cout << k << endl << "Even numbers: ";
	for (int i=0; i<k ; i++){
		cout << *(evens+i) << " ";
	}
	
	/*
	int *res = copyArray(a, n);
	for (int i = 0; i < n; i++){
		cout << *(res + i) << " ";
	}
	
	delete[] a;
	return 0;
}*/