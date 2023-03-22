#include <bits/stdc++.h>
using namespace std;
vector<int> graph[1001];
bool isPos;
int linked[1001];
int vertex, PD;
int main(){
    cin >> vertex >> PD;
    queue<int> q;
    queue<int> wating;
    queue<int> result;
    for(int i = 0; i < PD; i++){
        int a; cin >> a;
        for(int i = 0; i < a; i++){
            int b; cin >> b;
            wating.push(b);
        }
        while(wating.size() > 1){
            int now = wating.front();
            wating.pop();
            graph[now].push_back(wating.front());
            linked[wating.front()]++;
        }
        while(!wating.empty()) wating.pop();
    }
    for(int i = 1; i <= vertex; i++){
        if(linked[i] == 0){
            q.push(i);
        }
    }
    for(int i = 1; i <= vertex; i++){
        if(q.empty()){
            isPos = true;
            break;
        }
        int temp = q.front();
        result.push(temp);
        q.pop();
        for(auto& v : graph[temp]){
            linked[v]--;
            if(linked[v] == 0){
                q.push(v);
            }
        }
    }
    if(!isPos){
        while(!result.empty()){
            cout << result.front() << '\n';
            result.pop();
        }
    }
    else cout << 0;
}