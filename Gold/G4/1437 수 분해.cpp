#include <bits/stdc++.h>
using namespace std;
int main(){
    int n; cin >> n;
    if(n == 0){
        cout << 0;
        return 0;
    }
    int ans = 1;
    while(n > 0){
        if(n >= 5){
            n -= 3;
            ans = (ans * 3) % 10007;
        }
        else{
            ans = (ans * n) % 10007;
            n = 0;
        }
    }
    cout << ans;
}