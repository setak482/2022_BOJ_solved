#include <bits/stdc++.h>
#define MOD 1000000000
using namespace std;
int dp[101][10][1024];
int main(){
    for(int i = 1; i <= 9; i++){
        dp[1][i][1 << i] = 1;
    }
    int N; cin >> N;
    for(int i = 0; i < N; i++){
        for(int j = 0; j <= 9; j++){
            for(int k = 0; k <= 1023; k++){
                if(j < 9){
                    dp[i+1][j+1][k | 1 << (j+1)] += dp[i][j][k];
                    dp[i+1][j+1][k | 1 << (j+1)] %= MOD;
                } 
                if(j > 0){
                    dp[i+1][j-1][k | 1 << (j-1)] += dp[i][j][k];
                    dp[i+1][j-1][k | 1 << (j-1)] %= MOD;
                } 
            }
        }
    }
    int res = 0;
    for(int i = 0; i <= 9; i++){
        res += dp[N][i][1023];
        res %= MOD;
    }
    cout << res;
}