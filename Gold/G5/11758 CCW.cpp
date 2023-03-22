#include <bits/stdc++.h>
using namespace std;
struct point{int x, y;};
int CCW(point p1, point p2, point p3){
    return (p2.x-p1.x) * (p3.y-p1.y) - (p3.x-p1.x) * (p2.y-p1.y);
}
int main(){
    point p1;
    point p2;
    point p3;
    cin >> p1.x >> p1.y;
    cin >> p2.x >> p2.y;
    cin >> p3.x >> p3.y;
    int res = CCW(p1, p2, p3);
    if(res == 0) cout << 0;
    else if(res < 0) cout << -1;
    else cout << 1;
}