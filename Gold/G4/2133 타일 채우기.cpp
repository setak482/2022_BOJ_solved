#include <bits/stdc++.h>
using namespace std;
int dp[31];
int main(){
    int N; cin >> N;
    if(N % 2 != 0){
        cout << 0;
        exit(0);
    }
    dp[0] = 1;
    dp[2] = 3;
    for(int i = 4; i <= N; i += 2){
        dp[i] += 3*dp[i-2];
        for(int j = i-4; j >= 0; j -= 2){
            dp[i] += 2 * dp[j];
        }
    }
    cout << dp[N];
}