#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int main(){
    priority_queue<int, vector<int>, greater<int>> pq;
    int result = 0;
    int tc; cin >> tc;
    int p = 0, q = 0, r = 0;
    for(int i = 0; i < tc; i++){
        int a; cin >> a;
        pq.push(a);
    }
    while(pq.size() != 1){
        p = pq.top(); pq.pop();
        q = pq.top(); pq.pop();
        r = p + q;
        result += r;
        pq.push(r);
    }
    cout << result;
}