#include <iostream>
#include <iomanip>
using namespace std;

int main(){
    int t, n;
    double a0, an1, ci;

    cin >> t;
    while (t--){
        double sum_c = 0;

        cin >> n >> a0 >> an1;

        for (int i = 1; i <= n; ++i){
            cin >> ci;
            sum_c += (n - i + 1) * ci;
        }

        double ans = (n * a0 + an1 - 2 * sum_c) / (n + 1);

        cout << fixed << setprecision(2) << ans << endl;

        if (t > 0) cout << endl;
    }

    return 0;
}