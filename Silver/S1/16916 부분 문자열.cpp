#include <bits/stdc++.h>
using namespace std;
void prefix(string pat, int* lps){
    int len = 0;
    int n = pat.length();
    lps[0] = 0;
    int i = 1;
    while(i < n){
        if(pat[i] == pat[len]){
            len++;
            lps[i] = len;
            i++;
        }
        else{
            if(len != 0){
                len = lps[len - 1];
            }
            else{
                lps[i] = 0;
                i++;
            }
        }
    }
}
int KMP(string pat, string txt){
    int m = pat.length();
    int n = txt.length();
    int lps[m];
    prefix(pat, lps);
    int i = 0, j = 0;
    while(i < n){
        if(pat[j] == txt[i]){
            i++;
            j++;
        }
        if(j == m){
            return 1;
        }
        else if(i < n && pat[j] != txt[i]){
            if(j != 0) j = lps[j-1];
            else i = i + 1;
        }
    }
    return 0;
}
int main(){
    string a, b; cin >> a >> b;
    cout << KMP(b, a);
}