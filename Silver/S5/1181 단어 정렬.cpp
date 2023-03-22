// https://www.acmicpc.net/problem/1181
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(string a, string b){
    if (a.length() == b.length()) {
        return a < b;
    }
    else{
        return a.length() < b.length();
    }
}

int main() {
    int testcase;
    cin >> testcase;
    vector<string> dic;

    for (int i = 0; i < testcase; i++) {
        string b;
        cin >> b;
        dic.push_back(b);
    }
    // for (int i = dic.size() - 1; i != 0; i--) {
    //     for (int ii = 0; ii < i; ii++) {
    //         string f;
    //         if (dic[ii].size() > dic[ii + 1].size()) {
    //             f = dic[ii];
    //             dic[ii] = dic[ii + 1];
    //             dic[ii + 1] = f;
    //         }
    //     }
    // }
    stable_sort(dic.begin(), dic.end(), compare);
    dic.erase(unique(dic.begin(), dic.end()), dic.end());
    
    for (int i = 0; i < dic.size(); i++) {
        if (i < dic.size() - 1) {
            cout << dic[i] << '\n';
        }
        else {
            cout << dic[i];
        }
    }
}