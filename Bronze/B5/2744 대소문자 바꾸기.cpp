#include <bits/stdc++.h>
using namespace std;
int main(){
    string str; cin >> str;
    for(int i = 0; i < str.length(); i++){
        if(str[i] <= 'Z'){
            str[i] = char(int(str[i])+32);
        }
        else if(str[i] >= 'a'){
            str[i] = char(int(str[i])-32);
        }
    }
    cout << str;
}