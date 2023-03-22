#include <bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int a; cin >> a;
    vector<int> v;
    for(int i = 0; i < a; i++){
        int b; cin >> b;
        v.push_back(b);
    }
    if (next_permutation(v.begin(), v.end())){
        for(auto& i : v){
            cout << i << ' ';
        }
    }
    else{
        cout << -1;
    }
}