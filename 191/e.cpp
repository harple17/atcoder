#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i < (n); i++)
using ll = long long;
using P = pair<int, int>;

//if there are start, end and cost, by making graph the problem would be solved

//an e(lement) has destination(to) and cost(c).
struct E {
    int to, c;
    E (int to=0, int c=0): to(to), c(c) {}
};

int main() {
    int n,m;
    cin >> n >> m;
    vector<vector<E>> G(n);
    rep(i,m) {
        int a,b,c;
        cin >> a >> b >> c;
        a--; b--;
        G[a].emplace_back(b,c);
    }
    const int INF = 10000001;
    rep(sv,n) {
        vector<int> dist(n,INF);
        priority_queue<P, vector<P>, greater<P>> PQ;
        auto push = [&](int d, int v) {
            if (dist[v] > d) {
                dist[v] = d;
                PQ.emplace(d,v);
            }
        };
        for(auto&& e : G[sv]) push(e.c,e.to);
        while(!PQ.empty()) {
            auto [d,v] = PQ.top(); PQ.pop();
            if (dist[v] != d) continue; //https://youtu.be/iEfDi7wagfE?t=10211
            for (auto&& e : G[v]) push(e.c+dist[v],e.to);
        }
        int ans = dist[sv];
        if (ans == INF) ans = -1;
        cout << ans << endl;
    }
    return 0;
}