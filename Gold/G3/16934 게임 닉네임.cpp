#include <bits/stdc++.h>
using namespace std;
struct Trie{
    int finish; // 끝점
    unordered_map<char, Trie*> child;
    int alp_cnt[26];
    void insert(const char* pat) {
        if(*pat == '\0') finish++;
        else{
            if(!child.count(*pat))
                child[*pat] = new Trie();
            this->alp_cnt[*pat-'a']++;
            child[*pat]->insert(pat + 1);
        }
    }
    string check(const char* pat, string ans) {
        if(*pat == '\0'){
            if(this->finish == 1)
                return ans;
            else
                return ans + to_string(this->finish);
        }
        if(this->alp_cnt[*pat-'a'] == 1)
            return ans + *pat;
        return child[*pat]->check(pat+1, ans+*pat);
    }
};
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    Trie *root = new Trie();
    int tc; cin >> tc;
    for(int i = 0; i < tc; i++){
        string cmd; cin >> cmd;
        const char* cmd_c = cmd.c_str();
        root->insert(cmd_c);
        cout << root->check(cmd_c, "") << '\n';
    }
}