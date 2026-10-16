#include <iostream>
#include <string>
using namespace std;

void solve(string pre, string in){
    if (pre.empty()) return;
    
    char root = pre[0];
    int pos = in.find(root);
    
    string left_in = in.substr(0, pos);
    string right_in = in.substr(pos + 1);
    string left_pre = pre.substr(1, pos);
    string right_pre = pre.substr(1 + pos);
    
    solve(left_pre, left_in);
    solve(right_pre, right_in);
    
    cout << root;
}

int main(){
    string pre, in;
    
    while (cin >> pre >> in){
        solve(pre, in);
        cout << endl;
    }
    
    return 0;
}