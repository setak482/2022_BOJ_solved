#include <bits/stdc++.h>
using namespace std;
int main(){
    map<string, int> trees;
    string temp;
    double entire = 0;
    while(getline(cin, temp)){
        if(!trees.count(temp)){
            trees.insert({temp, 1});
            entire++;
        }
        else{
            trees[temp]++;
            entire++;
        }
    }
    for(auto& i : trees){
        double value = (double(i.second) / entire) * 100;
        cout<<fixed;
        cout.precision(4);
        cout << i.first << ' ' << value << '\n';
    }
}