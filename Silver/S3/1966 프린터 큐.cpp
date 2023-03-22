#include <bits/stdc++.h>
using namespace std;
queue<pair<int, int>> rollback(queue<pair<int, int>> q){
    q.push(q.front());
    q.pop();
}
int main(){
    int tc; cin >> tc;
    for(int t = 0; t < tc; t++){
        int cnt = 0;
        priority_queue<int> pq;
        queue<pair<int, int>> q;
        int howmany, whichone; cin >> howmany >> whichone;
        for(int i = 0; i < howmany; i++){
            int imp; cin >> imp;
            q.push({i, imp});
            pq.push(imp);
        }
        while(!q.empty()){
            int q_loc = q.front().first;
            int q_imp = q.front().second;
            q.pop();
            if(pq.top() == q_imp){
                pq.pop();
                cnt++;
                if(whichone == q_loc){
                    cout << cnt << '\n'; break;
                }
            }
            else q.push({q_loc, q_imp});
        }
    }
}