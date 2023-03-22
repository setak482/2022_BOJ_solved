#include <bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    regex reg("(100+1+|01)+");
    smatch mat;
    string str; cin >> str;
    if(regex_match(str, mat, reg)) cout << "SUBMARINE" << '\n';
    else cout << "NOISE" << '\n';
}