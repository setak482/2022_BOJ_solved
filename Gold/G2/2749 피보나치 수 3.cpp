#include <bits/stdc++.h>
#define jgh 1500000
#define ll long long
using namespace std;
ll fibo[jgh];
int main(){
    ll n; cin >> n;
    fibo[0] = 0;
    fibo[1] = 1;
    for(int i = 2; i < jgh; i++){
        fibo[i] = (fibo[i-2] + fibo[i-1]) % 1000000;
    }
    cout << fibo[n % jgh];
}