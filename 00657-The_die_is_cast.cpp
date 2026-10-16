#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

int main(){
    int w, h;
    int counter = 0;
    string line;
    
    while (cin >> w >> h && w && h){
        cin.ignore();
        char pic[55][55];
        vector <int> points;
        
        for (int i = 0; i < h; ++i){
            getline(cin, line);
            for (int j = 0; j < w; ++j){
                pic[i][j] = line[j];
            }
        }
        
        for (int i = 0; i < h; ++i){
            for (int j = 0; j < w; ++j){
                if (pic[i][j] == '*'){
                    pic[i][j] = '.';
                    
                }
            }
        }
        
        counter++;
        cout << "Throw " << counter << endl;
        
        // for (int i = 0; i < h; ++i){
        //     for (int j = 0; j < w; ++j){
        //         cout << pic[i][j];
        //     }
        //     cout << endl;
        // }
    }
    
    return 0;
}