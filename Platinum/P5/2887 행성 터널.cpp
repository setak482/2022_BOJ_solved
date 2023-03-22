#include <bits/stdc++.h>
#define ll long long
#define triple tuple<int, int, int>
using namespace std;
int root[100001];
struct cmp{
    bool operator()(triple a, triple b){
        return get<2>(a) > get<2>(b);
    }
};
vector<pair<int, int>> xv;
vector<pair<int, int>> yv;
vector<pair<int, int>> zv;
priority_queue<triple, vector<triple>, cmp> planet;
int find(int x){
    if(x == root[x]) return x;
    int y = find(root[x]);
    root[x] = y;
    return root[x];
}
void merge(int x, int y){
    x = find(x);
    y = find(y);
    if(x == y) return;
    if(x < y) root[y] = x;
    else root[x] = y;
}
int main(){
    ll result = 0;
    int vertex; cin >> vertex;
    for(int i = 1; i <= vertex; i++){
        root[i] = i;
    }
    for(int i = 0; i < vertex; i++){
        int a, b, c; cin >> a >> b >> c;
        xv.push_back({a, i});
        yv.push_back({b, i});
        zv.push_back({c, i});
    }
    sort(xv.begin(), xv.end());
    sort(yv.begin(), yv.end());
    sort(zv.begin(), zv.end());
    for(int i = 0; i < vertex - 1; i++){
        planet.push({xv[i].second, xv[i+1].second, xv[i+1].first - xv[i].first});
        planet.push({yv[i].second, yv[i+1].second, yv[i+1].first - yv[i].first});
        planet.push({zv[i].second, zv[i+1].second, zv[i+1].first - zv[i].first});
    }
    while(!planet.empty()){
        ll s = get<0>(planet.top());
        ll e = get<1>(planet.top());
        ll dist = get<2>(planet.top());
        planet.pop();
        if(find(s) != find(e)){
            result += dist;
            merge(s, e);
        }
    }
    cout << result;
}