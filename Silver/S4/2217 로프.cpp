#include <bits/stdc++.h>
using namespace std;
int main(){
    int ropes; cin >> ropes;
    int maxrope = 0;
    priority_queue<int> pq;
    for(int i = 1; i <= ropes; i++){
        int a; cin >> a;
        pq.push(a);
    }
    for(int i = 1; i <= ropes; i++){
        int c = pq.top();
        maxrope = max(c*i, maxrope);
        pq.pop();
    }
    cout << maxrope;
}