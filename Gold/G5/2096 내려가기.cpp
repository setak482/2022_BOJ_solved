#include <bits/stdc++.h>
#define tri 3
using namespace std;
int main(){
    int N, p, q, maxdp[tri], mindp[tri], temp[tri];
    cin >> N >> maxdp[0] >> maxdp[1] >> maxdp[2];
    memcpy(mindp, maxdp, sizeof(maxdp));
    for(int i = 0; i < N-1; i++){
        cin >> temp[0] >> temp[1] >> temp[2];
        p = maxdp[0], q = maxdp[2];
        maxdp[0] = max(maxdp[0], maxdp[1]) + temp[0];
        maxdp[2] = max(maxdp[1], maxdp[2]) + temp[2];
        maxdp[1] = max(max(p, maxdp[1]), q) + temp[1];
        p = mindp[0], q = mindp[2];
        mindp[0] = min(mindp[0], mindp[1]) + temp[0];
        mindp[2] = min(mindp[1], mindp[2]) + temp[2];
        mindp[1] = min(min(p, mindp[1]), q) + temp[1];
    }
    cout << max(max(maxdp[0], maxdp[1]), maxdp[2]) << ' ' <<
            min(min(mindp[0], mindp[1]), mindp[2]);
}