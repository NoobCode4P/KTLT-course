#include <iostream>
#include <fstream>

#include <map>
#include <sstream>
#include <vector>

using namespace std;


//==================2/8================
bool checkPrimeNum(int n){
    if (n < 2)
        return false;
    for (int i = 2; i*i <= n; i++)
        if (n % i == 0)
            return false;
    return true;
}
void inputNumberTXTfile(){
    ofstream out("Numbers.txt");
    if (!out) return;
    for (int i = 1; i < 101; i++)
        out << i << " ";
}
void ex2(){
    ifstream in("Numbers.txt");
    if (!in){
        cout << "ERROR: Could not open the file!" << endl;
        return;
    }
    int number;
    cout << "Prime numbers: ";
    while (in >> number){
        if (checkPrimeNum(number))
            cout << number << " ";
    }
    cout << endl;
    in.close();
}

//==================3/8===============
int Fibonacci(int n){
    int a[n+1];
    a[0] = 0;
    a[1] = 1;
    for (int i = 2; i <= n; i++)
        a[i] = a[i-1] + a[i-2];
    return a[n];
}
void ex3(){
    fstream out("Fibonacci.txt", ios::out);
    out << "Range i from 1 to 100\n";
    out << "i_th\t" << "FibonacciNum\n";
    for (int i = 1; i <= 100; i++){
        for (int j = 0; j < 14; j++)
            if (i == Fibonacci(j))
                out << j << "\t\t" << Fibonacci(j) << endl;
    }
}

//=================4/8===============
void ex4(){
    ofstream out("Fibonacci.txt");
    if(!out)
        return;
    out << "i made myself a snowball\n"
        << "as perfect as could be\n"
        << "i thought i would keep it as a pet"
        << "\nand let it sleep with me\n"
        << "i made it some pajamas\n"
        << "and a pillow for its head\n"
        << "then last night it ran away\n"
        << "but first it wet the bed\n";
    out.close();
}

//================5/8=================
void ex5(){
    ifstream in("Snowball.txt");
    if (!in){
        cout << "ERROR: unable to open the file!\n";
        return;
    }
    string word;
    map <string, int > list;
    while (in >> word){
        list[word]++;
    }
    ofstream out("Freq.txt");

    map <string, int> :: iterator it;
    for (it = list.begin(); it != list.end(); it++)
        out << it->first << " -> " << it->second << endl;

    in.close();
    out.close();
}

//==============6/8===============
void ex6(){
    ifstream in("Snowball.txt");
    if (!in){
        cout << "ERROR: unable to open the file\n";
        return;
    }
    ofstream out("newSnowball.txt");
    string line;
    string word;
    while (getline(in,line)){
        stringstream read(line);
        while (read >> word){
            if (word == "it")
                out << "snowball ";
            else out << word << " ";
        }
        out << endl;
    }
    in.close();
    out.close();
}

//==============7/8===============
void ex7(){
    ifstream in("Snowball.txt");
    if (!in){
        cout << "ERROR: Couldn't open the file\n";
        return;
    }
    //=====count Number of lines=======
    string line;
    int numoflines = 0;
    while (getline(in, line))
        numoflines++;
    
    cout << "The number of lines: " << numoflines << endl;
    int n;
    cin >> n;
    if (numoflines < n){
        cout << "Invalid input! The input number must not exceed the number of lines." << endl;
        return;
    }

    in.clear();
    in.seekg(0, ios::beg);
    
    vector <string> lines;
    while (getline(in, line))
        lines.push_back(line);
    
    lines.erase(lines.begin()+ n - 1);
    for (int i = 0; i < lines.size(); i++)
        cout << lines[i] << endl;
    in.close();
}

//==============8/8================
void ex8(){
    ifstream in("Snowball.txt");
    if (!in){
        cout << "ERROR: Couldn't open the file\n";
        return;
    }
    //=====count Number of lines=======
    string line;
    int numoflines = 0;
    while (getline(in, line))
        numoflines++;
    
    cout << "The number of lines: " << numoflines << endl;
    int n;
    cin >> n;
    if (numoflines < n){
        cout << "Invalid input! The input number must not exceed the number of lines." << endl;
        return;
    }

    in.clear();
    in.seekg(0, ios::beg);

    vector <string> lines;
    while (getline(in,line))
        lines.push_back(line);
    
    lines.insert(lines.begin() + n - 1, "i love snowball");

    for (int i = 0; i < lines.size(); i++)
        cout << lines[i] << endl;
    in.close();

}

//=============9/9================
void ex9(){
    ifstream inA("FileA.txt");
    ifstream inB("FileB.txt");

    if (!inA || !inB){
        cout << "Error: Could not open file\n";
        return;
    }
    string lineA;
    vector <string> linesA;
    while (getline(inA, lineA))
        linesA.push_back(lineA);
    
    string lineB;
    vector <string> linesB;
    while (getline(inB, lineB))
        linesB.push_back(lineB);
    
    inA.close();
    inB.close();

    int j = 0, k = 0;
    vector <string> MergedFiles;
    MergedFiles.resize(linesA.size() + linesB.size());
    for (int i = 0; i < MergedFiles.size(); i++){
        if (i % 2 == 0)
            MergedFiles[i] = linesA[j++];
        else 
            MergedFiles[i] = linesB[k++];
    }
    
    ofstream out("FileA_B.txt");
    for (int i = 0; i < MergedFiles.size(); i++)
        out << MergedFiles[i] << endl;
    out.close();
}

int main(){
    // inputNumberTXTfile();
    // ex2();
    ex9();

    return 0;
}