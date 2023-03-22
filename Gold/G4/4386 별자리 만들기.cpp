#include <bits/stdc++.h>
using namespace std;
struct graph_info{
    int s;
    int e;
    double dist;
    bool operator <(const graph_info &other) const{
        return dist > other.dist; 
    }
};
int vertex, edge;
vector<pair<double, double>> location;
double result;
priority_queue<graph_info> pq;
int mst[101];
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
double make_dist(double x1, double y1, double x2, double y2){
    return sqrt(pow(abs(x2-x1), 2) + pow(abs(y2-y1), 2));
}
int main(){
    cout.precision(3);
    cout.fixed;
    cin >> vertex;
    for(int i = 0; i < vertex; i++){
        double a, b; cin >> a >> b;
        location.push_back({a, b});
    }
    for(int i = 1; i <= vertex; i++){
        for(int j = i+1; j <= vertex; j++){
            int x1 = location[i-1].first;
            int y1 = location[i-1].second;
            int x2 = location[j-1].first;
            int y2 = location[j-1].second;
            pq.push({i, j, make_dist(x1, y1, x2, y2)});
        }
    }
    for(int i = 1; i <= vertex; i++){
        mst[i] = i;
    }
    while(!pq.empty()){
        int st = pq.top().s;
        int en = pq.top().e;
        double dist = pq.top().dist;
        pq.pop();
        if(!compare(st, en)){
            result += dist;
            merge(st, en);
        }
    }
    cout << result;
}