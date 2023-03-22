#include <bits/stdc++.h>
using namespace std;
int dp[4001][4001] = {0, };
int main(){
    string a, b;
    int maxlen = 0;
    cin >> a >> b;
    for(int i = 1; i < a.length()+1; i++){
        for(int j = 1; j < b.length()+1; j++){
            if(a[i-1] == b[j-1]){
                dp[i][j] = dp[i-1][j-1] + 1;
            }
            else{
                dp[i][j] = 0;
            }
            maxlen = max(maxlen, dp[i][j]);
        }
    }
    cout << maxlen;
}