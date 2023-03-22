#include <bits/stdc++.h>
using namespace std;
vector<int> ans;
void prefix(string pat, vector<int> &lps){
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
void KMP(string pat, string txt){
    int m = pat.length();
    int n = txt.length();
    vector<int> lps(m);
    prefix(pat, lps);
    int i = 0, j = 0;
    while(i < n){
        if(pat[j] == txt[i]){
            i++;
            j++;
        }
        if(j == m){
            ans.push_back(i - j + 1);
            j = lps[j-1];
        }
        else if(i < n && pat[j] != txt[i]){
            if(j != 0) j = lps[j-1];
            else i = i + 1;
        }
    }
    return;
}
int main(){
    string a, b;
    getline(cin, a);
    getline(cin, b);
    KMP(b, a);
    cout << ans.size() << '\n';
    for(auto& i : ans) cout << i << ' ';
}