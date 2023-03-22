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
    point A;
    point B;
    point C;
    point D;
    cin >> A.x >> A.y;
    cin >> B.x >> B.y;
    cin >> C.x >> C.y;
    cin >> D.x >> D.y;
    if(CCW(A, B, C) * CCW(A, B, D) < 0 && CCW(C, D, A) * CCW(C, D, B) < 0){
        cout << 1;
        exit(0);
    }
    else if(CCW(A, B, C) * CCW(A, B, D) == 0 && CCW(C, D, A) * CCW(C, D, B) == 0){
        if((A.x <= D.x || A.y <= D.y) && (B.x >= C.x || B.y >= C.y)){
            cout << 1;
        }
        else cout << 0;
        exit(0);
    }
    cout << 0;
}