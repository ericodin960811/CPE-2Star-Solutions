#include <iostream>
using namespace std;

int BigMod(long long B, long long P, int M){
    if (P == 0) return 1;
    
    if (P % 2 == 0){
        long long half = BigMod(B, P/2, M);
        return (half * half) % M;
    } 
    
    if (P % 2 == 1){
        return B % M * BigMod(B, P-1, M) % M;
    }
    return 0;
}

int main(){
    int b, p, m;
    
    while (cin >> b >> p >> m){
        cout << BigMod(b, p, m) << endl;
    }

    return 0;
}