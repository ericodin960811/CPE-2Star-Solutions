#include <iostream>
#include <string>
using namespace std;

string turn(string n){
    string num = n;
    char f = num[0];
    num.erase(0, 1);
    num += f;
    
    return num;
}

bool isPrime[1000005];
bool isCircular[1000005];
int prefix[1000005];

int main(){
    fill (isPrime, isPrime + 1000005, true);
    isPrime[0] = false;
    isPrime[1] = false;
    
    for (int i = 2; i * i < 1000005; ++i){
        if (isPrime[i]){
            for (int j = i * i; j < 1000005; j += i){
                isPrime[j] = false;
            }
        }
    }
    
    fill (isCircular, isCircular + 1000005, true);
    isCircular[0] = false;
    isCircular[1] = false;
    
    for (int i = 100; i < 1000005; ++i){
        if (isPrime[i]){
            string num = to_string(i);
            bool circular = true;
            
            for (int j = 0; j < num.size(); ++j){
                if (!isPrime[stoi(num)]){
                    circular = false;
                    break;
                }
                num = turn(num);
            }
            
            if (!circular){
                isCircular[i] = false;
            }
        }else{
            isCircular[i] = false;
        }
    }
    
    prefix[99] = 0;
    
    for (int i = 100; i < 1000005; ++i){
        if (isCircular[i]){
            prefix[i] = prefix[i - 1] + 1;
        }else{
            prefix[i] = prefix[i - 1];
        }
    }
    
    int start;
    int end;
    
    while (cin >> start && start != -1){
        cin >> end;
        int ans = prefix[end] - prefix[start - 1];
        
        if (ans == 0){
            cout << "No Circular Primes." << endl;
        }else if (ans == 1){
            cout << "1 Circular Prime." << endl;
        }else{
            cout << ans << " Circular Primes." << endl;
        }
    }
    
    return 0;
}