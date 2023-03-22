#include <bits/stdc++.h>
#define ll long long
#define INF __LONG_LONG_MAX__
using namespace std;
ll L, R;
ll result = INF;
void multipointer(vector<ll> &v, int a, int b){
    if(a >= b){
        cout << L << ' ' << R;
        exit(0);
    }
    ll tempresult = v[a] + v[b];
    if(abs(tempresult) < result){
        result = abs(tempresult);
        L = v[a];
        R = v[b];
    }
    if(tempresult < 0) multipointer(v, a+1, b);
    else multipointer(v, a, b-1);
}

int main(){
    int N; cin >> N;
    vector<ll> arr;
    for(int i = 0; i < N; i++){
        ll a; cin >> a;
        arr.push_back(a);
    }
    sort(arr.begin(), arr.end());
    multipointer(arr, 0, arr.size()-1);
}