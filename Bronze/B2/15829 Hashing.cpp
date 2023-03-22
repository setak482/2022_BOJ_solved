#include <bits/stdc++.h>
#define ll unsigned long
#define MOD 1234567891
using namespace std;
int main(){
    string str;
    ll hash = 0;
    int e; cin >> e;
    cin >> str;
    ll pw = 1;
    for(auto& i : str){
        int key = i - '`';
        hash = (hash + (key * pw)) % MOD;
        pw = (pw * 31) % MOD;
    }
    hash %= MOD;
    cout << hash;
}