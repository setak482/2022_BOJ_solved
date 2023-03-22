#include <bits/stdc++.h>
using namespace std;
char alph_tree[26][2] = {'0', }; // left : 0, right : 1
void preorder(int lv){
    if(lv<0) return;
    printf("%c", lv+65);
    preorder(int(alph_tree[lv][0])-65);
    preorder(int(alph_tree[lv][1])-65);
    return;
}
void inorder(int lv){
    if(lv<0) return;
    inorder(int(alph_tree[lv][0])-65);
    printf("%c", lv+65);
    inorder(int(alph_tree[lv][1])-65);
    return;
}
void postorder(int lv){
    if(lv<0) return;
    postorder(int(alph_tree[lv][0])-65);
    postorder(int(alph_tree[lv][1])-65);
    printf("%c", lv+65);
    return;
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tc; cin >> tc;
    for(int i = 0; i < tc; i++){
        char a, b, c; cin >> a >> b >> c;
        int idx = int(a) - int('A');
        if(b != '.') alph_tree[idx][0] = b;
        if(c != '.') alph_tree[idx][1] = c;
    }
    preorder(0); printf("\n");
    inorder(0); printf("\n");
    postorder(0);
}