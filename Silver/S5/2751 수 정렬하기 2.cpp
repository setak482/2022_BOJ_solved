#include <bits/stdc++.h>
#define endl '\n';
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    priority_queue<int, vector<int>, greater<int>> pq;
    int tc; cin >> tc;
    for(int i = 0; i < tc; i++){
        int a; cin >> a;
        pq.push(a);
    }
    while(!pq.empty()){
        cout << pq.top() << endl;
        pq.pop();
    }
}