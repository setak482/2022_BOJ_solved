#include <bits/stdc++.h>
using namespace std;
int lcm(int a, int b){
    return (a*b)/__gcd(a, b);
}
int main(){
    int a, b; cin >> a >> b;
    int G = __gcd(a, b);
    cout << G << '\n';
    cout << lcm(a, b);
}