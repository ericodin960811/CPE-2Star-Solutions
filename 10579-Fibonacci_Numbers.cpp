#include <iostream>
#include <vector>
using namespace std;

vector <int> add(vector <int> a, vector <int> b){
    int carry = 0;
    vector <int> res;

    for (int i = 0; i < a.size(); ++i){
        int curr = carry + a[i] + b[i];
        res.push_back(curr % 10);
        carry = curr / 10;
    }

    if (a.size() == b.size()){
        if (carry != 0){
            res.push_back(carry);
        }
    }else{
        int curr = carry + b[b.size() - 1];
        res.push_back(curr % 10);
        curr /= 10;
        if (curr != 0){
            res.push_back(curr);
        }
    }

    return res;
}

int main(){
    int n;
    vector <vector<int>> Fib(5005);

    Fib[1] = {1};
    Fib[2] = {1};

    int i = 3;
    while (Fib[i - 1].size() <= 1000){
        Fib[i] = add(Fib[i - 2], Fib[i - 1]);
        i++;
    }

    while (cin >> n){
        for (int i = Fib[n].size() - 1; i >= 0; i--){
            cout << Fib[n][i];
        }
        cout << endl;
    }

    return 0;
}