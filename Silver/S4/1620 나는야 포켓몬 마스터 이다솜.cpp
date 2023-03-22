#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int input_dic, problem;
    cin >> input_dic >> problem;
    map<string, int> pokemon_dic;
    map<int, string> reverse_pokemon_dic;
    for(int i = 1; i < input_dic+1; i++){
        string a;
        cin >> a;
        pokemon_dic.insert({a, i});
        reverse_pokemon_dic.insert({i, a});
    }
    for(int i = 0; i < problem; i++){
        string a;
        cin >> a;
        if(atoi(a.c_str()) == 0){
            cout << pokemon_dic.at(a) << '\n';
        }
        else{
            cout << reverse_pokemon_dic.at(atoi(a.c_str())) << '\n';
        }
    }
}