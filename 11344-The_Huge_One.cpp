#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool isDivisible(string n, int d){
    if (d == 1) return true;
    int rem = 0;

    for (int i = 0; i < n.size(); ++i){
        rem = rem * 10 + (n[i] - '0');
        rem %= d;
    }

    if (rem == 0){
        return true;
    }else{
        return false;
    }
}

int main(){
    int n, t;
    string num;
    cin >> n;

    while (n--){
        cin >> num;
        cin >> t;
        vector <int> S(t);

        for (int i = 0; i < t; ++i){
            cin >> S[i];
        }

        bool isWonderful = true;

        for (int i = 0; i < t; ++i){
            if (!isDivisible(num, S[i])){
                isWonderful = false;
                break;
            }
        }

        if (isWonderful){
            cout << num << " - Wonderful." << endl;
        }else{
            cout << num << " - Simple." << endl;
        }
    }

    return 0;
}