#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll cnt = 0, rslt_x, rslt_y, fin;
bool please_exit = false;

void Z(pair<ll, ll> pivot, ll level){
    ll x = pivot.first, y = pivot.second;
    if (please_exit == false){
        if (level == 0){
            fin = cnt;
            please_exit = true;
            return;
        }
        if(rslt_x < x && rslt_y < y){
            Z({x-pow(2, level-2), y-pow(2, level-2)}, level-1);
        }
        else if(rslt_x >= x && rslt_y < y){
            cnt += pow(4, level-1);
            Z({x+pow(2, level-2), y-pow(2, level-2)}, level-1);
        }
        else if(rslt_x < x && rslt_y >= y){
            cnt += 2 * pow(4, level-1);
            Z({x-pow(2, level-2), y+pow(2, level-2)}, level-1);
        }
        else if(rslt_x >= x && rslt_y >= y){
            cnt += 3 * pow(4, level-1);
            Z({x+pow(2, level-2), y+pow(2, level-2)}, level-1);
        }
    }
}
int main(){
    ll binary_sqrt; 
    cin >> binary_sqrt >> rslt_y >> rslt_x;
    Z({pow(2, binary_sqrt-1), pow(2, binary_sqrt-1)}, binary_sqrt);
    cout << fin;
}