#include <iostream>
#include <cmath>
using namespace std;
int main(){
    int tc;
    cin >> tc;
    for (int i = 0; i < tc; i++){
        int a, b, c, f = 1, room = 1;
        cin >> a >> b >> c;
        for(int v = 1; v < c; v++){
            if(v % a == 0 && a != 1){
                room++;
                f = 1;
            }
            else if (v % a != 0 && a != 1){
                f++;
            }
            else if (a == 1){
                room++;
                f = 1;
            }
        }
        cout << f*100 + room << '\n';
    }
}