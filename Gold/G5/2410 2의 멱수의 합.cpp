#include <bits/stdc++.h>
using namespace std;
int dp[1000001];
int main(){
    dp[1]= 1;
    dp[2]= 2;
    int N; cin >> N;
    for(int i = 3; i <= N; i++){
        if(i % 2 == 0) dp[i] = (dp[i-1] + dp[i/2]) %  1000000000;
        else dp[i] = dp[i-1];
    }
    cout << dp[N];
}