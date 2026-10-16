#include <iostream>
#include <map>
#include <string>
#include <queue>
using namespace std;

int main(){
    int counter = 0;
    string s;
    map <string, int> Map;
    queue <string> q;
    
    for (char c='a'; c<='z'; ++c){
        string s(1, c);
        Map[s] = ++counter;
        q.push(s);
    }
    
    while (!q.empty()){
        string head = q.front();
        q.pop();
        
        if (head.size() < 5){
            char c = head.back();
            for (int i=c+1; i<='z'; ++i){
                string s = head + char(i);
                Map[s] = ++counter;
                q.push(s);
            }
        }
    }
    
    while (cin >> s){
        bool isValid = true;
        
        for (int i=0; i<s.size()-1; ++i){
            if (s[i] >= s[i + 1]){
                isValid = false;
                break;
            }
        }
        
        if (isValid){
            cout << Map[s] << endl;
        }else{
            cout << '0' << endl;
        }
    }
        
    return 0;
}
// AC (18ms, 8.8MB)