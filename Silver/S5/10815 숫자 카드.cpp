#include <bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    vector<int> v;
    int t; cin >> t;
    v.resize(t);
    for(int i = 0; i < t; i++){
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    int t2; cin >> t2;
    for(int i = 0; i < t2; i++){
        int a; cin >> a;
        cout << binary_search(v.begin(), v.end(), a) << ' ';
    }
}