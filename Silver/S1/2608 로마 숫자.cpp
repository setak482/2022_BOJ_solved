#include <bits/stdc++.h>
using namespace std;
int digitalize(char c){
    if(c == 'M') return 1000;
    else if(c == 'D') return 500;
    else if(c == 'C') return 100;
    else if(c == 'L') return 50;
    else if(c == 'X') return 10;
    else if(c == 'V') return 5;
    else if(c == 'I') return 1;
}
string undo(int i){
    string res;
    int sen = floor(i / 1000);
    while(sen--){
        res.push_back('M');
    }
    int hyaku = floor((i % 1000) / 100);
    if(hyaku == 4){
        res.push_back('C');
        res.push_back('D');
        hyaku = 0;
    }
    else if(hyaku == 9){
        res.push_back('C');
        res.push_back('M');
        hyaku = 0;
    }
    else if(hyaku >= 5){
        res.push_back('D');
        hyaku -= 5;
    }
    while(hyaku){
        res.push_back('C');
        hyaku--;
    }
    int jyu = floor((i % 100) / 10);
    if(jyu == 4){
        res.push_back('X');
        res.push_back('L');
        jyu = 0;
    }
    else if(jyu == 9){
        res.push_back('X');
        res.push_back('C');
        jyu = 0;
    }
    else if(jyu >= 5){
        res.push_back('L');
        jyu -= 5;
    }
    while(jyu){
        res.push_back('X');
        jyu--;
    }
    int ichi = i % 10;
    if(ichi == 4){
        res.push_back('I');
        res.push_back('V');
        ichi = 0;
    }
    else if(ichi == 9){
        res.push_back('I');
        res.push_back('X');
        ichi = 0;
    }
    else if(ichi >= 5){
        res.push_back('V');
        ichi -= 5;
    }
    while(ichi){
        res.push_back('I');
        ichi--;
    }
    return res;
}
int main(){
    int resA[2] = {0, };
    int resB = 0;
    for(int tc = 0; tc < 2; tc++){
        string str; cin >> str;
        for(int i = 0; i < str.length(); i++){
            int digit = digitalize(str[i]);
            if(i < str.length()-1){
                int cmp = digitalize(str[i+1]);
                if(digit < cmp) resA[tc] -= digit;
                else resA[tc] += digit;
            }
            else resA[tc] += digit;
        }
    }
    resB = resA[0] + resA[1];
    cout << resB << '\n' << undo(resB);
}