#include <iostream>
#include <vector>
using namespace std;

vector <int> F[5001];

vector <int> add(vector <int> F1, vector <int> F2){
    vector <int> F3;
    int carry = 0;
    int sum = 0;
    
    while (F1.size() < F2.size()){
        F1.push_back(0);
    }
    
    for (int i=0; i<F2.size(); ++i){
        sum = F1[i] + F2[i] + carry;
        F3.push_back(sum % 10);
        carry = (sum / 10);
    }
    
    if (carry > 0){
        F3.push_back(carry);
    }
    
    return F3;
}

int main(){
    F[0] = {0}; F[1] = {1};
    
    for (int i=2; i<5001; ++i){
        F[i] = add(F[i-2], F[i-1]);
    }
    
    int n;
    
    while (cin >> n){
        cout << "The Fibonacci number for " << n << " is ";
        for (int i=F[n].size()-1; i>=0; i--){
            cout << F[n][i];
        }
        cout << endl;
    }
    
    return 0;
}
