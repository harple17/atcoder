#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i < (n); i++)
using ll = long long;
using P = pair<ll, int>;

struct E {
    int to, c, d;
    E(int to, int c, int d): to(to), c(c), d(d) {}
};

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<E>> G(n);
    rep(i,m) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        a--; b--;
        G[a].emplace_back(b,c,d);
        G[b].emplace_back(a,c,d);
    }
    const ll INF = 2*1e17; // max(t)*max(n)*2(miss the train)
    vector<ll> dist(n, INF);
    priority_queue<P, vector<P>, greater<P>> Q;
    auto push = [&](int v, ll c) {
        if (dist[v] <= c) return;
        dist[v] = c;
        Q.emplace(c, v);
    };
    push(0,0);
    while(!Q.empty()) {
        auto [co, dest] = Q.top(); Q.pop();
        if (dist[dest] != co) continue;
        for (E& e: G[dest]) {
            ll di = co+(e.c+(e.d/(co+1)));
            push(e.to,di);
        }
    }
    ll ans = dist[n-1];
    if (ans == INF) ans = -1;
    cout << ans << endl;
    return 0;
}