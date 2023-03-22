#include <bits/stdc++.h>
using namespace std;
int main(){
    int money; cin >> money;
    money = 1000 - money;
    int cnt = 0;
    while(money > 0){
        cnt++;
        if(money >= 500) money -= 500;
        else if(money >= 100 && money < 500) money -= 100;
        else if(money >= 50 && money < 100) money -= 50;
        else if(money >= 10 && money < 50) money -= 10;
        else if(money >= 5 && money < 10) money -= 5;
        else if(money < 5) money -= 1;
    }
    cout << cnt;
}