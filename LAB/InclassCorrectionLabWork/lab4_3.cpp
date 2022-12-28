/*#include <iostream>
#include <cmath>
using namespace std;
void solve(float a, float b, float c) {
	if (a == 0) {
		if (b == 0 && c == 0) {
			cout << "PT co vo so nghiem";
		}
		else if (b == 0 && c != 0)
			cout << "PT vo nghiem";
		else 
			cout << "Day la pt bac 1 co nghiem x = " << -c / b;
	}
	else {
		float delta = b*b - 4 * a*c;
		if (delta < 0)
			cout << "PT vo nghiem\n";
		else if (delta == 0) {
			cout << "PT co nghiem kep:\n";
			cout << "x1 = x2 = " << -b / (2 * a) << '\n';
		}
		else {
			cout << "PT co 2 nghiem phan biet la: \n";
			cout << "x1 = " << (-b + sqrt(delta)) / (2 * a) << "\nx2 = " << (-b - sqrt(delta)) / (2 * a) << '\n';
		}
	}
}
int main() {
	float a, b, c;
	cout << "Nhap a: ";
	cin >> a;
	cout << "Nhap b: ";
	cin >> b;
	cout << "Nhap c: ";
	cin >> c;
	solve(a, b, c);
	return 0;
}*/
/*#include <iostream>
#include <cstring>
int countUpcase(char c[100])
{
	int cnt = 0;

	cin.get(c, 100, '\n');

	for (int i = 0; i < strlen(c); i++)
	{
		if (c[i] >= 'A' && c[i] <= 'Z') cnt++;
	};

	return cnt;
}
using namespace std;
int main()
{
	char c[100];

	cout <<"The number of upcase is: "<< countUpcase(c);

	return 0;
}*/

#include <iostream>
#include <cmath>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

struct point
{
	float x;
	float y;

	int quadrant();
	float dist(point B);
};

int point::quadrant(){
	if (x > 0 && y > 0) return 1;
	if (x > 0 && y < 0) return 2;
	if (x < 0 && y > 0) return 3;
	if (x < 0 && y < 0) return 4;
}

float point::dist(point B){
	return sqrt((x - B.x) * (x - B.x) + (y - B.y) * (y - B.y));
}

void genfile(){
	int n;
	string s, sothu1, sothu2, dau;
	fstream fi("input1.txt");
	fstream fo("output1.txt", ios::out);
	getline(fi, s);
	n = stoi(s);
	cout << n;
	for (int i = 0; i < n; i++){
		getline(fi, s);
		stringstream ss(s);
		getline(ss, sothu1, ' ');
		getline(ss, dau, ' ');
		getline(ss, sothu2);
		switch (dau[0]){
			case '+':{
				fo << stof(sothu1) + stof(sothu2) << endl;
				break;
			}
			case '-':{
				fo << stof(sothu1) - stof(sothu2) << endl;
				break;
			}
			case '*':{
				fo << stof(sothu1) * stof(sothu2) << endl;
				break;
			}
			case '/':{
				fo << stof(sothu1) / stof(sothu2) << endl;
				break;
			}
		}
	}
	fi.close();
	fo.close();
}

int main(){
	/*
	point A{ 1, 1};
	point B{ 2, 3 };
	cout << "Khoang cach: " << A.dist(B);
	switch (A.quadrant()){
		case 1:{
			cout << "Up right";
			break;
		}
		case 2:{
			cout << "Up left";
			break;
		}
		case 3:{
			cout << "Down right";
			break;
		}
		case 4:{
			cout << "Down left";
			break;
		}
	}
	*/

	genfile();
	return 0;
}


/*
void check(point p)
{
	if ((p.x < 0) && (p.y > 0)) cout << "A thuoc goc phan tu thu 1";
	else if ((p.x > 0) && (p.y > 0)) cout << "A thuoc goc phan tu thu 2";
	else if ((p.x > 0) && (p.y < 0)) cout << "A thuoc goc phan tu thu 3";
	else cout << "A thuoc goc phan tu thu 4";
	cout << endl;
}

float distant(point p1, point p2)
{
	return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

point midpoint(point p1, point p2)
{
	point p;
	p.x = (p1.x + p2.x) / 2;
	p.y = (p1.y + p2.y) / 2;
	return p;
}


bool collineared(point a, point b, point c)
{
	if (a.x == 0 && b.x == 0 && c.x == 0)
		return true;
	if (a.y == 0 && b.y == 0 && c.y == 0)
		return true;
	if ((b.x - a.x) / (c.x - a.x) == (b.y - a.y) / (c.y - a.y))
		return true;
	else
		return false;
}

int main()
{
	point p1, p2, a, b, c;
	cout << "A(x,y): ";
	cin >> p1.x >> p1.y;
	check(p1);
	cout << "B(x,y): ";
	cin >> p2.x >> p2.y;
	cout << "Khoang cach giua A va B: " << distant(p1, p2)<<endl;
	cout << "Trung diem cua A va B: I(" << midpoint(p1, p2).x << "," << midpoint(p1, p2).y << ")" << endl;
	cout << "a(x,y)";
	cin >> a.x >> a.y;
	cout << "b(x,y)";
	cin >> b.x >> b.y;
	cout << "c(x,y)";
	cin >> c.x >> c.y;
	if (collineared(a, b, c))
		cout << "3 given points are collineared" << endl;
	else
		cout << "3 given points are not collineared" << endl;

	return 0;
}
*/