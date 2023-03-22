#include <bits/stdc++.h>
using namespace std;
int main(){
    int prev = 0;
    priority_queue<int> pq;
    int n, k; cin >> n >> k;
    for(int i = 0; i < n; i++){
        int a; cin >> a;
        if(prev == 0){
            prev = a;
        }
        else{
            pq.push(abs(a - prev));
            prev = a;
        }
    }
    for(int i = 0; i < k-1; i++){
        pq.pop();
    }
    int res = 0;
    while(!pq.empty()){
        res += pq.top();
        pq.pop();
    }
    cout << res;
}