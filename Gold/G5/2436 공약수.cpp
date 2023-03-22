#include <bits/stdc++.h>
using namespace std;
int main(){
    int l, g, d, p, q;
    cin >> g >> l;
    d = l/g;
    for(int i = round(sqrt(d)); i >= 1 ; i--){
        if((d % i == 0) && (gcd(d/i, i) == 1)){
            p = d/i * g;
            q = i * g;
            break;
        }
    }
    cout << q << ' ' << p;
}