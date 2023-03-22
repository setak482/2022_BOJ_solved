#include <bits/stdc++.h>
using namespace std;
int main(){
    int x, y, w, h; cin >> x >> y >> w >> h;
    int res = min(min(min(abs(w-x), abs(h-y)), x), y);
    cout << res;
}