#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i < (n); i++)
using ll = long long;
using P = pair<int, int>;

int main() {
    int n,m;
    cin >> n >> m;
    vector<vector<int>> G(n);
    rep(i,m) {
        int a,b;
        cin >> a >> b;
        a--;b--;
        G[a].push_back(b);
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
            for (int to : G[v]) {
                if (dist[to] == INF) {
                    dist[to] = dist[v] + 1;
                    q.push(to);
                }
            }
        }
    };
    int ans = 0;
    rep(i,n) {
        bfs(i);
        rep(j,n) {
            if(dist[j]!=INF) ans++;
        }
    }
    cout << ans << endl;
    return 0;
}