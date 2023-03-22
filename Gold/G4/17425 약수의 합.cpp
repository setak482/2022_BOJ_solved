#include <bits/stdc++.h>
#define ll long long
#define MAX 1000001
using namespace std;
ll memo[MAX];
ll res[MAX];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    fill_n(memo, MAX, 1);
    for(int i = 2; i < MAX; i++){ // DP
        for(int j = 1; i*j < MAX; j++){
            memo[i*j] += i;
        }
    }
    for(int i = 1; i < MAX; i++){
        res[i] = res[i-1] + memo[i];
    }
    int tc; cin >> tc;
    while(tc--){
        int temp; cin >> temp;
        cout << res[temp] << '\n';
    }
}