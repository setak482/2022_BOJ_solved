#include <bits/stdc++.h>
using namespace std;
set<pair<int, int > > visited;
int S;
struct node{
    int inScreen;
    int Clipboard;
    int depth;
};
int bfs(){
    queue<node> q;
    visited.insert({1, 0});
    q.push({1, 0, 0});
    while(!q.empty()){
        int scr = q.front().inScreen;
        int clip = q.front().Clipboard;
        int depth = q.front().depth;
        q.pop();
        if(scr == S){
            return depth;
        }
        if(!visited.count({scr, scr})){
            visited.insert({scr, scr});
            q.push({scr, scr, depth+1});
        }
        if(!visited.count({scr + clip, clip}) && clip != 0){
            visited.insert({scr + clip, clip});
            q.push({scr + clip, clip, depth+1});
        }
        if(!visited.count({scr-1, clip})){
            visited.insert({scr-1, clip});
            q.push({scr-1, clip, depth+1});
        }
    }
}
int main(){
    cin >> S;
    cout << bfs();
}