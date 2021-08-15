#include<bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
using namespace std;
using P = pair<int,int>;

const int mi[] = {1,0,-1,0};
const int mj[] = {0,1,0,-1};

int main() {
    int h,w,ch,cw,dh,dw;
    cin >> h >> w;
    cin >> ch >> cw;
    cin >> dh >> dw;
    ch--;cw--;dh--;dw--;
    vector<string> s(h);
    rep(i,h) cin >> s[i];
    const int INF = 1e6;
    vector<vector<int>> dist(h,vector<int>(w,INF));
    deque<P> deq;
    deq.emplace_front(ch,cw); //init
    dist[ch][cw] = 0; //init
    while(!deq.empty()) {
        int i0 = deq.front().first;
        int j0 = deq.front().second;
        deq.pop_front();
        int d = dist[i0][j0];
        rep(k,4) {
            int i = i0 + mi[k], j = j0 + mj[k];
            if (s[i][j] == '#') continue;
            if (i < 0 || i >= h || j < 0 || j >= w) continue;
            if (dist[i][i] <= d) continue;
            dist[i][j] = d;
            deq.emplace_front(i,j);
        }
        for (int l = -2; l <= 2 ; l++) {
            for (int m = -2; m <= 2 ; m++) {
                int i = i0 + l, j = j0 + m;
                if (s[i][j] == '#') continue;
                if (i < 0 || i >= h || j < 0 || j >= w) continue;
                if (dist[i][j] <= d + 1) continue;
                dist[i][j] = d + 1;
                deq.emplace_back(i,j);
            }
        }
    }
    int ans = dist[dh][dw];
    if (ans == INF) ans = -1;
    cout << ans << endl;
    return 0;
}