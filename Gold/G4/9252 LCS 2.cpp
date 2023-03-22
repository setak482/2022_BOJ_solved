#include <bits/stdc++.h>
using namespace std;
int dp[1001][1001] = {0, };
int main(){
    string a, b;
	string result;
    cin >> a >> b;
    for(int i = 1; i < a.length()+1; i++){
        for(int j = 1; j < b.length()+1; j++){
            if(a[i-1] == b[j-1]){
                dp[i][j] = dp[i-1][j-1] + 1;
            }
            else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    cout << dp[a.length()][b.length()];
	int loc_a = a.length();
	int loc_b = b.length();
	int cnt = dp[a.length()][b.length()];
	while(cnt){
		if(a[loc_a-1] == b[loc_b-1]){
			result.push_back(a[loc_a-1]);
			loc_a--;
			loc_b--;
			--cnt;
		}
		else{
			if(dp[loc_a-1][loc_b] > dp[loc_a][loc_b-1]) loc_a--;
			else loc_b--;
		}
	}
	reverse(result.begin(), result.end());
	cout << '\n' << result;
}