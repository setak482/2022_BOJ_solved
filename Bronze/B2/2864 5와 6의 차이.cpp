#include <bits/stdc++.h>
using namespace std;
int main(){
    string sixA, sixB, fivA, fivB, originA, originB;
    cin >> originA >> originB;
    for(int i = 0; i < originA.length(); i++){
        if(originA[i] == '6' || originA[i] == '5'){
            sixA.push_back('6');
            fivA.push_back('5');
        }
        else{
            sixA.push_back(originA[i]);
            fivA.push_back(originA[i]);
        }
    }
    for(int i = 0; i < originB.length(); i++){
        if(originB[i] == '6' || originB[i] == '5'){
            sixB.push_back('6');
            fivB.push_back('5');
        }
        else{
            sixB.push_back(originB[i]);
            fivB.push_back(originB[i]);
        }
    }
    int mx = stoi(sixA) + stoi(sixB);
    int mn = stoi(fivA) + stoi(fivB);
    cout << mn << ' ' << mx;
}