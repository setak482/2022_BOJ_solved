#include <bits/stdc++.h>
#define pp pair<int, int>
using namespace std;
struct cmp{
    bool operator()(pp a, pp b){
        if(a.second != b.second){
            return a.second > b.second;
        }
        else return a.first < b.first;
    }
};
int main(){
    priority_queue<pp, vector<pp>, cmp> pq;
    priority_queue<int, vector<int>, greater<int>> pq_res;
    int lect; cin >> lect;
    for(int i = 0; i < lect; i++){
        int a, b; cin >> a >> b;
        pq.push({a, b});
    }
    int days = 0;
    int money = 0;
    while(!pq.empty()){
        if(pq.top().second > days){
            pq_res.push(pq.top().first);
            days++;
        }
        else if(pq.top().second > days-1){
            if(pq_res.top() < pq.top().first){
                pq_res.pop();
                pq_res.push(pq.top().first); 
            }
        }
        pq.pop();
    }
    while(!pq_res.empty()){
        money += pq_res.top();
        pq_res.pop();
    }
    cout << money;
}