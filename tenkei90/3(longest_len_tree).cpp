#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i < (n); i++)
using ll = long long;
using P = pair<int, int>;

int main() {
    int n;
    cin >> n;
    vector<vector<int>> d(n);
    rep(i,n-1){ //nじゃダメ(なんで？？)
        int a0,b0;
        cin >> a0 >> b0;
        a0--; b0--; //0-indexed
        d[a0].push_back(b0);
        d[b0].push_back(a0);
    }
    queue<int> q;
    const int INF = 10000000;
    vector<int> dist(n);
    auto bfs = [&](int start) {
        rep(i,n) dist[i] = INF; //二回使う
        q.push(start);
        dist[start] = 0;
        while(!q.empty()) {
            int v = q.front(); q.pop();
            for (int to : d[v]) {
                if (dist[to] == INF) {
                    dist[to] = dist[v] + 1;
                    q.push(to);
                }
            }
        }
    };
    bfs(0);
    int max_l0 = -1, max_id0 = -1; 
    rep(i,n) {
        if (max_l0 < dist[i]) {
            max_l0 = dist[i];
            max_id0 = i;
        }
    }
    bfs(max_id0);
    int ans = -1;
    rep(i,n) {
        ans = max(ans, dist[i]);
    }
    cout << ans + 1 << endl;
    return 0;
}