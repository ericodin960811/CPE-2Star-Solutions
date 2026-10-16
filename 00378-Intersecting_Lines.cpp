#include <iostream>
#include <iomanip>
using namespace std;

int main(){
    int t;
    int x1, y1, x2, y2, x3, y3, x4, y4;
    
    cin >> t;
    cout << "INTERSECTING LINES OUTPUT" << endl;
    while (t--){
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
        // Ax + By = C
            // A = y1 - y2, B = x2 - x1, C = Ax1 + By1;
                // { (y1 - y2)x + (x2 - x1)y = (y1 - y2)x1 + (x2 - x1)y1
                // { (y3 - y4)x + (x4 - x3)y = (y3 - y4)x3 + (x4 - x3)y3
        // 克拉瑪
        double Delta = (y1 - y2)*(x4 - x3) - (y3 - y4)*(x2 - x1);
        double Dx = ((y1 - y2)*x1 + (x2 - x1)*y1)*(x4 - x3) - ((y3 - y4)*x3 + (x4 - x3)*y3)*(x2 - x1);
        double Dy = (y1 - y2)*((y3 - y4)*x3 + (x4 - x3)*y3) - (y3 - y4)*((y1 - y2)*x1 + (x2 - x1)*y1);
        
        if (Delta != 0){
            double x = Dx / Delta;
            double y = Dy / Delta;
            cout << "POINT " << fixed << setprecision(2) << x << " " << y << endl;
        }else{
            if (Dx == Dy){
                cout << "LINE" << endl;
            }else{
                cout << "NONE" << endl;
            }
        }
    }
    cout << "END OF OUTPUT" << endl;
    
    return 0;
}