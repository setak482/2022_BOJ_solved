#include <iostream>
#include <vector>
#include <utility>
using namespace std;
int main(){
    int testcase;
    vector<pair<int, int>> dp(40, pair<int, int>(0, 0));
    dp[0] = make_pair(1, 0);
    dp[1] = make_pair(0, 1);
    cin >> testcase;
    for(int i = 0; i < testcase; i++){
        int input;
        cin >> input;
        if(input == 0){
            cout << dp[0].first << " " << dp[0].second << '\n';
            continue;
        }
        else if(input == 1){
            cout << dp[1].first << " " << dp[1].second << '\n';
            continue;
        }
        else{
            for(int i = 2; i < input+1; i++){
                dp[i] = make_pair(dp[i-1].first + dp[i-2].first, dp[i-1].second + dp[i-2].second);
            }
            cout << dp[input].first << " " << dp[input].second << '\n';
        }
    }
}