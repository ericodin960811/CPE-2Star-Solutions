#include <iostream>
#include <vector>
using namespace std;

vector <int> multiply(vector <int> num, int m){
    int carry = 0;
    int curr;

    for (int i = 0; i < num.size(); ++i){
        curr = num[i] * m + carry;
        num[i] = curr % 10;
        carry = curr / 10;
    }

    while (carry > 0){
        num.push_back(carry % 10);
        carry = carry / 10;
    }

    return num;
}

int main(){
    int n;
    vector <int> Curr = {1};
    vector <int> Factorial[1005];

    for (int i = 1; i <= 1000; ++i){
        Curr = multiply(Curr, i);
        Factorial[i] = Curr;
    }

    while (cin >> n){
        int sum = 0;

        for (int i = 0; i < Factorial[n].size(); ++i){
            sum += Factorial[n][i];
        }

        cout << sum << endl;
    }

    return 0;
}