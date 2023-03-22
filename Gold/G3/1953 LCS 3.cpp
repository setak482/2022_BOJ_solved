#include <bits/stdc++.h>
using namespace std;
int dp[101][101][101] = {0, };
int main(){
    string a, b, c;
    cin >> a >> b >> c;
    for(int i = 1; i < a.length()+1; i++){
        for(int j = 1; j < b.length()+1; j++){
            for(int k = 1; k < c.length()+1; k++){
                if(a[i-1] == b[j-1] && b[j-1] == c[k-1] && a[i-1] == c[k-1]){
                    dp[i][j][k] = dp[i-1][j-1][k-1] + 1;
                }
                else{
                    dp[i][j][k] = max(max(dp[i-1][j][k], dp[i][j-1][k]), dp[i][j][k-1]);
                }
            }
        }
    }
    cout << dp[a.length()][b.length()][c.length()];
}