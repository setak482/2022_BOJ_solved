#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int num;
int id = 0;
vector<int> arr, idx, result;
int ldp[1000001];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int arrsize; cin >> arrsize;
    arr.push_back(20040802);
    idx.push_back(20040802);
    for(int i = 0; i < arrsize; i++){
        cin >> num;
        arr.push_back(num);
        if(id == 0){
            ldp[id++] = num;
            idx.push_back(0);
        }
        else{
            if(ldp[id-1] < num){
                idx.push_back(id);
                ldp[id++] = num;
            }
            else{
                auto iter = lower_bound(ldp, ldp + id, num);
                idx.push_back(iter - ldp);
                *iter = num;
            }
        }
    }
    cout << id << '\n';
    for(int i = arrsize; i >= 1; i--){
        if(id == idx[i]+1){
            result.push_back(arr[i]); id--;
        }
    }
    for(auto i = result.rbegin(); i < result.rend(); i++){
        cout << *i << ' ';
    }
}