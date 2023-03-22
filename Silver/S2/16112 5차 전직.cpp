#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int quest, stone;
    ll ans = 0;
    priority_queue<ll, vector<ll>, greater<ll>> pq;
    cin >> quest >> stone;
    for(int i = 0; i < quest; i++){
        ll a; cin >> a;
        pq.push(a);
    }
    for(int i = 0; i < quest; i++){
        ll cur = pq.top(); pq.pop();
        ans += cur * min(stone, i);
    }
    cout << ans;
}