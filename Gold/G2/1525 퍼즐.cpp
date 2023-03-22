#include <bits/stdc++.h>
using namespace std;
set<string> visited;
int move_set[2][4] = {{1, 0, -1, 0}, {0, 1, 0, -1}};
string puzzle;
string result = "123456780";
int bfs(){
    queue<pair<string, int>> q;
    q.push({puzzle, 0});
    visited.insert(puzzle);
    while(!q.empty()){
        string cur = q.front().first;
        int dep = q.front().second;
        q.pop();
        if(cur == result){
            return dep;
        }
        int z = cur.find('0');
        int x = z % 3;
        int y = z / 3;
        for(int i = 0; i < 4; i++){
            int newx = x + move_set[0][i];
            int newy = y + move_set[1][i];
            string next = cur;
            if(newx >= 0 && newy >= 0 && newx < 3 && newy < 3){
                char temp = next[(newy * 3)+newx];
                next[(newy * 3)+newx] = '0';
                next[(y*3)+x] = temp;
                if(!visited.count(next)){
                    visited.insert(next);
                    q.push({next, dep+1});
                }
            }
        }
    }
    return -1;
}
int main(){
    for(int i = 0; i < 9; i++){
        char c; cin >> c;
        puzzle.push_back(c);
    }
    cout << bfs();
}