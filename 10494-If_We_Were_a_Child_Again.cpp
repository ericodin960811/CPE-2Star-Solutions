#include <iostream>
#include <string>
using namespace std;

string divide(string n, int m, long long& rem){
    long long r = 0;
    string q = "";

    for (char c : n){
        r = r * 10 + (c - '0');
        q += to_string(r / m);
        r %= m;
    }

    rem = r;

    if (q.size() > 1){
        int i = 0;

        while (q[i] == '0' && i < q.size() - 1){
            i++;
        }

        q = q.substr(i);
    }

    return q;
}

int main(){
    int m;
    string n, op;

    while (cin >> n >> op >> m){
        long long rem = 0;

        if (op == "/"){
            cout << divide(n, m, rem) << endl;
        }else{
            divide(n, m, rem);
            cout << rem << endl;
        }
    }

    return 0;
}

// no need vector
// store from left to right, don't need to reverse