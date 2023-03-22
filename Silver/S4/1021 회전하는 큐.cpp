//회전하는 큐 (bj1021)
#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

deque<int> rotate_right(deque<int> deq) {
    for (int i = 0; i < deq.size() - 1; i++) {
        int a = deq.back();
        deq.pop_back();
        deq.push_front(a);
    }
    return deq;
}

deque<int> rotate_left(deque<int> deq) {
    for (int i = 0; i < deq.size() - 1; i++) {
        int a = deq.front();
        deq.pop_front();
        deq.push_back(a);
    }
    return deq;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int deque_size;
    int needs;
    deque<int> source_deque;
    cin >> deque_size >> needs;

    deque<int> needs_deque;
    for (int i = 0; i < needs; i++) {
        int a;
        cin >> a;
        needs_deque.push_back(a);
    }
    for (int i = 1; i < deque_size + 1; i++) {
        source_deque.push_back(i);
    }

    int cnt = 0;
    for (int i = 0; i < needs; i++) {
        int st = needs_deque[i];
        while (st != source_deque.front()) {
            cnt += 1;
            if ((find(source_deque.begin(), source_deque.end(), st) - source_deque.begin()) > abs(find(source_deque.begin(), source_deque.end(), st) - source_deque.end())) {
                source_deque = rotate_left(source_deque);
            }
            else {
                source_deque = rotate_right(source_deque);
            }
        }
        if (st == source_deque.front()) {
            source_deque.pop_front();
            continue;
        }
    }
    cout << cnt;
}