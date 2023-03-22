#include <bits/stdc++.h>
using namespace std;
int sudoku[9][9];
bool possible(int x, int y, int n){
    for(int i = 0; i < 9; i++){
        if(sudoku[y][i] == n || sudoku[i][x] == n){
            return false;
        }
    }
    int square_x = floor(x / 3) * 3;
    int square_y = floor(y / 3) * 3;
    for(int i = square_y; i <= square_y + 2; i++){
        for(int j = square_x; j <= square_x + 2; j++){
            if(sudoku[i][j] == n){
                return false;
            }
        }
    }
    return true;
}
void dfs(int n){
    if(n == 81){
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                cout << sudoku[i][j] << ' ';
            }
            cout << '\n';
        }
        exit(0);
    }
    else{
        int x = n % 9;
        int y = floor(n / 9);
        if(sudoku[y][x] == 0){
            for(int i = 1; i <= 9; i++){
                if(possible(x, y, i)){
                    sudoku[y][x] = i;
                    dfs(n+1);
                    sudoku[y][x] = 0;
                }
            }
        }
        else dfs(n+1);
    }
}
int main(){
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            scanf("%1d", &sudoku[i][j]);
        }
    }
    dfs(0);
}