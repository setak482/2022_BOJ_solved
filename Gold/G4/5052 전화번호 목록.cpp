#include <bits/stdc++.h>
using namespace std;
struct trie {
    bool finish;
    trie* next[10];
    trie() : finish(false) {
        memset(next, 0, sizeof(next));
    }
    ~trie(){
        for(int i = 0; i < 10; i++) {
            if(next[i]) delete next[i];
        }
    }
    void insert(const char* key) {
        if(*key == '\0') finish = true;
        else{
            int cur = *key - '0';
            if(next[cur] == NULL) next[cur] = new trie();
            next[cur]->insert(key + 1);
        }
    }
    bool find(const char* key) {
        if(*key == '\0') return false;
        if(finish) return true;
        int cur = *key - '0';
        if(next[cur] == NULL) return false;
        return next[cur]->find(key+  1);
    }
};
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc, inp; cin >> tc;
    while(tc--){
        trie *ROOT = new trie();
        cin >> inp;
        vector<string> cmd(inp);
        for(int i = 0; i < inp; i++){
            cin >> cmd[i];
            ROOT->insert(cmd[i].c_str());
        }
        for(int i = 0; i < inp; i++){
            if(ROOT->find(cmd[i].c_str())){
                cout << "NO\n";
                goto jump;
            }
        }
        cout << "YES\n";
jump:;
    }
}