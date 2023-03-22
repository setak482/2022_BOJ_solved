#include <bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int nums, tried; cin >> nums >> tried;
    vector<int> prefix_sum(nums+1, 0);
    for(int i = 1; i <= nums; i++){
        int a; cin >> a;
        prefix_sum[i] = a + prefix_sum[i-1];
    }
    for(int i = 0; i < tried; i++){
        int b, c; cin >> b >> c;
        cout << prefix_sum[c] - prefix_sum[b-1] << '\n';
    }
}