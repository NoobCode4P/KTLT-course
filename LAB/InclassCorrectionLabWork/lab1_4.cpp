#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

void genMatrix(int **&p, int &m, int &n)
{
	cout << "Length: ";
	cin >> m;
	cout << "Width: ";
	cin >> n;
	p = new int*[m];
	for (int i = 0; i < m; ++i)
		p[i] = new int[n];
	for (int i = 0; i < m; ++i)
		for (int j = 0; j < n; ++j)
			p[i][j] = rand() % (100 - 1 + 1) + 1;
}

void output(int **p, int m, int n)
{
	for (int i = 0; i < m; ++i){
		for (int j = 0; j < n; ++j)
			cout << p[i][j] << " ";
		cout << endl;
	}	
}

void swapRows(int**& a, int length, int width, int row1, int row2) {
	int *p = a[row1];
	a[row1] = a[row2];
	a[row2] = p;
}
void swapColumns(int **&a, int length, int width, int col1, int col2) {
	for (int i = 0; i < length; i++) {
		swap(a[i][col1], a[i][col2]);
	}
}
int**TransposeMatrix(int**&A, int m, int n)
{
	int **c;
	c = new int*[n];
	for (int i = 0; i < n; i++)
	{
		c[i] = new int[m];
	}
	for (int i = 0; i < n; i++)
	{
		
		for (int j = 0; j < m; j++)
		{
			c[i][j] = A[j][i];
		}
	}
	return c;
}

int** concatenate2MatricesH(int** a, int** b, int length, int width)
{
	int** H = new int *[length];
	for (int i = 0; i < length; i++)
	{
		H[i] = new int[width * 2];
	}

	for (int i = 0; i < length; i++)
	{
		for (int j = 0; j < width; j++)
		{
			H[i][j] = a[i][j];
		}
	}
	for (int i = 0; i < length; i++)
	{
		for (int j = 0; j < width; j++)
		{
			H[i][j + width] = b[i][j];
		}
	}
	return H;
}

int** concatenate2MatricesV(int** a, int** b, int length, int width)
{
	int** V = new int *[length*2];
	for (int i = 0; i < length*2; i++)
	{
		V[i] = new int[width];
	}

	for (int i = 0; i < length; i++)
	{
		for (int j = 0; j < width; j++)
		{
			V[i][j] = a[i][j];
		}
		for (int j = 0; j < width; j++)
		{
			V[i + length][j] = b[i][j];
		}
	}
	return V;
}

int** findSubmatrix(int** a, int length, int width, int &length_, int &width_)
{
	int max = 0, maxR1 = -1, maxC1 = -1, maxR2 = -1, maxC2 = -1;

	int ** ans = new int*[length];
	for (int i = 0; i < length; i++)
		ans[i] = new int[width];

	int ** sum = new int*[length];
	for (int i = 0; i < length; i++)
		sum[i] = new int[width];

	//Calculate sum 2D
	for (int i = 0; i < width; i++)
		sum[0][i] = (i == 0 ? 0 : sum[0][i - 1]) + a[0][i];
	for (int i = 0; i < length; i++)
		sum[i][0] = (i == 0 ? 0 : sum[i - 1][0]) + a[i][0];

	for (int i = 1; i < length; i++)
		for (int j = 1; j < width; j++)
			sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + a[i][j];

	//End calculate sum 2D

	for (int r1 = 0; r1 < length; r1++)
		for (int c1 = 0; c1 < width; c1++)
			for (int r2 = r1; r2< length; r2++)
				for (int c2 = c1; c2 < width; c2++){
					int tmp = sum[r2][c2];
					tmp -= (r1 == 0 ? 0 : sum[r1 - 1][c2]);
					tmp -= (c1 == 0 ? 0 : sum[r2][c1 - 1]);
					tmp += (r1 == 0 || c1 == 0) ? 0 : sum[r1 - 1][c1 - 1];
					if (tmp > max){
						max = tmp;
						maxR1 = r1, maxC1 = c1;
						maxR2 = r2, maxC2 = c2;
					}
				}

	cout << "--------------------------------\n";
	cout << "Max sum: " << max << '\n';
	cout << maxR1 << ' ' << maxC1 << ' ' << maxR2 << ' ' << maxC2 << '\n';
	cout << "--------------------------------\n";

	if (maxR1 == -1 || maxC1 == -1 || maxR2 == -1 || maxC2 == -1) return ans;

	//Gen ans array
	length_ = maxR2 - maxR1 + 1;
	width_ = maxC2 - maxC1 + 1;

	for (int i = 0; i < length_; i++){
		for (int j = 0; j < width_; j++){
			ans[i][j] = a[i + maxR1][j + maxC1];
			cout << ans[i][j] << ' ';
		}
		cout << '\n';
	}

	return ans;
}
int main()
{
	/*int **p,**a, **b, m, n;
	int length, width;
	srand(time(NULL));*/
	/*genMatrix(p, m, n);
	output(p, m, n);
	cout << "Transpose Matrix:\n";
	a = TransposeMatrix(p, m, n);
	output(a, n, m);
	cout << "Swap 1 & 2" << endl;
	//swapRows(p, m, n, 1, 2);
	swapColumns(p, m, n, 1, 2);
	output(p, m, n);
	
	for (int i = 0; i < m; ++i)
		delete[] p[i];
	delete[] p;*/
	
	/*genMatrix(a, length, width);
	output(a, length, width);
	genMatrix(b, length, width);
	output(b, length, width);*/
	/*int** h = concatenate2MatricesH(a, b, length, width);
	output(h, length, width*2);*/
	/*int** v = concatenate2MatricesV(a, b, length, width);
	output(v, length*2, width);
	system("pause");*/

	int length = 5, width = 6, length_ = 0, width_ = 0;
	int** a;
	genMatrix(a, length, width);
	output(a, length, width);
	int ** ans = findSubmatrix(a, length, width, length_, width_);
	//output(ans, length_, width_);
	return 0;
}