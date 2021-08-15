#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i < (n); i++)
using ll = long long;
using P = pair<int, int>;

int main() {
    int r, c;
    cin >> r >> c;
    vector<vector<int>> a(r, vector<int>(c-1));
    vector<vector<int>> b(r-1, vector<int>(c));
    rep(i,r)rep(j,c-1) cin >> a[i][j];
    rep(i,r-1)rep(j,c) cin >> b[i][j];
    const int INF = 10000000;
    vector<int> dist(2*r*c, INF);
    priority_queue<P, vector<P>, greater<P>> q;
    auto push = [&](int i, int j, int k, int x) {
        int v = 2*i*c + 2*j + k;
        if(dist[v] > x) {
            dist[v] = x;
            q.emplace(x, v); 
        }
    };
    push(0, 0, 0, 0);
    while(!q.empty()) {
        auto [x, v] = q.top(); q.pop();
        if (dist[v] != x) continue;
        int i = v/(2*c);
        int j = v/2%c;
        int k = v%2;
        if (k == 0) {
            if (j+1 < c) push(i, j+1, k, x+a[i][j]);
            if (j > 0) push(i, j-1, k, x+a[i][j-1]);
            if (i+1 < r) push(i+1, j, k, x+b[i][j]);
            push(i, j, 1, x+1);
        } else {
            if (i > 0) push(i-1, j, k, x+1);
            push(i, j, 0, x);
        }
    }
    cout << dist[2*(r*c-1)] << endl;
    return 0;
}