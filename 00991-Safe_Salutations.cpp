#include <iostream>
using namespace std;

int main(){
    int cat[12];
    cat[0] = 1;
    cat[1] = 1;
    
    for (int i = 2; i <= 10; ++i){
        cat[i] = 0;
        for (int j = 0; j < i; ++j){
            cat[i] += cat[j] * cat[i - j - 1];
            // 4: 0 * 3 + 1 * 2 + 2 * 1 + 3 * 0
        }
    }
    
    int n;
    bool first = true;
    
    while (cin >> n){
        if (!first){
            cout << endl;
        }else{
            first = false;
        }
        cout << cat[n] << endl;
    }
    
    return 0;
}