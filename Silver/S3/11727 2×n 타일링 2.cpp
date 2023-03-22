#include <iostream>
using namespace std;
int main(){
    int a; cin >> a;
    int dp[1001] = {0, 1, 3};
    if(a > 2){
        for(int i = 3; i < a+1; i++){
            dp[i] = ((dp[i-1] % 10007) + (2 * dp[i-2] % 10007)) % 10007;
        }
    }
    cout << dp[a];
}