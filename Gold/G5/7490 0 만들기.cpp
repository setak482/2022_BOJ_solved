#include <bits/stdc++.h>
using namespace std;
int last_num;
void dfs(int n, int cn, int cur, int sign, string calc){
    if(abs(n) == last_num){
        cur += cn*sign;
        if(cur == 0){
            cout << calc << '\n';
        }
        return;
    }
    else{
        dfs(n+1, cn*10 + (n+1), cur, sign, calc + ' ' + to_string(n+1));
        dfs(n+1, n+1, cur+(cn*sign), 1, calc + '+' + to_string(n+1));
        dfs(n+1, n+1, cur+(cn*sign), -1, calc + '-' + to_string(n+1));
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc; cin >> tc;
    while(tc--){
        cin >> last_num;
        dfs(1, 1, 0, 1, "1");
        cout << '\n';
    }
}