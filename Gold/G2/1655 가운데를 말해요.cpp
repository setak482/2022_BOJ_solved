#include <bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    priority_queue<int, deque<int>, less<int>> pq_g; // 내림차순
    priority_queue<int, deque<int>, greater<int>> pq_l; // 오름차순
    int tc; cin >> tc;
    while(tc--){
        int midpoint;
        int a; cin >> a;
        if(pq_g.size() > pq_l.size()) pq_l.push(a);
        else pq_g.push(a);
        if(pq_g.size() != 0 && pq_l.size() != 0) {
            if(pq_g.top() >= pq_l.top()){
                int maxh = pq_g.top();
                pq_g.pop(); pq_g.push(pq_l.top());
                pq_l.pop(); pq_l.push(maxh);
            }
        }
        cout << pq_g.top() << '\n';
    }
}