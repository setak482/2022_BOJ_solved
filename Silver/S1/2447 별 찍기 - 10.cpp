#include <bits/stdc++.h>
using namespace std;
char mapped[6666][6666];
void star(int n, int x, int y){
    if(n == 3){
        mapped[y][x] = '*';
        mapped[y][x+1] = '*';
        mapped[y][x+2] = '*';
        mapped[y+1][x] = '*';
        mapped[y+1][x+2] = '*';
        mapped[y+2][x] = '*';
        mapped[y+2][x+1] = '*';
        mapped[y+2][x+2] = '*';
        return;
    }
    int next = n/3;
    star(next, x, y);
    star(next, x+next, y);
    star(next, x+(next*2), y);
    star(next, x, y+next);
    star(next, x+(next*2), y+next);
    star(next, x, y+(next*2));
    star(next, x+next, y+(next*2));
    star(next, x+(next*2), y+(next*2));
}
int main(){
    int s; cin >> s;
    memset(mapped, ' ', sizeof(mapped));
    star(s, 0, 0);
    for(int y = 0; y < s; y++){
        for(int x = 0; x < s; x++){
            cout << mapped[y][x];
        }
        cout << '\n';
    }
}