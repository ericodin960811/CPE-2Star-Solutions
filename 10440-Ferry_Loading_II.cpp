#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int c, n, t, m, arrival;
    cin >> c;

    while (c--){
        cin >> n >> t >> m;

        vector <int> Time;
        int trips;
        int curr_time = 0;
        int first;

        for (int i = 0; i < m; ++i){
            cin >> arrival;
            Time.push_back(arrival);
        }

        if (m % n == 0){
            first = n - 1;
            trips = m / n;
        }else{
            first = m % n - 1;
            trips = m / n + 1;
        }

        // first trip
        curr_time = Time[first] + 2 * t;

        for (int i = first + 1; i < m; i += n){
            curr_time = max(curr_time, Time[i + n - 1]) + 2 * t;
        }

        // last trip
        curr_time -= t;

        cout << curr_time << " " << trips << endl;
    }

    return 0;
}