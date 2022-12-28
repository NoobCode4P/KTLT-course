#include <iostream>
#include <cstring>
#include <string>
#include <cctype>
#include <sstream>
#include <vector>

#include <algorithm>

using namespace std;

//===========1/8=============
bool determine_Y_or_y(char c){
    if (tolower(c) != 'y')
        return false;
    return true;
}
//===========2/8=============
void ex2(){
    string str1,str2;
    getline(cin, str1);
    getline(cin, str2);
    if (str1 == str2) cout << "They are the same!\n";
    else cout << "They are NOT the same!\n";
}

//==========3/8==============
void ex3(){
    char str[] = "237.89";
    double value;
    value = atof(str);
}

//=========4/8==============
//Write code to get a full name of multiple words and then print it out in reverse order of words.
void ex4_String(){
    string name;
    cout << "Fullname: ";
    getline(cin,name);
    string kq = "";
    int size = name.length();
    int start = size-1;
    int end = size - 1;
    while (start >= 0){
        for (; name[start] != ' ' && start >= 0; start--);
        kq += name.substr(start+1, end - start);
        if (start > 0)
            kq += " ";
        end = start - 1;
        start--;
    }
    cout << kq << endl;
}

//===========5/8============
//Write code to receive a string s and a non-negative integer n. If the number of characters in s
//is larger than n, shorten s to n characters only. Otherwise, s is unchanged.
void ex5_String(){
    string s;
    int n;
    getline(cin, s);
    cin >> n;
    if (n < s.length())
        s = s.substr(0,n);
    cout << s << endl;
}

void ex5_CString(){
    char word[100];
    cin.getline(word,100);
    int n;
    cin >> n;
    if (n < strlen(word))
        *(word + n) = '\0';
    cout << word << endl;
}

//===========6/8===========
//Write code to receive a string of multiple words and, for every word, capitalize the first letter
//and decapitalize other letters.
void ex6_String(){
    string word;
    getline(cin,word);
    stringstream read(word);

    //count words
    int countBlankspace = 0;
    for (int i = 0; i < word.length(); i++)
        if (word[i] == ' ')
            countBlankspace++;
    int numOfWords = countBlankspace + 1;

    //read string
    string w;
    int count = 0;
    while(read >> w){
        for (int i = 0; i < w.length(); i++){
            if (i == 0)
                w[i] = toupper(w[i]);
            else
                w[i] = tolower(w[i]);
        }
        count++;
        cout << w;
        if (count < numOfWords)
            cout << " ";
    }
    cout << endl;
}

void ex6_CString(){
    char c[100];
    cin.getline(c, 100);
    int n = strlen(c);
    int i = 0; 
    while (c[i] != '\0'){
        if (i == 0 || c[i-1] == ' ')
            c[i] = toupper(c[i]);
        else c[i] = tolower(c[i]);
        i++;
    }
    cout << c << endl;
    
}

//===========7/8==========
//Write code to check whether a given string is a palindrome (case-insensitive).
void ex7_String(){
    string str;
    getline(cin,str);
    string temp = "";
    for (int i = 0; i < str.length(); i++)
        if (str[i] != ' ')
            temp += tolower(str[i]);
    bool checkPalindrome = true;
    int len = temp.length();
    for (int i = 0; i < len/2; i++)
        if (temp[i] != temp[len - 1 - i]){
            checkPalindrome = false;
            break;
        }
    if (checkPalindrome)
        cout << "This is a palindrome." << endl;
    else cout << "This is not a palindrome." << endl;         
}

void ex7_CString(){
    char c[100];
    cin.getline(c,100);
    char temp[100];
    int j = 0;
    for (int i = 0; i < strlen(c); i++)
        if (c[i] != ' ')
            temp[j++] = tolower(c[i]);
    temp[j] = '\0';
    bool check = true;
    for (int i = 0; i < j/2; i++)
        if (temp[i] != temp[j - 1 - i]){
            check = false;
            break;
        }
    (check) ? cout << "This is a palindrome." : cout << "This is not a palindrome.";
    cout << endl;
}

//==========8/8==========
//Write code to receive a string of multiple words and print the set of (distinct) words jn that
//string, as well as the frequency of each word. Assume that every pair of adjacent words is
//separated by a single whitespace.
void ex8_String(){
    string sent;
    getline(cin,sent);
    vector <string> set;
    stringstream read(sent);
    string word;
    while (read >> word)
        set.push_back(word);
    for (int i = 0; i < set.size(); i++){
        int count = 1;
        for (int j = i+1; j < set.size(); j++){
            if (set[i] == set[j]){
                count++;
                set.erase(set.begin()+j);
            }
        }
        cout << set[i] << " " << count << " ";
    }
    cout << endl;
}

void ex8_CString(){
    char sent[100];
    cin.getline(sent,100);
}

