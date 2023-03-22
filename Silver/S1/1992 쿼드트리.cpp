#include <bits/stdc++.h>
#define MAX 65
using namespace std;
int quad[MAX][MAX];
int n;
string rcr(pair<int, int> location_1, pair<int, int> location_2){
    string result;
    int x1 = location_1.first, y1 = location_1.second,
    x2 = location_2.first, y2 = location_2.second;
    int xmid = (x1 + x2) / 2, ymid = (y1 + y2) / 2;
    int init = quad[y1][x1];
    if(x2-x1 == 1){
        if(quad[y1][x1] == 1){
            return "1";
        }
        else{
            return "0";
        }
    }
    for(int cury = y1; cury < y2; cury++){
        for(int curx = x1; curx < x2; curx++){
            if(quad[cury][curx] != init){
                return "(" + rcr(make_pair(x1, y1), make_pair(xmid, ymid))+
                rcr(make_pair(xmid, y1), make_pair(x2, ymid))+
                rcr(make_pair(x1, ymid), make_pair(xmid, y2))+
                rcr(make_pair(xmid, ymid), make_pair(x2, y2)) + ")";
            }
        }
    }
    if(init == 1){
        return "1";
    }
    else return "0";
}

int main(){
    cin >> n;
    for(int y = 0; y < n; y++){
        for(int x = 0; x < n; x++){
            scanf("%1d", &quad[y][x]);
        }
    }
    cout << rcr({0, 0}, {n, n});
}