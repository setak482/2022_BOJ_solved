#include <iostream>
#include <map>
#include <deque>
#include <string>
#include <algorithm>
using namespace std;
int main(){
    map<string, int, less<string>> human;
    int dd, bd;
    cin >> dd >> bd;
    deque<string> result;
    for (int i = 0; i < dd; i++){
        string a;
        cin >> a;
        human.insert({a, 1});
    }
    for (int i = 0; i < bd; i++){
        string a;
        cin >> a;
        if (human.find(a) != human.end()){
            result.push_back(a);
        }
    }
    sort(result.begin(), result.end());
    cout << result.size() << '\n';
    while (!result.empty()){
        cout << result.front() << '\n';
        result.pop_front();
    }
}