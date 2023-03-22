#include <bits/stdc++.h>
using namespace std;
int prior(char a){
    if(a == '+' || a == '-'){
        return 1;
    }
    else if(a == '*' || a == '/'){
        return 2;
    }
    else if(a == '('){
        return 3;
    }
}
bool isitdigit(char a){
    if (int(a) >= 65 && int(a) < 91) {
        return true;
    }
    return false;
}
int main(){
    stack<char> stk;
    string orgn_calc; cin >> orgn_calc;
    for(auto& a : orgn_calc){
        if(!isitdigit(a)){
            if(stk.empty() || stk.top() == '(' && a != ')'){
                stk.push(a);
            }
            else if (a != ')'){
                while(!stk.empty()){
                    if (stk.size() >= 1 && (prior(stk.top()) < prior(a) || stk.top() == '(')) break;
                    cout << stk.top(); stk.pop();
                }
                stk.push(a);
            }
            else{
                while(1){
                    if(stk.top() == '('){
                        stk.pop(); break;
                    }
                    cout << stk.top(); stk.pop();
                }
            }
        }
        else{
            cout << a;
        }
    }
    while(!stk.empty()){
        cout << stk.top(); stk.pop();
    }
}