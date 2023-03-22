#include <bits/stdc++.h>
using namespace std;
int main(){
    int tc; cin >> tc;
    int result = 0;
    priority_queue<int, vector<int>, less<int>> pq_first;
    priority_queue<int, vector<int>, greater<int>> pq_second;
    for(int i = 0; i < tc; i++){
        int a; cin >> a;
        pq_first.push(a);
    }
    for(int i = 0; i < tc; i++){
        int a; cin >> a;
        pq_second.push(a);
    }
    while(!pq_first.empty()){
        result += pq_first.top() * pq_second.top();
        pq_first.pop(); pq_second.pop();
    }
    cout << result;
}