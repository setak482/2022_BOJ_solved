#include <bits/stdc++.h>
using namespace std;
string memo[101][101];
string big_int_plus(string a, string b){
    int sum = 0;
    string result;
    while(!a.empty() || !b.empty() || sum){
        if(!a.empty()){
            sum += a.back() - '0';
            a.pop_back();
        }
        if(!b.empty()){
            sum += b.back() - '0';
            b.pop_back();
        }
        result.push_back((sum % 10) + '0');
        sum /= 10;
    }
    reverse(result.begin(), result.end());
    return result;
}

string combination(int n, int r){
    if(n == r || r == 0) return "1";
    string &result = memo[n][r];
    if(result != "") return result;
    result = big_int_plus(combination(n-1, r-1), combination(n-1, r));
    return result;
}

int main(){
    int a, b; cin >> a >> b;
    cout << combination(a, b);
}