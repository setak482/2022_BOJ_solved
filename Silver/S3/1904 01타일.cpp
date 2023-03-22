#include <bits/stdc++.h>
#define MOD 15746
using namespace std;
int dp[1000001];
int main(){
    int N; cin >> N;
    dp[1] = 1 % MOD;
    dp[2] = 2 % MOD;
    for(int i = 3; i < N+1; i++){
        dp[i] = (dp[i-2] + dp[i-1]) % MOD;
    }
    cout << dp[N];
}