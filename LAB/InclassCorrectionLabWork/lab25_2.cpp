#include <iostream>
using namespace std;

//Đọc trước lab 2,  9h35 bắt đầu nha các bạn
//Interpolation Search

int InterpolationSearch(int a[], int n, int key){
	//Chạy trên mảng có thứ tự
	//Chạy hiệu quả trên mảng có chênh lệch giữa 2 phần tử cạnh nhau bất kì xấp xỉ nhau
	int L = 0, R = n - 1;
	while(L <= R){
		int mid = (key - a[L]) * (R - L) / (a[R] - a[L]) + L;
		if(a[mid] == key)
			return mid;
		if(a[mid] > key)
			R = mid - 1;
		if(a[mid] < key)
			L = mid + 1;
	}
	return -1;
}
/*
L     i					   R
0  1  2  3  4  5  6  7  8  9
10 15 20 25 30 35 40 45 50 1 tỷ

BinarySearch = 4  1  2

InterpolationSearch (20 - 10)(9 - 0) / (55 - 10) + 0 = 2

a[i] - a[L]      i - L
-----------  ~  -------
a[R] - a[L]      R - L
	(a[i] - a[L])(R - L)
==> --------------------- + L ~ i
		a[R] - a[L]
*/


//Insertion Sort (Sentinel)
void InsertionSort(int a[], int n){
	int temp = a[0]; // phần tử tạm lấy ra
	a[0] = INT_MIN;
	for(int i = 1; i < n; i++){
		int key = a[i];
		int j = i - 1;
		while(a[j] > key){ // bỏ được tối thiểu n phép so sánh
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = key;
	} // Sắp xếp xong mảng
	j = 1;
	while(a[j] < temp){  // thêm vào ở đây tối đa n phép so sánh
		a[j - 1] = a[j];
		j++;
	} // chèn phần tử đã lấy ra lại vào mảng
	a[j] = temp;
}

/*
Nếu phần tử nằm ở đầu mảng luôn nhỏ nhất -> bỏ điều kiện j > 0
0 1
6 3  1 2 5 4 7
*/

//Binary Insertion Sort

void InsertionSort(int a[], int n){
	int L, R, mid;
	for(int i = 1; i < n; i++){
		int key = a[i];
		L = 0;
		R = i - 1;
		while(L <= R){ // tìm vị trí j sao cho có thể chèn a[i] vào
			mid = (L + R) / 2;
			if(key < a[mid] && key > a[mid] - 1){
				for(int j = i; j > mid; j--){
					a[j] = a[j - 1]
				}
				a[mid] = key;
			}
			if(key > a[mid]){
				L = mid + 1;
			}
			if(key < a[mid - 1]){
				R = mid - 1;
			}
		}
		a[j + 1] = key;
	}
}
/*
Insertion sort chia mảng làm 2 phần đã được sắp xếp / chưa được sắp xếp
*/

//Improve Bubble Sort

void BubbleSort(int a[], int n){
	int count;
	for(int i = 1; i < n - 1; i++){
		count = 0;
		for(int j = n - 1; j >= i; j--){
			if(a[j] < a[j - 1]){
				swap(a[j], a[j - 1]);
				count++;
			}
		}
		if(count == 0)
			return;
	}
}
/*
1 2 4 3 5 7 6 9 8
1 2 3 4 5 6 7 8 9
hoang phí n - 1 vòng lặp còn lại
//Trong nhiều trường hợp, mảng của BubbleSort được sắp xếp ngay sau một vài vòng lặp đầu tiên
*/





























//Shaker Sort
int main(){
	return 0;
}