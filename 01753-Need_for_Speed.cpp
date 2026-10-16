#include <iostream>
#include <iomanip>
using namespace std;

int main(){
    int n, t;
    
    while (cin >> n >> t){
        int d[1005];
        int s[1005];
        
        for (int i = 0; i < n; ++i){
            cin >> d[i] >> s[i];
        }
        
        double high = 2000000.0;
        double low = -1e9;
        double mid;
        
        // low
        for (int i = 0; i < n; ++i){
            if (low < -s[i]){
                low = -s[i];
            }
        }
        
        for (int iter = 0; iter < 100; ++iter){
            mid = (low + high) / 2.0;
            double Time = 0.0;
            
            for (int i = 0; i < n; ++i){
                Time += d[i] / (s[i] + mid);
            }
            
            if (Time > t){
                // c 太小
                low = mid;
            }else{
                high = mid;
            }
        }
        cout << fixed << setprecision(9) << mid << endl;
    }
    
    return 0;
}

// speed = s + c
// time = dist / speed = dist / (s + c)
// t = d1 / (s1 + c) + d2 / (s2 + c) + ...

// t = di / (si + c)
// si + c > 0
// c > -si