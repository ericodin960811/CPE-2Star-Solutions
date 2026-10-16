#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <sstream>
using namespace std;

bool isOp(string c){
    if (c == "+" || c == "-" || c == "*" || c == "/"){
        return true;
    }
    return false;
}

int main(){
    string s;
    bool fk = true;
    
    while (getline(cin, s)){
        string f = "";
        string formula = "";
        
        for (char c : s){
            if (c != ' '){
                f += c;
            }
        }
        
        for (int i=0; i<f.size(); ++i) {
            if (f[i] == '*' || f[i] == '/' || f[i] == '=') {
                formula += " ";
                formula += f[i];
                formula += " ";
            }else if (f[i] == '+' || f[i] == '-') {
                if (i > 0 && isdigit(f[i-1])) {
                    formula += " ";
                    formula += f[i];
                    formula += " ";
                }else {
                    formula += f[i];
                }
            }else {
                formula += f[i];
            }
        }
        
        vector <string> Formula;
        
        stringstream ss(formula);
        string token;
        
        while (ss >> token){
            Formula.push_back(token);
        }
        
        if (!fk){
            cout << endl;
        }else{
            fk = false;
        }
        
        for (int i=0; i<Formula.size(); ++i){
            if (i != Formula.size()-1){
                cout << Formula[i] << " ";
            }else{
                cout << Formula[i];
            }
        }
        cout << endl;
        
        while (Formula.size() > 3){
            int OpIndex = -1;
            bool first = true;
            
            for (int i=0; i<Formula.size(); ++i){
                if (Formula[i] == "*" || Formula[i] == "/"){
                    OpIndex = i;
                    break;
                }else if (Formula[i] == "+" || Formula[i] == "-"){
                    if (first){
                        OpIndex = i;
                        first = false;
                    }
                }
            }
            
            int a = stoi(Formula[OpIndex-1]);
            int b = stoi(Formula[OpIndex+1]);
            int c;
            
            if (Formula[OpIndex] == "+"){
                c = a + b;
            }else if (Formula[OpIndex] == "-"){
                c = a - b;
            }else if (Formula[OpIndex] == "*"){
                c = a * b;
            }else if (Formula[OpIndex] == "/"){
                c = a / b;
            }
            
            Formula[OpIndex-1] = to_string(c);
            Formula.erase(Formula.begin() + OpIndex, Formula.begin() + OpIndex + 2);
            
            for (int i=0; i<Formula.size(); ++i){
                if (i != Formula.size()-1){
                    cout << Formula[i] << " ";
                }else{
                    cout << Formula[i];
                }
            }
            cout << endl;
        }
    }
    
    return 0;
}