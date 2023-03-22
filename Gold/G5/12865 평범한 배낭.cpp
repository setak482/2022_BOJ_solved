#include <bits/stdc++.h>
using namespace std;
pair<int, int> arr[101];
int dp[101][100001];
int main(){
    int item, max_weight; cin >> item >> max_weight;
    for(int i = 1; i <= item; i++){
        int a, b; cin >> a >> b;
        arr[i] = {b, a};
    }
    for(int i = 1; i <= item; i++){
        for(int j = 1; j <= max_weight; j++){
            if(arr[i].second <= j){
                dp[i][j] = max(arr[i].first + dp[i-1][j-arr[i].second], dp[i-1][j]);
            }
            else dp[i][j] = dp[i-1][j];
        }
    }
    cout << dp[item][max_weight];
}