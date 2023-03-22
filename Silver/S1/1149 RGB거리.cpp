#include <iostream>
#include <vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cout.tie(NULL); cin.tie(NULL);
    
    int tc;
    cin >> tc;

    vector<vector<int>> ac(1001, vector<int>(3, 0));

    for(int i = 0; i < tc; i++){
        int r, g, b;
        cin >> r >> g >> b;
        ac[i][0] = r;
        ac[i][1] = g;
        ac[i][2] = b;
    }

    vector<vector<int>> dp(1001, vector<int>(3, 0));
    
    dp[0][0] = ac[0][0];
    dp[0][1] = ac[0][1];
    dp[0][2] = ac[0][2];

    for(int i = 1; i < tc; i++){
        dp[i][0] = min(dp[i-1][1], dp[i-1][2]) + ac[i][0];
        dp[i][1] = min(dp[i-1][0], dp[i-1][2]) + ac[i][1];
        dp[i][2] = min(dp[i-1][0], dp[i-1][1]) + ac[i][2];
    }

    cout << min(min(dp[tc-1][0], dp[tc-1][1]), dp[tc-1][2]);
}