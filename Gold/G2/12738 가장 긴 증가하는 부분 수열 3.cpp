#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int num;
vector<int> ldp;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int arrsize; cin >> arrsize;
    ldp.push_back(20040802);
    for(int i = 0; i < arrsize; i++){
        cin >> num;
        if(ldp.back() < num){
            ldp.push_back(num);
        }
        else{
            auto iter = lower_bound(ldp.begin(), ldp.end(), num);
            *iter = num;
        }
    }
    cout << ldp.size();
}