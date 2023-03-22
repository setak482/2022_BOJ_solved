#include <bits/stdc++.h>
using namespace std;
struct node{
    int data;
    node* right;
    node* left;
};
node* insert(node* &n, int val){
    if(n == NULL){
        n = new node;
        n->data = val;
        n->right = NULL;
        n->left = NULL;
    }
    else{
        if(val < n->data) insert(n->left, val);
        else insert(n->right, val);
    }
    return n;
}
void postorder(node* n){
    if(n != NULL){
        postorder(n->left);
        postorder(n->right);
        cout << n->data << '\n';
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    node* root = NULL;
    int a;
    while(!cin.eof() && cin >> a){
        insert(root, a);
    }
    postorder(root);
}