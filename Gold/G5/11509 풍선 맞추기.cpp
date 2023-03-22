#include <bits/stdc++.h>
using namespace std;
int arr[1000001] = {0, };
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc, res = 0; cin >> tc;
    for(int i = 0; i < tc; i++){
        int a; cin >> a;
        if(arr[a+1]){
            arr[a+1]--;
            arr[a]++;
        }
        else{
            res++;
            arr[a]++;
        }
    }
    cout << res;
}