#include <map>
//==========9/8==========
//Write code to check whether a given string is a pangram (case-insensitive).
//(PANGRAM IS A SENTENCE THAT CONTAINS EVERY LETTER OF ALPHABET, IF POSSIBLE WITH EACH LETTER ONLY BEING USED ONCE)
void ex9_String(){
    string sentence;
    getline(cin,sentence);
    
    //Create a map storing UPPERCASE alphabetic letters and their frequencies
    map <char, int> alphabet;
    for (int i = 65; i <= 90; i++)
        alphabet[char(i)] = 0;
    //Check the presence of each character in sentence and Update Frequency in map
    for (int j = 0; j < sentence.size(); j++){
        if (toupper(sentence[j]) >= 'A' && toupper(sentence[j]) <= 'Z'){
            alphabet[toupper(sentence[j])]++;
        }
    }
    map <char, int> :: iterator it;
    /* for (it = alphabet.begin(); it != alphabet.end(); it++){
        cout << it->first << "\t" << it->second <<endl;
    } */
    bool checkAppearance = true;
    for (it = alphabet.begin(); it != alphabet.end(); it++){
        if (it->second == 0){
            checkAppearance = false;
            break;
        }
    }
    
    cout << "This is ";
    (checkAppearance) ? cout << "a pangram\n" : cout << "not a pangram\n";
}

void ex9_CString(){
    char sent[100];
    cin.getline(sent,100);
    int *ascii = new int [27];
    for (int i = 65; i <= 90; i++)
        ascii[i] = 0;
    for (int i = 0; i < strlen(sent); i++){
        if (toupper(sent[i]) >= 'A' && toupper(sent[i]) <= 'Z')
            ascii[(int)(toupper(sent[i]))]++;
    }
    bool check = true;
    for (int i = 65; i <= 90; i++){
        if (ascii[i] == 0){
            check = false;
            break;
        }
    }
    delete [] ascii;
    cout << "This is ";
    (check) ? cout << "a pangram\n" : cout << "not a pangram\n";
}

//==========10/9==========
// A strong password has at least 15 characters of all the following kinds: uppercase letters,
// lowercase letters, numbers and symbols (such as ` ! ” ? $ ? % ^ & * ( ) _ – + = { [ } ] : ; @ ‘ ~ # |
// < , > . ? Write code to check whether a given password is strong enough.
void ex10_String(){
    string pwd;
    getline(cin,pwd);
    bool checkLen = true;
    bool checkUpperC = false;
    bool checkLowerC = false;
    bool checkNum = false;
    bool checkSymbol = false;

    //check LENGTH
    if (pwd.length() < 15)
        checkLen = false;
    //check UpperCase
    for (int i = 0; i < pwd.length(); i++){
        if (pwd[i] >= 'A' && pwd[i] <= 'Z'){
            checkUpperC = true;
            break;
        }
    }
    //check LowerCase
    for (int i = 0; i < pwd.length(); i++){
        if (pwd[i] >= 'a' && pwd[i] <= 'z'){
            checkLowerC = true;
            break;
        }
    }
    //check Number
    for (int i = 0; i < pwd.length(); i++){
        if ((int)pwd[i] - 48 >= 0 && (int)pwd[i] - 48 <= 9){
            checkNum = true;
            break;
        }
    }
    //check Symbol
    for (int i = 0; i < pwd.length(); i++){
        int n = (int)pwd[i];
        if (n >= 33 && n <= 126){
            if(!(n >= 65 && n <= 90) && !(n >= 97 && n <= 122) && !(n >= 48 && n <= 57)){
                checkSymbol = true;
                break;
            }
        }
    }
    (checkLen && checkUpperC && checkLowerC && checkNum && checkSymbol) ? cout << "Strong enough\n" : cout << "Not strong enough\n";
}

void ex10_CString(){
    char *pwd = new char [100];
    cin.getline(pwd, 100);
    bool checkLen = true;
    bool checkUpperC = false;
    bool checkLowerC = false;
    bool checkNum = false;
    bool checkSymbol = false;

    //check LENGTH
    if (strlen(pwd) < 15)
        checkLen = false;
    //check UpperCase
    for (int i = 0; i < strlen(pwd); i++){
        if (pwd[i] >= 'A' && pwd[i] <= 'Z'){
            checkUpperC = true;
            break;
        }
    }
    //check LowerCase
    for (int i = 0; i < strlen(pwd); i++){
        if (pwd[i] >= 'a' && pwd[i] <= 'z'){
            checkLowerC = true;
            break;
        }
    }
    //check Number
    for (int i = 0; i < strlen(pwd); i++){
        if ((int)pwd[i] - 48 >= 0 && (int)pwd[i] - 48 <= 9){
            checkNum = true;
            break;
        }
    }
    //check Symbol
    for (int i = 0; i < strlen(pwd); i++){
        int n = (int)pwd[i];
        if (n >= 33 && n <= 126){
            if(!(n >= 65 && n <= 90) && !(n >= 97 && n <= 122) && !(n >= 48 && n <= 57)){
                checkSymbol = true;
                break;
            }
        }
    }
    (checkLen && checkUpperC && checkLowerC && checkNum && checkSymbol) ? cout << "Strong enough\n" : cout << "Not strong enough\n";
}

