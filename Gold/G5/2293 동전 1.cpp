#include <bits/stdc++.h>
using namespace std;
int dp[10001];
int coin[101];
int main(){
    int a, b; cin >> a >> b;
    for(int i = 0; i < a; i++){
        scanf("%d", &coin[i]);
    }
    dp[0] = 1;
    for(int i = 0; i < a; i++){
        for(int j = coin[i]; j <= b; j++){
            dp[j] += dp[j-coin[i]];
        }
    }
    cout << dp[b];
}