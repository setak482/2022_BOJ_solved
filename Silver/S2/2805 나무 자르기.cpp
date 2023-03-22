#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long
ull goal;
int parametric(vector<ull>& v, ull left, ull right){
    ull mid = (left + right)/2;
    ull res = 0;
    if(left > right) return mid;
    for(auto& i : v){
        if(i > mid){
            res += i - mid;
        }
    }
    if(res == goal){
        return mid;
    }
    else if(res < goal){
        return parametric(v, left, mid-1);
    }
    else if(res > goal){
        return parametric(v, mid+1, right);
    }
}
int main(){
    int trees; cin >> trees >> goal;
    int v_max = 0;
    vector<ull> forest;
    for(int i = 0; i < trees; i++){
        int a; cin >> a;
        v_max = max(v_max, a);
        forest.push_back(a);
    }
    cout << parametric(forest, 0, v_max);
}