#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> origin;
vector<int> result;

int binary_search(vector<int> &v, int num){
    int first = 0;
    int last = v.size()-1;
    while(first <= last){
        int mid = (first + last) / 2;
        if(v[mid] > num){
            last = mid - 1;
        }
        else if(v[mid] < num){
            first = mid + 1;
        }
        else{
            return 1;
        }
    }
    return 0;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int a;
    cin >> a;
    for(int i = 0; i < a; i++){
        int b;
        cin >> b;
        origin.push_back(b);
        result.push_back(0);
    }
    sort(origin.begin(), origin.end());
    int f;
    cin >> f;
    vector<int> searching;
    for(int i = 0; i < f; i++){
        int c;
        cin >> c;
        searching.push_back(c);
    }
    for(auto& i : searching){
        cout << binary_search(origin, i) << '\n';
    }
}