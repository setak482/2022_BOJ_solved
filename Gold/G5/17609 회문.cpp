#include <bits/stdc++.h>
using namespace std;
string txt;
int palindrome(int L, int R, int res){
    while(L < R){
        if(txt[L] != txt[R]){
            if(res == 0){
                if(palindrome(L+1, R, 1) == 0 || palindrome(L, R-1, 1) == 0) return 1;
                else return 2;
            }
            else return 2;
        }
        else{
            L++;
            R--;
        }
    }
    return 0;
}
int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0); cin.tie(0);
    int tc; cin >> tc;
    while(tc--){
        cin >> txt;
        cout << palindrome(0, txt.length()-1, 0) << '\n';
        txt.clear();
    }
}