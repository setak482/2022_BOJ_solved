#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

deque<int> left_swap(deque<int> deque) {
    int a;
    a = deque.front();
    deque.pop_front();
    deque.push_back(a);
    return deque;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int a, b;
    cin >> a >> b;
    deque<int> deq;
    deque<int> result;
    while (a--) {
        deq.push_back(a + 1);
    }
    reverse(deq.begin(), deq.end());
    int cnt = 0;
    while (!deq.empty()) {
        cnt++;
        if (cnt % b != 0) {
            deq = left_swap(deq);
        }
        else if (deq.size() == 1){
            result.push_back(deq.front());
            deq.pop_front();
            break;
        }
        else {
            result.push_back(deq.front());
            deq.pop_front();
        }
    }
    cout << '<';
    for (int i = 0; i < result.size(); i++) {
        if(i != result.size() - 1){
            cout << result[i] << ", ";
        }
        else{
            cout << result[i] << '>';
        }
    }
}