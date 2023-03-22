#include <bits/stdc++.h>
#define ll long long
#define pi 3.14159265358
using namespace std;
struct point{
    ll x;
    ll y;
    bool operator < (const point &other){
        if(y != other.y){
            return y < other.y;
        }
        else return x < other.x;
    }
};
vector<point> point_set;
ll CCW(point p1, point p2, point p3){
    ll res = (p2.x-p1.x) * (p3.y-p1.y) - (p3.x-p1.x) * (p2.y-p1.y);
    if(res > 0) return 1;
    else if(res == 0) return 0;
    else return -1;
}
ll dist(point a, point b){
    return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}
bool cmp(const point &a, const point &b){
    point init = point_set.front();
    ll c = CCW(init, a, b);
    if(c == 0){
        return dist(init, a) < dist(init, b);
    }
    return c > 0;
}
int main(){
    int t, l; cin >> t >> l;
    for(int i = 0; i < t; i++){
        int a, b;
        cin >> a >> b;
        point_set.push_back({a, b});
    }
    sort(point_set.begin(), point_set.end());
    sort(point_set.begin()+1, point_set.end(), cmp);
    deque<point> stk;
    stk.push_back(point_set[0]);
    stk.push_back(point_set[1]);
    for(int i = 2; i < t; i++){
        while(stk.size() >= 2 && CCW(point_set[i], stk[stk.size()-2], stk[stk.size()-1])<0){
            stk.pop_back();
        }
        stk.push_back(point_set[i]);
    }
    queue<point> q;
    point init_point = stk.front();
    double ans = (pi * 2 * l);
    while(!stk.empty()){
        while(q.size() != 2){
            q.push(stk.front());
            stk.pop_front();
        }
        point one = q.front();
        q.pop();
        ans += sqrt(dist(q.front(), one));
    }
    ans += sqrt(dist(init_point, q.front()));
    cout << round(ans);
}