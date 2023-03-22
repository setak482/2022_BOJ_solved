#include <bits/stdc++.h>
#define ll long long
using namespace std;
struct point{ll x, y;};
ll CCW(point p1, point p2, point p3){
    ll res = (p2.x-p1.x) * (p3.y-p1.y) - (p3.x-p1.x) * (p2.y-p1.y);
    if(res > 0) return 1;
    else if(res == 0) return 0;
    else return -1;
}
int main(){
    point A, B, C, D;
    cin >> A.x >> A.y;
    cin >> B.x >> B.y;
    cin >> C.x >> C.y;
    cin >> D.x >> D.y;
    ll ab = CCW(A, B, C) * CCW(A, B, D);
    ll cd = CCW(C, D, A) * CCW(C, D, B);
    if(ab == 0 && cd == 0){
        if((((min(A.x, B.x) <= max(C.x, D.x)) && (min(A.y, B.y) <= max(C.y, D.y))) && (min(C.x, D.x) <= max(A.x, B.x))) && (min(C.y, D.y) <= max(A.y, B.y))){
            cout << 1;
            return 0;
        }
        else{
            cout << 0;
            return 0;
        }
    }
    cout << (ab <= 0 && cd <= 0);
}