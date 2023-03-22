#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int tc, result = 0; cin >> tc;
    vector<int> v;
    for(int i = 0; i < tc; i++){
        int a; cin >> a;
        v.push_back(a);
    }
    stable_sort(v.begin(), v.end());
    vector<int> v_sum(tc+1);
    for(int i = 0; i < tc+1; i++){
        for(int ii = 0; ii < i; ii++){
            v_sum[i] += v[ii];
        }
    }
    for(auto& i : v_sum){
        result += i;
    }
    cout << result;
}