#include <iostream>
#include <string>
#include <vector>
#include <cctype>
using namespace std;

int main(){
    string line;
    vector <string> list;
    
    string s = "";
    int index = 0;
    bool alpha = false;
    bool digit = false;

    while (getline(cin, line) && line != "0"){
        for (char c : line){
            if (isalpha(c)){
                cout << c;
                s += c;
                alpha = true;
            }else if (isdigit(c)){
                index = index * 10 + (c - '0');
                digit = true;
            }else{
                if (alpha){
                    alpha = false;
                    list.insert(list.begin(), s);
                    s = "";
                }else if (digit){
                    digit = false;
                    string str = list[index - 1];
                    
                    cout << str;
                    list.erase(list.begin() + (index - 1));
                    list.insert(list.begin(), str);
                    index = 0;
                }
                cout << c;
            }
        }
        if (digit){
            digit = false;
            string str = list[index - 1];
            
            cout << str;
            list.erase(list.begin() + (index - 1));
            list.insert(list.begin(), str);
            index = 0;
        }else if (alpha){
            alpha = false;
            list.insert(list.begin(), s);
            s = "";
        }
        cout << endl;
    }
    
    
    return 0;
}