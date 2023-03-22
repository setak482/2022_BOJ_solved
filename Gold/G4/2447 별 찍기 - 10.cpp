#include <bits/stdc++.h>
using namespace std;
char mapped[3073][6145] = {' ', };
char stars = '*';
void star(int n, int x, int y){
    if(n == 3){
        mapped[y][x] = stars;
        mapped[y+1][x+1] = stars;
        mapped[y+1][x-1] = stars;
        for(int i = 0; i < 5; i++){
            mapped[y+2][(x-2)+i] = stars;
        }
        return;
    }
    star(n/2, x, y);
    star(n/2, x-(n/2), y+(n/2));
    star(n/2, x+(n/2), y+(n/2));
}

int main(){
    int s; cin >> s;
    memset(mapped, ' ', sizeof(mapped));
    star(s, s-1, 0);
    for(int y = 0; y < s; y++){
        for(int x = 0; x < 2*(s-1)+1; x++){
            cout << mapped[y][x];
        }
        cout << '\n';
    }
}