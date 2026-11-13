#include <iostream>
#include <list> // doubly linked list
#include <algorithm> // find()
using namespace std;

int main(){
    int p, c;
    int counter = 0;

    while (cin >> p >> c && c){
        list <int> List;
        char command;
        int n;

        cout << "Case " << ++counter << ":" << endl;

        for (int i = 1; i <= min(p, c); ++i){
            List.push_back(i);
        }

        for (int i = 0; i < c; ++i){
            cin >> command;
            
            if (command == 'N'){
                int p = List.front();
                List.pop_front();
                List.push_back(p);
                cout << p << endl;
            }else{
                cin >> n;
                auto it = find(List.begin(), List.end(), n);

                if (it != List.end()){ // found
                    List.erase(it);
                }

                List.push_front(n);
            }
        }
    }

    return 0;
}