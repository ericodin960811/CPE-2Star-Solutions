#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n;
    
    while (cin >> n && n){

        for (int m=1; m<=n; ++m){
            vector <int> list;
        
            for (int i=0; i<n; ++i){
                list.push_back(i + 1);
            }
            list.erase(list.begin() + 0);
            
            int index = m - 1;
            while (list.size() > 1){
                list.erase(list.begin() + index);
                index = (index + m - 1) % list.size();
            }
            if (list[0] == 13){
                cout << m << endl;
                break;
            }
        }
    }

    return 0;
}