#include <bits/stdc++.h>
using namespace std;
int dp[2][100001] = {0, };
int arr[2][100001] = {0, };
int main(){
    int tc; cin >> tc;
    while(tc--){
        int arrsize; cin >> arrsize;
        for(int i = 0; i < 2; i++){
            for(int j = 1; j <= arrsize; j++){
                int a; cin >> a;
                arr[i][j] = a;
            }
        }
        dp[0][1] = arr[0][1];
        dp[1][1] = arr[1][1];
        for(int i = 2; i <= arrsize; i++){
            dp[0][i] = max(dp[1][i-1], dp[1][i-2]) + arr[0][i];
            dp[1][i] = max(dp[0][i-1], dp[0][i-2]) + arr[1][i];
        }
        cout << max(dp[0][arrsize], dp[1][arrsize]) << '\n';
        memset(dp, 0, sizeof(dp));
        memset(arr, 0, sizeof(arr));
    }
}