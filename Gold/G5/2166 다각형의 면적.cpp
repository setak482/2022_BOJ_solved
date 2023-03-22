#include <bits/stdc++.h>
using namespace std;
int main(){
    vector<pair<double, double>> v;
    int polygon; cin >> polygon;
    for(int i = 0; i < polygon; i++){
        int a, b; cin >> a >> b;
        v.push_back({a,b});
    }
    double resA = 0, resB = 0;
    for(int j = 0; j < polygon-1; j++){
        resA += v[j].first * v[j+1].second;
    }
    resA += v[polygon-1].first * v[0].second;
    for(int j = 0; j < polygon-1; j++){
        resB += v[j].second * v[j+1].first;
    }
    resB += v[polygon-1].second * v[0].first;
    double QED = abs(resB - resA);
    printf("%.1f", QED/2);
}