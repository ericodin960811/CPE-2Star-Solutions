#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(){
    int t, n;
    cin >> t;
    
    while (t--){
        cin >> n;
        if (n == 1){
            cout << "1" << endl;
        }else if (n == 0){
            cout << "0" << endl;
        }else{
            string q = "";
            bool divided = true;
            
            while (n > 1){
                int lastN = n;
                
                for (int i = 9; i >= 2; i--){
                    if (n % i == 0){
                        n /= i;
                        q += to_string(i);
                        break;
                    }
                }
                if (lastN != n){
                    continue;
                }else{
                    divided = false;
                    break;
                }
            }
            
            if (divided){
                reverse(q.begin(), q.end());
                cout << q << endl;
            }else{
                cout << "-1" << endl;
            }
        }
    }
    
    return 0;
}