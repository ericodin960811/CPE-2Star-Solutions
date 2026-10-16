#include <iostream>
#include <stack>
#include <vector>
using namespace std;
int main(){
    int n;
    while (cin >> n && n){
        while (true){
            vector <int> Order;
            int num;
            
            cin >> num;
            if (num == 0){
                break;
            }
            
            Order.push_back(num);
            for (int i=1; i<n; ++i){
                cin >> num;
                Order.push_back(num);
            }
            
            int order = Order[0];
            int outside = 1;
            stack <int> Station;
            int Oindex = 0;
            bool Go = true;
            
            while (Go){
                if (!Station.empty() && Station.top() == order){
                    Station.pop();
                    Oindex++;
                    order = Order[Oindex];
                }else if (outside <= n){
                    Station.push(outside);
                    outside++;
                }else{
                    Go = false;
                    break;
                }
            }
            
            if (Station.empty()){
                cout << "Yes" << endl;
            }else{
                cout << "No" << endl;
            }
        }
        cout << endl;
    }
    
    return 0;
}