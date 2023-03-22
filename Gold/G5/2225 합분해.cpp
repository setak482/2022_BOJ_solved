#include <bits/stdc++.h>
#define ull unsigned long long
#define MOD 1000000000
using namespace std;
ull memo[404][404] = {0, };
ull combination(int n, int r){
    if(n == r || r == 0) return 1;
    ull &result = memo[n][r];
    if(result != 0) return result;
    result = ((combination(n-1, r-1) % MOD) + (combination(n-1, r) % MOD)) % MOD;
    return result;
}
int main() {
    int n, r; cin >> n >> r;
    cout << combination(n+r-1, r-1);
}