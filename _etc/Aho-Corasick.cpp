#include <bits/stdc++.h>
using namespace std;
struct trie {
    bool finish;
    map<char, trie*> child;
    trie* fail;
    trie() : finish(false), fail(nullptr) {}
    void insert(const char* pat){
        if(*pat == '\0') finish = true;
        else{
            if(child.find(*pat) == child.end())
                child[*pat] = new trie();
            child[*pat]->insert(pat + 1);
        }
    }
    void Fail(){
        trie* root = this;
        queue<trie*> q;
        q.push(root);
        while(!q.empty()){
            trie* now = q.front();
            q.pop();
            for(auto& v : now->child){
                trie* next = v.second;
                if(now == root) next->fail = root;
                else{
                    trie* prev = now->fail;
                    while(prev != root && prev->child.find(v.first) == prev->child.end())
                        prev = prev->fail;
                    if(prev->child.find(v.first) != prev->child.end())
                        prev = prev->child[v.first];
                    next->fail = prev;
                }
                if(next->fail->finish)
                    next->finish = true;   
                q.push(next);
            }
        }
    }
};
bool KMP(string txt, trie* root){
    trie* now = root;
    int n = txt.length();
    vector<pair<string, int>> ans;
    for(int i = 0; i < n; i++){
        while (now != root && now->child.find(txt[i]) == now->child.end()) {
            now = now->fail;
        }
        if (now->child.find(txt[i]) != now->child.end()) 
            now = now->child[txt[i]];
        if (now->finish) {
            return true;
        }
    }
    return false;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    trie *root = new trie();
    for(int i = 0; i < n; i++) {
        string str; cin >> str;
        root->insert(str.c_str());
    }
    root->Fail();
    int tc; cin >> tc;
    for(int i = 0; i < tc; i++){
        string txt; cin >> txt;
        if(KMP(txt, root)) cout << "YES\n";
        else cout << "NO\n";
    }
}
/** 표준입력
 * (패턴 문자열 개수만큼의 정수)
 * 패턴 문자열
 * (찾고싶은 검색어 개수만큼의 정수)
 * 검색어
*/