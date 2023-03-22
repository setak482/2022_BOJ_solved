#include <bits/stdc++.h>
using namespace std;
bool isPalindrome(string &str){
    string restr;
    restr.resize(str.length());
    reverse_copy(str.begin(), str.end(), restr.begin());
    for(int i = 0; i < str.length(); i++){
        if(str[i] != restr[i]){
            return false;
        }
    }
    return true;
}
int main(){
    string text; cin >> text;
    char fir = text.front();
    bool allsame = true;
    for(int i = 1; i < text.length(); i++){
        if(fir != text[i]){
            allsame = false;
        }
    }
    if(allsame){
        cout << -1;
        exit(0);
    }
    if(isPalindrome(text)) cout << text.length()-1;
    else cout << text.length();
}