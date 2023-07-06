#include <bits/stdc++.h>
#define um unordered_map
using namespace std;
string reverse_pokemon_dic[100001];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int input_dic, problem;
    cin >> input_dic >> problem;
    um<string, int> pokemon_dic;
    for(int i = 1; i <= input_dic; i++){
        string a;
        cin >> a;
        pokemon_dic.insert({a, i});
        reverse_pokemon_dic[i] = a;
    }
    for(int i = 0; i < problem; i++){
        string a; cin >> a;
        if(atoi(a.c_str()) == 0)
            cout << pokemon_dic.at(a) << '\n';
        else cout << reverse_pokemon_dic[atoi(a.c_str())] << '\n';
    }
}