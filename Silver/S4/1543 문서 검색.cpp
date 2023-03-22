#include <bits/stdc++.h>
using namespace std;
bool visited[2500];
int res;
int main(){
    string txt, pat;
    getline(cin, txt);
    getline(cin, pat);
    for(int i = 0; i < txt.length(); i++){
        bool correct = true;
        if(txt[i] == pat.front() && !visited[i] && txt.length()-i >= pat.length()){
            for(int j = 1; j < pat.length(); j++){
                if(txt[i+j] != pat[j]) correct = false;
            }
            if(correct){
                res++;
                for(int j = 0; j < pat.length(); j++){
                    visited[i+j] = true;
                }
            }
        }
    }
    cout << res;
}