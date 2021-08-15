#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i < (n); i++)
using ll = long long;
using P = pair<ll, int>;

struct E {
    int to, t, k;
    E(int to, int t, int k): to(to), t(t), k(k) {}
};

int main() {
    int n, m, x, y;
    cin >> n >> m >> x >> y;
    x--; y--;
    vector<vector<E>> G(n);
    rep(i,m) {
        int a, b, t, k;
        cin >> a >> b >> t >> k;
        a--; b--;
        G[a].emplace_back(b,t,k);
        G[b].emplace_back(a,t,k);
    }
    const ll INF = 2*1e17; // max(t)*max(n)*2(miss the train)
    vector<ll> dist(n, INF);
    priority_queue<P, vector<P>, greater<P>> Q;
    auto push = [&](int v, ll c) {
        if (dist[v] <= c) return;
        dist[v] = c;
        Q.emplace(c, v);
    };
    push(x,0);
    while(!Q.empty()) {
        auto [co, dest] = Q.top(); Q.pop();
        if (dist[dest] != co) continue;
        for (E& e: G[dest]) {
            ll d = (co+e.k-1)/e.k*e.k+e.t;
            push(e.to,d);
        }
    }
    ll ans = dist[y];
    if (ans == INF) ans = -1;
    cout << ans << endl;
    return 0;
}