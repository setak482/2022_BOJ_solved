#include <bits/stdc++.h>
using namespace std;
int mmap[26][26];
int visited[26][26] = { 0, };
int moves[2][4] = { {1, 0, -1, 0}, {0, 1, 0, -1} };
int msize; bool onaji; int depth = 0;
int org[14] = { 0, };
priority_queue<int, vector<int>, greater<int>> pq;
queue<pair<int, int>> q;
bool ispossible(int a, int b) {
    if (a < 1 || a > msize || b < 1 || b > msize
        || visited[b][a] || mmap[b][a] == 0) {
        return false;
    }
    return true;
}

void dfs(int x, int y) {
    for (int i = 0; i < 4; i++) {
        int new_x = x + moves[0][i];
        int new_y = y + moves[1][i];
        if (ispossible(new_x, new_y)) {
            depth++;
            visited[new_y][new_x]++;
            dfs(new_x, new_y);
        }
    }
}

int main() {
    scanf("%d", &msize);
    for (int y = 1; y < msize + 1; y++) {
        for (int x = 1; x < msize + 1; x++) {
            scanf("%1d", &mmap[y][x]);
        }
    }
    for (int y = 1; y < msize + 1; y++) {
        for (int x = 1; x < msize + 1; x++) {
            if(mmap[y][x] == 1 && visited[y][x] == 0){
                visited[y][x]++;
                depth = 1;
                dfs(x, y);
                pq.push(depth);
            }
        }
    }
    
    cout << pq.size() << '\n';
    while(!pq.empty()){
        cout << pq.top() << '\n'; pq.pop();
    }
}