#include <iostream>
#include <string>
#include <vector>
#include <cctype>
using namespace std;

int main(){
    string codification;
    int n;
    
    while (cin >> codification){
        cin >> n;
        
        vector <pair<long long, char>> ops;
        long long innerN = 0;
        
        for (int i = 0; i < codification.size(); ++i){
            string val = "";
            
            if (isdigit(codification[i]) || codification[i] == '-'){
                if (codification[i] == '-'){
                    val += '-';
                    i++;
                }
                
                while (isdigit(codification[i])){
                    val += codification[i];
                    i++;
                }
                
                if (codification[i] == '+' || codification[i] == '*'){
                    if (codification[i] == '+'){
                        ops.push_back({stoll(val), '+'});
                    }else{
                        ops.push_back({stoll(val), '*'});
                    }
                }else{ // ']'
                    innerN = stoll(val);
                }
            }
        }
        vector <long long> cur(n, innerN);
        vector <long long> next(n);
        
        for (int i = ops.size() - 1; i >= 0; i--){
            long long m = ops[i].first;
            char op = ops[i].second;
            
            if (op == '+'){
                next[0] = m;
                for (int j = 1; j < n; ++j){
                    next[j] = next[j - 1] + cur[j - 1];
                }
            }else{ // op == '*'
                next[0] = m * cur[0];
                for (int j = 1; j < n; ++j){
                    next[j] = next[j - 1] * cur[j];
                }
            }
            cur = next;
        }
        
        bool first = true;

        for (int i = 0; i < n; ++i){
            if (!first){
                cout << " " << cur[i];
            }else{
                cout << cur[i];
                first = false;
            }
        }
        cout << endl;
    }
    
    return 0;
}