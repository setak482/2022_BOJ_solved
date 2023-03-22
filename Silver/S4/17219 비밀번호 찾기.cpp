#include <bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0); cin.tie(0);
    map<string, string> pw;
    int m, n; cin >> m >> n;
    for(int i = 0; i < m; i++){
        string a, b; cin >> a >> b;
        pw.insert({a, b});
    }
    for(int i = 0; i < n; i++){
        string a; cin >> a;
        cout << pw[a] << '\n';
    }
}