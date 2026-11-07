#include <iostream>
#include <vector>
using namespace std;

vector <int> add(vector <int> a, vector <int> b){
    vector <int> res;
    int carry = 0;
    int i = 0;
    
    while (i < a.size() || i < b.size() || carry > 0){
        int curr = carry;

        if (i < a.size()){
            curr += a[i];
        }

        if (i < b.size()){
            curr += b[i];
        }

        res.push_back(curr % 10);
        carry = curr / 10;
        i++;
    }

    return res;
}

vector <int> multiply(vector <int> N, int m){
    vector <int> res;
    int carry = 0;
    int curr = 0;

    for (int i = 0; i < N.size(); ++i){
        curr = carry + N[i] * m;
        res.push_back(curr % 10);
        carry = curr / 10;
    }

    while (carry > 0){
        res.push_back(carry % 10);
        carry /= 10;
    }

    return res;
}

int main(){
    int n;
    vector <int> dp[805];

    dp[1] = {0};
    dp[2] = {1};

    for (int i = 3; i <= 800; ++i){
        dp[i] = multiply((add(dp[i - 2], dp[i - 1])), (i - 1));
    }

    while (cin >> n && n != -1){
        for (int i = dp[n].size() - 1; i >= 0; i--){
            cout << dp[n][i];
        }
        cout << endl;
    }

    return 0;
}

// Dn = (n - 1) * (Dn-1 + Dn-2)