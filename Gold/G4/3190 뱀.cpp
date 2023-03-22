#include <bits/stdc++.h>
using namespace std;
bool apple_locate[101][101] = {false, };
int cmd[10001];
bool snake_locate[101][101];
int moveset[2][4] = {{1, 0, -1, 0}, {0, 1, 0, -1}}; // R D L U
int main(){
    int field; cin >> field;
    int apples; cin >> apples;
    for(int i = 0; i < apples; i++){
        int x, y; cin >> x >> y;
        apple_locate[x][y] = true;
    }
    int cmd_size; cin >> cmd_size;
    for(int i = 0; i < cmd_size; i++){
        int a; char b; cin >> a >> b;
        if(b == 'L') cmd[a] = 1; // 반시계 회전
        else if(b == 'D') cmd[a] = 2; // 시계 회전
    }
    deque<pair<int, int>> snake;
    snake.push_front({1, 1});
    snake_locate[1][1] = true;
    int game_sec = 0;
    int cur_move = 0;
    while(true){
        game_sec++;
        if(cmd[game_sec-1] == 1){
            cur_move--;
            if(cur_move < 0) cur_move = 3;
        }
        else if(cmd[game_sec-1] == 2){
            cur_move++;
            if(cur_move > 3) cur_move = 0;
        }
        int cur_x = snake.front().first;
        int cur_y = snake.front().second;
        int new_x = cur_x + moveset[0][cur_move];
        int new_y = cur_y + moveset[1][cur_move];
        if(new_x < 1 || new_x > field || new_y < 1 || new_y > field || snake_locate[new_y][new_x]){
            cout << game_sec;
            break;
        }
        else{
            snake.push_front({new_x, new_y});
            snake_locate[new_y][new_x] = true;
            if(apple_locate[new_y][new_x]) apple_locate[new_y][new_x] = false;
            else{
                snake_locate[snake.back().second][snake.back().first] = false;
                snake.pop_back();
            }
        }
    }
}