//==========11/9==========
// Write code to sort an array of strings in descending order of string length. Ties (i.e., strings of
// equal length) are broken by lexicographical order.
void ex11_String(){
    string str;
    getline(cin,str);
    stringstream read(str);

    //count words in str
    int count = 0;
    for (int i = 0; i < str.length();i++)
        if (str[i] == ' ')
            count++;
    count++;

    string *word = new string[count];
    int j = 0;
    while(read >> word[j++]);

    for (int i = 0; i < count-1; i++){
        for (int k = i+1; k < count; k++){
            if (word[k].length() > word[i].length())
                swap(word[i], word[k]);
            else if (word[k].length() < word[i].length())
                continue;
            else if (word[k].length() == word[i].length()){
                if (word[k] < word[i])
                    swap(word[i], word[k]);
            }
        }
    }

    for (int i = 0; i < count; i++)
        cout << word[i] << " ";
    cout << endl;
    delete [] word;  
}

void ex11_CString(){
    char * const sent = new char [100];
    cin.getline(sent, 100);  

    //count word
    char *ptrCount = sent;
    int count = 0;
    while (*ptrCount != '\0') {
        if (*ptrCount == ' ')
            count++;
        ptrCount++;
    }
    count++;
    
    char ** ptr = new char *[count];
    char *p = strtok(sent," ");
    int index = 0;
    while (p != nullptr) {
        ptr[index] = new char [strlen(p)+1];
        ptr[index++] = p;
        p = strtok(NULL," ");
    }
    for (int i = 0; i < count-1; i++) {
        for (int j = i+1; j < count; j++) {
            if (strlen(ptr[i]) < strlen(ptr[j]))
                swap(ptr[i], ptr[j]);
            else{
                if (strlen(ptr[i]) == strlen(ptr[j]))
                    if (strcmp(ptr[i], ptr[j]) > 0)
                        swap(ptr[i], ptr[j]);
            }
        }
    }
    for (int i = 0; i < count; i++)
        cout << ptr[i] << " ";
    //free memory allocated
    // for (int i = 0; i < count; i++)
    //     delete [] ptr[i];
    delete [] ptr;
    cout << endl;
}

//===========12/9=========
// Write code that receives a string s and then eliminates all leading blanks from the left end of s
// and all trailing blanks from the right end of s. It also replaces all subsequent spaces within the
// string by a single space.
void ex12_String(){
    string str;
    getline(cin, str);
    stringstream read(str);
    string temp;
    while (read >> temp)
        cout << temp << " ";
    cout << endl;
}

void ex12_CString(){
    char *str = new char[100];
    cin.getline(str, 100);

    char *ptr = strtok(str," ");
    while (ptr != nullptr){
        for (int i = 0; i < strlen(ptr); i++){
            cout << ptr[i];
        }
        cout << " ";
        ptr = strtok(NULL," ");
    }
    cout << endl;
}

//============13/9=============
// Write code to receive a string and a pattern (which is ensured to be shorter than the string),
// and it then deletes any but one occurrence of the pattern in the string.
void ex13_String(){
    string str;
    getline(cin,str);
    string pattern;
    getline (cin,pattern);
    if (pattern.length() > str.length()){
        cout << "The length of pattern is longer than the length of the string!";
        return;
    }
    stringstream read(str);

    vector <string> a;
    string temp;
    while(read >> temp)
        a.push_back(temp);
        
    int countOccur = 1;
    for (int i = 0; i < a.size(); i++){
        if (a[i] == pattern){
            if (countOccur > 1){
                a.erase(a.begin()+i);
                i--;
            }
            countOccur++;
        }
    }
    for (int i = 0; i < a.size(); i++)
        cout << a[i] << " ";
    cout << endl;
}



//=============14/9===========
// Write a code segment that uses built-in functions to split a string into multiple substrings
// following delimiters. For example, “apple and banana” → {“apple”, “and”, “banana”}.
void ex14_String(){
    string str;
    getline(cin, str);
    string token;

    int index = 0;
    while (index < str.length()){
        while (str[index] == ' ')
            index++;

        int begin = index;
        int stop = str.find(' ',begin);
        token = str.substr(begin, stop - begin);
        cout << token << endl;
        index = stop;
    }
}

void ex14_CString(){
    char * str = new char[100];
    cin.get(str, 100);

    char *ptr = strtok(str," ");
    while(ptr != NULL){
        cout << ptr << endl;
        ptr = strtok(NULL," ");
    }
    delete [] str;
}

//=============15/9=============
// Write a function called swap_heads(s, t) that returns a single string that consists of s, a space,
// and then t, except leading consonants of s and t have been swapped. If either s, or t, or both,
// start with a vowel, then return s and t with a space between them.
string swap_heads(string s, string t){
    string result ="";
}


int main(){
    //ex5_CString();
    ex14_String();

    return 0;
}
