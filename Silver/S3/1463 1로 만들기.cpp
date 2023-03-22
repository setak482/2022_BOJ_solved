#include <iostream>
#include <vector>
using namespace std;
int main() {
    int a;
    cin >> a;
    vector<int> dp(a + 1);

    dp[1] = 0;
    for (int i = 2; i < a+1; i++) {
        dp[i] = dp[i-1] + 1;
        if (i % 3 == 0) {
            dp[i] = min(dp[i], dp[i/3] + 1);
        }
        if (i % 2 == 0) {
            dp[i] = min(dp[i], dp[i/2] + 1);
        }
    }
    cout << dp[a];
}