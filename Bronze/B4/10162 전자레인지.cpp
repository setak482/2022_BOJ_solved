#include <bits/stdc++.h>
#define fmin 300
#define omin 60
#define tsec 10
using namespace std;
int main(){
    int time; cin >> time;
    int resultA = 0;
    int resultB = 0;
    int resultC = 0;
    while(time >= 10){
        if(time >= fmin){
            time -= fmin;
            resultA++;
        }
        else if(time >= omin){
            time -= omin;
            resultB++;
        }
        else if(time >= tsec){
            time -= tsec;
            resultC++;
        }
    }
    if(time == 0) cout << resultA << ' ' << resultB << ' ' << resultC;
    else cout << -1;
}