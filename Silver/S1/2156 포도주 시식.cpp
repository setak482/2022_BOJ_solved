#include <iostream>
#include <vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    vector<int> dp(10001);

    int tc;
    cin >> tc;
    vector<int> ap;
    for(int i = 0; i < tc; i++){
        int a;
        cin >> a;
        ap.push_back(a);
    }

    dp[0] = ap[0];
    dp[1] = ap[0] + ap[1];
    dp[2] = max(ap[1]+ap[2] ,max(dp[1], (ap[0]+ap[2])));

    if(tc>2){
        for(int i = 3; i < tc; i++){
            dp[i] = max((dp[i-3]+ap[i]), max(max((ap[i]+ap[i-1]+dp[i-3]), (ap[i]+dp[i-2])), dp[i-1]));
        }
    }

    cout << dp[tc-1];
}