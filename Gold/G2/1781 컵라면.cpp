#include <bits/stdc++.h>
using namespace std;
struct cmp{
    bool operator()(pair<int, int> a, pair<int, int> b){
        if(a.first == b.first){
            return a.second < b.second;
        }
        else return a.first > b.first;
    }
};
int main(){
    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
    priority_queue<int, vector<int>, greater<int>> pq_2nd;
    int p_num; cin >> p_num;
    int cupramen = 0, deadline = 1;
    for(int i = 0; i < p_num; i++){
        int a, b; cin >> a >> b;
        pq.push({a, b});
    }
    while(!pq.empty()){
        pair<int, int> pr = pq.top();
        pq.pop();
        if(pr.first >= deadline){
            pq_2nd.push(pr.second);
            deadline++;
        }
        else if(pq_2nd.top() < pr.second){
            pq_2nd.pop();
            pq_2nd.push(pr.second);
        }
    }
    while(!pq_2nd.empty()){
        cupramen += pq_2nd.top();
        pq_2nd.pop();
    } 
    cout << cupramen;
}