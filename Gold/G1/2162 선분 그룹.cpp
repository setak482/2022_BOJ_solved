#include <bits/stdc++.h>
using namespace std;
int root[1000001];
int visited[3001];
struct Point{int x, y;};
struct Line{Point a, b;};
int CCW(Point p1, Point p2, Point p3){
    int res = (p2.x-p1.x) * (p3.y-p1.y) - (p3.x-p1.x) * (p2.y-p1.y);
    if(res > 0) return 1;
    else if(res == 0) return 0;
    else return -1;
}
bool intersection(Line First, Line Second){
    Point A = First.a, B = First.b, C = Second.a, D = Second.b;
    int ab = CCW(A, B, C) * CCW(A, B, D);
    int cd = CCW(C, D, A) * CCW(C, D, B);
    if(ab == 0 && cd == 0){
        if((((min(A.x, B.x) <= max(C.x, D.x)) && (min(A.y, B.y) <= max(C.y, D.y))) && (min(C.x, D.x) <= max(A.x, B.x))) && (min(C.y, D.y) <= max(A.y, B.y))){
            return 1;
        }
        else return 0;
    }
    return ab <= 0 && cd <= 0;
}
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
    ios_base::sync_with_stdio(false); cin.tie(0);
    int line_cnt; cin >> line_cnt;
    for(int i = 1; i <= line_cnt; i++){
        root[i] = i;
    }
    vector<Line> v(line_cnt+1);
    for(int i = 1; i <= line_cnt; i++){
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        v[i] = {{a, b}, {c, d}};
    }
    for(int i = 1; i <= line_cnt; i++){
        for(int j = 1; j <= i; j++){
            if (intersection(v[i], v[j])) merge(i, j);
        }
    }
    for(int i = 1; i <= line_cnt; i++){
        visited[find(i)]++;
    }
    int gr_cnt = 0, max_cnt = 0;
    for(int i = 1; i <= line_cnt; i++){
        if(visited[i] > 0) gr_cnt++;
        if(visited[i] > max_cnt){
            max_cnt = visited[i];
        }
    }
    cout << gr_cnt << '\n' << max_cnt;
}