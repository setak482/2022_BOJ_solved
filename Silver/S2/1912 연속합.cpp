#include <bits/stdc++.h>
using namespace std;
int main(){
    vector<int> arr;
    vector<int> dp;
    int tc; cin >> tc;
    for(int i = 0; i < tc; i++){
        int a; cin >> a;
        arr.push_back(a);
    }
    dp.push_back(arr[0]);
    int value = dp[0];
    for(int i = 1; i < tc; i++){
        dp.push_back(max(dp[i-1]+arr[i], arr[i]));
        value = max(dp[i], value);
    }
    cout << value;
}