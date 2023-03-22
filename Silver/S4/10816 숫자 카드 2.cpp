#include <bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    vector<int> s;
    int tc; cin >> tc;
    for(int i = 0; i < tc; i++){
        int a; cin >> a;
        s.push_back(a);
    }
    sort(s.begin(), s.end());
    int b; cin >> b;
    for(int i = 0; i < b; i++){
        int c; cin >> c;
        cout << upper_bound(s.begin(), s.end(), c) - lower_bound(s.begin(), s.end(), c) << ' ';
    }
}