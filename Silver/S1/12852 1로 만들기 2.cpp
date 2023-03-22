#include <bits/stdc++.h>
using namespace std;
int main() {
    int a; cin >> a;
    vector<int> dp(a + 1);
    dp[1] = 0;
    for (int i = 2; i < a+1; i++) {
        dp[i] = dp[i-1] + 1;
        if (i % 3 == 0) {
            dp[i] = min(dp[i], dp[i/3] + 1);
        }
        if (i % 2 == 0) {
            dp[i] = min(dp[i], dp[i/2] + 1);
        }
    }
    cout << dp[a] << '\n';
    while(a > 0){
        cout << a << ' ';
        if(a == 1) break;
        if(dp[a] == dp[a-1] + 1){
            a--;
        }
        else if(a % 2 == 0 && dp[a] == dp[a/2]+1){
            a /= 2;
        }
        else if(a % 3 == 0 && dp[a] == dp[a/3]+1){
            a /= 3;
        }
    }
}