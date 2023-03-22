#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    vector<ll> padovan;
    padovan.push_back(0);
    padovan.push_back(1);
    padovan.push_back(1);
    padovan.push_back(1);
    ll tc; cin >> tc;
    deque<ll> testcase;
    for(int i = 0; i < tc; i++){
        ll a; cin >> a;
        testcase.push_back(a);
    }
    ll maxtc = *max_element(testcase.begin(), testcase.end());
    if(maxtc > 3){
        for(int i = 4; i < maxtc+1; i++){
            padovan.push_back(padovan[i-2] + padovan[i-3]);
        }
    }
    for(auto& i : testcase){
        cout << padovan[i] << '\n';
    }
}