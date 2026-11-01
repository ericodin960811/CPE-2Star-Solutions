#include <iostream>
#include <vector>
using namespace std;

vector <int> multiply(vector <int> num, int m){
    vector <int> res;
    long long carry = 0;

    for (int i = 0; i < num.size() || carry > 0; ++i){
        long long curr = carry;

        if (i < num.size()){
            curr += (long long) num[i] * m;
        }

        res.push_back(curr % 10);
        carry = curr / 10;
    }

    return res;
}

vector <int> add(vector <int> a, vector <int> b){
    vector <int> res;
    long long carry = 0;
    int i = 0;

    while (i < a.size() || i < b.size() || carry > 0){
        long long curr = carry;

        if (i < a.size()){
            curr += a[i];
        }

        if (i < b.size()){
            curr += b[i];
        }

        carry = curr / 10;
        res.push_back(curr % 10);
        i++;
    }

    return res;
}

int main(){
    int n, a;

    while (cin >> n >> a){
        vector <int> Ans = {0};

        for (int i = 1; i <= n; ++i){
            vector <int> Ai = {1};

            for (int j = 1; j <= i; ++j){
                Ai = multiply(Ai, a);
            }
            Ans = add(multiply(Ai, i), Ans);
        }
        
        for (int i = Ans.size() - 1; i >= 0; i--){
            cout << Ans[i];
        }
        cout << endl;
    }

    return 0;
}