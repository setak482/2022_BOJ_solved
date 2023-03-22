#include <bits/stdc++.h>
using namespace std;
int num[10001];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc; cin >> tc;
    for(int i = 0; i < tc; i++){
        int a; cin >> a;
        num[a]++;
    }
    for(int i = 1; i <= 10000; i++){
        while(num[i]){
            cout << i << '\n';
            num[i]--;
        }
    }
}