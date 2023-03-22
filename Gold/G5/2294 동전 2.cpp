#include <bits/stdc++.h>
#define INF 99999999
using namespace std;
int dp[10001] = {INF, };
int coin[101];
int main(){
    int a, b; cin >> a >> b;
    for(int i = 0; i < a; i++){
        scanf("%d", &coin[i]);
    }
    for(int i = 1; i <= b; i++) dp[i] = INF;
    dp[0] = 1;
    for(int i = 0; i < a; i++){
        for(int j = coin[i]; j <= b; j++){
            dp[j] = min(dp[j], dp[j-coin[i]]+1);
        }
    }
    if(dp[b] == INF) cout << -1;
    else cout << dp[b]-1;
}