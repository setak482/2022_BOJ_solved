#include <bits/stdc++.h>
using namespace std;
int cnt = 0;
void move(int from, int to){
    cout << from << " " << to << '\n';
}
void hanoi(int n, int from, int by, int to){
    if(n == 0) return;
    hanoi(n - 1, from, to, by);
    move(from, to);
    hanoi(n - 1, by, from, to);
}
int main(){
	int N; cin >> N;
	cout << (int)pow(2, N)-1 << '\n';
	hanoi(N, 1, 2, 3);
} 