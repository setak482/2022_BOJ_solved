#include <bits/stdc++.h>
using namespace std;
int memo[1001][1001] = {0, };
int combination(int n, int r){
    if(memo[n][r] != 0) return memo[n][r];
    if(n == r || r == 0) return 1;
    memo[n][r] = ((combination(n-1, r-1) % 10007) + (combination(n-1, r) % 10007)) % 10007;
    return memo[n][r];
}

int main(){
    int a, b; cin >> a >> b;
    cout << combination(a, b);
}