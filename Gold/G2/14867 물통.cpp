#include <bits/stdc++.h>
using namespace std;
struct node{
    int a_cond;
    int b_cond;
    int depth;
};
int A_bottle_max, B_bottle_max;
map<pair<int, int>, bool> visited;
int goalA, goalB;
int bfs(){
    queue<node> q;
    visited[{0, 0}] = true;
    q.push({0, 0, 0});
    while(!q.empty()){
        int cur_a = q.front().a_cond;
        int cur_b = q.front().b_cond;
        int depth = q.front().depth;
        q.pop();
        if(cur_a == goalA && cur_b == goalB){
            return depth;
        }
        if(cur_a < A_bottle_max && !visited[{A_bottle_max, cur_b}]){
            visited[{A_bottle_max, cur_b}] = true;
            q.push({A_bottle_max, cur_b, depth+1});
        }
        if(cur_b < B_bottle_max && !visited[{cur_a, B_bottle_max}]){
            visited[{cur_a, B_bottle_max}] = true;
            q.push({cur_a, B_bottle_max, depth+1});
        }
        if(cur_a > 0 && !visited[{0, cur_b}]){
            visited[{0, cur_b}] = true;
            q.push({0, cur_b, depth+1});
        }
        if(cur_b > 0 && !visited[{cur_a, 0}]){
            visited[{cur_a, 0}];
            q.push({cur_a, 0, depth+1});
        }
        if(cur_a <= (B_bottle_max - cur_b)){
            if(!visited[{0, cur_a + cur_b}]){
                visited[{0, cur_a + cur_b}] = true;
                q.push({0, cur_a + cur_b, depth+1});
            }
        }
        else if(cur_a > (B_bottle_max - cur_b)){
            if(!visited[{cur_a-(B_bottle_max-cur_b), B_bottle_max}]){
                visited[{cur_a-(B_bottle_max-cur_b), B_bottle_max}] = true;
                q.push({cur_a-(B_bottle_max-cur_b), B_bottle_max, depth+1});
            }
        }
        if(cur_b <= (A_bottle_max - cur_a)){
            if(!visited[{cur_a+cur_b, 0}]){
                visited[{cur_a+cur_b, 0}] = true;
                q.push({cur_a+cur_b, 0, depth+1});
            }
        }
        else if(cur_b > (A_bottle_max - cur_a)){
            if(!visited[{A_bottle_max, cur_b-(A_bottle_max-cur_a)}]){
                visited[{A_bottle_max, cur_b-(A_bottle_max-cur_a)}] = true;
                q.push({A_bottle_max, cur_b-(A_bottle_max-cur_a), depth+1});
            }
        }
    }
    return -1;
}
int main(){
    cin >> A_bottle_max >> B_bottle_max >> goalA >> goalB;
    cout << bfs();
}