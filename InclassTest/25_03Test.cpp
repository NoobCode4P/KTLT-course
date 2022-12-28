#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

/* Cho file "Cities.txt" (ít hơn 100 dòng) với mỗi dòng có định dạng:

Tên tỉnh,Diện tích,Dân số

Viết các hàm theo định dạng cho trước thỏa các yêu cầu sau:

1. Viết hàm printCities(...) in thông tin của những tỉnh trong file ra console theo định dạng:

Dân số-Họ và tên-Diện tích

2. Viết hàm sortCities(...) sắp xếp thông tin của những tỉnh trong file theo dân số tăng dần. 

3. Viết hàm calculateDensity(..., int* &less, int* &more) để cập nhật thông tin cho
các mảng more chứa các mật độ dân số lớn hơn 900 (người/km2) và less chứa 
các mật độ dân số ít hơn 300 (người/km2).
 */



struct City{
    string name;
    float area;
    double population;
};
void printCities(char *file){
    ifstream in(file);
    if(!in){
        cout << "Unable to open file!\n";
        return;
    }
    string ten;
    string dt;
    string ds;

    
    while(!in.eof()){
        getline(in,ten,',');
        getline(in,dt,',');
        getline(in,ds);
        cout << ds << "-" << ten << "-" << dt << endl;
    }
    in.close();
}
void sortCities(char * file){
    ifstream in(file);
    if(!in){
        cout << "Unable to open file!" << endl;
        return;
    }
    vector <City> a;
    City temp;
    string ten;
    string dt;
    string ds;
    while(!in.eof()){
        getline(in,temp.name,',');
        
        getline(in,dt,',');
        temp.area = stof(dt);

        getline(in, ds);
        temp.population = stod(ds);

        a.push_back(temp);
    }
    in.close();

    for (int i = 0; i < a.size()-1; i++){
        for (int j = i+1; j < a.size(); j++){
            if(a[j].population < a[i].population)
                swap(a[j],a[i]);
        }
    }
    for (int i = 0; i < a.size(); i++){
        cout << a[i].population << "----" << a[i].name << endl;
    }
}
void calculateDensity(char *file, int *&less, int *&more){
    ifstream in(file);
    if(!in){
        cout << "Unable to open file!" << endl;
        return;
    }
    vector <City> a;
    City temp;
    string ten;
    string dt;
    string ds;
    while(!in.eof()){
        getline(in,temp.name,',');
        
        getline(in,dt,',');
        temp.area = stof(dt);

        getline(in, ds);
        temp.population = stod(ds);

        a.push_back(temp);
    }
    in.close();

    less = new int[a.size()];
    more = new int[a.size()];
    int j = 0;
    int k = 0;
    
    for (int i = 0; i < a.size(); i++){
        int mdds = int(a[i].population)/a[i].area;
        if (mdds > 900)
            more[k++] = mdds;
        else if(mdds < 300)
            less[j++] = mdds;
    }
}
int main(){
    char filename[] = "Cities.txt";
    printCities(filename);
    //sortCities(filename);

    
    return 0;
}