#include <bits/stdc++.h>
using namespace std;
int main(){
    map<int, int> proof;
    int tc; cin >> tc;
    for(int i = 0; i < tc; i++){
        int a; cin >> a;
        if(!proof.count(a)) proof.insert({a, 1});
        else proof[a]++;
    }
    int b; cin >> b;
    cout << proof[b];
}