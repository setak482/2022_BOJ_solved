#include <iostream>
#include <set>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    multiset<int> heap;
    int tc, cnt = 0; cin >> tc;
    for(int i = 0; i < tc; i++){
        int a; cin >> a;
        if(a == 0){
            if(heap.empty()){
                cout << 0 << '\n';
            }
            else{
                cout << *heap.begin() << '\n';
                heap.erase(heap.begin());
            }
        }
        else{
            heap.insert(a);
        }
    }
}