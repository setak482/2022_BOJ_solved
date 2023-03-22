#include <bits/stdc++.h>
using namespace std;
struct graph_info{
    int s;
    int e;
    int dist;
    bool operator <(const graph_info &other) const{
        return dist > other.dist; 
    }
};  
int edge, vertex, entire_weight;
priority_queue<graph_info> pq;
int mst[10001];
int find(int x){
    if(x == mst[x]) return x;
    int y = find(mst[x]);
    mst[x] = y;
    return mst[x];
}
void merge(int x, int y){
    x = find(x);
    y = find(y);
    if(x == y) return;
    if(x < y) mst[y] = x;
    else mst[x] = y;
}
bool compare(int x, int y){
    if(find(x) == find(y)) return true;
    return false;
}
int main(){
    cin >> vertex >> edge;
    for(int i = 0; i < edge; i++){
        int a, b, c; cin >> a >> b >> c;
        pq.push({a, b, c});
    }
    for(int i = 1; i <= vertex; i++){
        mst[i] = i;
    }
    while(!pq.empty()){
        int st = pq.top().s;
        int en = pq.top().e;
        int dist = pq.top().dist;
        pq.pop();
        if(!compare(st, en)){
            entire_weight += dist;
            merge(st, en);
        }
    }
    cout << entire_weight;
}