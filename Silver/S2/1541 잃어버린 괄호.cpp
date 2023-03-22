#include <bits/stdc++.h>
using namespace std;
int main(){
    string cmd; cin >> cmd;
    int digit = 0;
    int result = 0;
    bool isMinus = false;
    for(auto& i : cmd){
        if(isdigit(i)){
            int num = i - '0';
            digit = (digit * 10) + num;
        }
        else{
            if(i == '+' && isMinus){
                result -= digit;
                digit = 0;
            }
            else if(i == '+' && !isMinus){
                result += digit;
                digit = 0;
            }
            else if(i == '-'){
                if(isMinus) result -= digit;
                else result += digit;
                isMinus = true;
                digit = 0;
            }
        }
    }
    if(isMinus) result -= digit;
    else result += digit;
    cout << result;
}