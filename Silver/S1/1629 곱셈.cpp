#include <bits/stdc++.h>
#define ull unsigned long long
using namespace std;
ull c;
ull power(ull a, ull b){
    if(b == 1){
        return a % c;
    }
    ull pows = power(a, b/2) % c;
    if (b % 2 == 0){
        return pows * pows;
    }
    else{
        return ((pows * pows) % c) * a;
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ull a, b; cin >> a >> b >> c;
    cout << power(a, b) % c;
}