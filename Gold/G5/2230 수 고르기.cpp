#include <bits/stdc++.h>
#define ll long long 
#define INF 2000000000
using namespace std;
int main(){
    ll n, m; cin >> n >> m;
    vector<ll> arr;
    for(int i = 0; i < n; i++){
        ll a; cin >> a;
        arr.push_back(a);
    }
    sort(arr.begin(), arr.end());
    int Lp = 0, Rp = 0;
    ll ans = 0;
    ll res = INF;
    while(Lp < n && Rp < n){
        if(Lp > Rp || Rp == n) break;
        ans = arr[Rp] - arr[Lp];
        if(ans >= m) res = min(res, ans);
        if(ans == m) break;
        else if(ans < m) Rp++;
        else if(ans > m) Lp++;
    }
    cout << res;
}