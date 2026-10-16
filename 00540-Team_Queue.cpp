#include <iostream>
#include <string>
#include <queue>
using namespace std;

int main(){
    int t, n, num;
    int counter = 0;
    while (cin >> t && t){
        int Map[1000005];
        queue <int> teamQueues[1005];
        queue <int> mainQueue;
        
        for (int i = 0; i < t; ++i){
            cin >> n;
            while (n--){
                cin >> num;
                Map[num] = i;
            }
        }
        counter++;
        cout << "Scenario #" << counter << endl;
        
        string cmd;
        while (cin >> cmd && cmd != "STOP"){
            int enNum;
            
            if (cmd == "ENQUEUE"){
                cin >> enNum;
                int tid = Map[enNum];
                if (teamQueues[tid].empty()){
                    teamQueues[tid].push(enNum);
                    mainQueue.push(tid);
                }else{
                    teamQueues[tid].push(enNum);
                }
            }else{
                int tid = mainQueue.front();
                int deNum = teamQueues[tid].front();
                teamQueues[tid].pop();
                if (teamQueues[tid].empty()){
                    mainQueue.pop();
                }
                cout << deNum << endl;
            }
        }
        cout << endl;
    }
    
    return 0;
}