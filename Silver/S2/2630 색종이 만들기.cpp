#include <iostream>
#include <vector>
#include <utility>
using namespace std;
vector<vector<int>> CP;
int recursive(pair<int, int> p, pair<int, int> q, int color){
    int x1 = p.first, x2 = q.first, y1 = p.second, y2 = q.second;
    int xmid = (x1 + x2)/2, ymid = (y1 + y2)/2;
    if((x2-x1) == 1){
        if(CP[y1][x1] == color){
            return 1;
        }
        else{
            return 0;
        }
    }
    for(int y = y1; y < y2; y++){
        for(int x = x1; x < x2; x++){
            if (CP[y][x] != color){
                return recursive(make_pair(x1, ymid), make_pair(xmid, y2), color) +
                recursive(make_pair(x1, y1), make_pair(xmid, ymid), color) +
                recursive(make_pair(xmid, y1), make_pair(x2, ymid), color) +
                recursive(make_pair(xmid, ymid), make_pair(x2, y2), color);
            }
        }
    }
    return 1;
}
int main(){
    int cp_size;
    cin >> cp_size;
    for(int y = 0; y < cp_size; y++){
        CP.push_back(vector<int>(cp_size, 0));
        for(int x = 0; x < cp_size; x++){
            int a; cin >> a;
            CP[y][x] = a;
        }
    }
    cout << recursive(make_pair(0, 0), make_pair(cp_size, cp_size), 0) << '\n';
    cout << recursive(make_pair(0, 0), make_pair(cp_size, cp_size), 1);
}