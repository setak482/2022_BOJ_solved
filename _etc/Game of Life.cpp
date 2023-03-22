#include <bits/stdc++.h>
#include <windows.h>
using namespace std;
int gen;
int grid[12][12];
int next_grid[12][12];
int moveset[2][8] = {{1, 1, 0, -1, -1, -1, 0, 1},{0, 1, 1, 1, 0, -1, -1, -1}};
bool freezing = true;
/** 생명게임 다음 스텝으로 넘어가기
 * @return 다음 스텝의 상태공간
*/
void next_step(){
    for(int y = 0; y < 12; y++){
        for(int x = 0; x < 12; x++){
            int lives = 0;
            for(int m = 0; m < 8; m++){
                int dx = x + moveset[0][m];
                if(dx < 0) dx = 11;
                else if(dx > 11) dx = 0;
                int dy = y + moveset[1][m];
                if(dy < 0) dy = 11;
                else if(dy > 11) dy = 0;
                if(dx < 12 && dx >= 0 && dy < 12 && dy >= 0){
                    if(grid[dy][dx] == 1) lives++;
                }
            }
            if(grid[y][x]){
                if(lives <= 1 || lives >= 4) next_grid[y][x] = 0;
                else next_grid[y][x] = 1;
            }
            else{
                if(lives == 3) next_grid[y][x] = 1;
                else next_grid[y][x] = 0;
            }
        }
    }
    freezing = true;
    for(int y = 0; y < 12; y++){
        for(int x = 0; x < 12; x++){
            if(grid[y][x] != next_grid[y][x]) freezing = false;
            grid[y][x] = next_grid[y][x];
        }
    }
    memset(next_grid, 0, sizeof(next_grid));
}
int main(){
    cin >> gen;
    for(int y = 0; y < 12; y++){
        for(int x = 0; x < 12; x++){
            scanf("%d", &grid[y][x]);
        }
    }
    system("cls");
    for(int i = 0; i < gen; i++){
        system("cls");
        printf("--------step %d----------\n", i+1);
        for(int y = 0; y < 12; y++){
            for(int x = 0; x < 12; x++){
                if(grid[y][x]) cout << "O ";
                else cout << "- ";
            }
            cout << '\n';
        }
        next_step();
        if(freezing){
            cout << "Game Over!";
            return 0;
        } 
        Sleep(500);
    }
    return 0;
}