#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll p, q;
map<ll, ll> dp;
ll dynamic(ll n){
    if(n == 0) return 1;
    if(dp.count(n)) return dp[n];
    return dp[n] = dynamic(floor(n/p)) + dynamic(floor(n/q));
}
int main(){
    dp.insert({0, 1});
    ll N; cin >> N >> p >> q;
    cout << dynamic(N);
}