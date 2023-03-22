#include <bits/stdc++.h>
#define pp pair<int, int>
using namespace std;
bool cmp(pp &a, pp &b){
    if(a.second == b.second)
        return a.first < b.first;
    else return a.second < b.second;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    vector<pp> v;
    int tc; cin >> tc;
    for(int i = 0 ; i < tc; i++){
        int a, b; cin >> a >> b;
        v.push_back({a, b});
    }
    sort(v.begin(), v.end(), cmp);
    for(auto& i : v){
        cout << i.first << ' ' << i.second << '\n';
    }
}