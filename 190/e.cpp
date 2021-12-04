//include libraries
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <valarray>
#include <string>
#include <typeinfo>
#include <utility>
#include <vector>
using namespace std;
#define rep(i,n) for (int i=0; i < (n); i++)
using ll = long long;
using P = pair<int, int>;

void chmin(int &x, int y) {
    x = min(x, y);
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> to(n); //隣接行列(ジャグ配列)
    rep(i,m) {
        int a, b;
        cin >> a >> b;
        a--; b--; //to 0-indexed
        to[a].push_back(b);
        to[b].push_back(a);
    }
    int k;
    cin >> k;
    vector<int> c(k);
    rep(i,k) {
        cin >> c[i];
        c[i]--; //to 0-indexed
    }

    //depth-first search
    const int INF = 1000000001;
    auto dfs = [&](int sv) { //start vertex
        vector<int> dist(n, INF);
        queue<int> q;
        dist[sv] = 0;
        q.push(sv);
        while(!q.empty()) {
            int v = q.front();
            q.pop();
            for (int u : to[v]) {
                if (dist[u] != INF) continue;
                dist[u] = dist[v] + 1;
                q.push(u); 
            }
        }
        return dist;
    };

    vector<vector<int>> dist(k, vector<int>(k));
    rep(i,k) {
        vector<int> d = dfs(c[i]); //shortest distances from c[i] to all of v that c[i] can go to. 
        rep(j,k) dist[i][j] = d[c[j]]; //shortest distances from c[i] to c[j]
    }

    vector<vector<int>> dp(1<<k, vector<int>(k, INF));
    rep(i,k) dp[1<<i][i] = 1; //iに訪れてiにいる時魔法石は1個
    rep(s,1<<k) {
        rep(i,k) {
            if (~s>>i&1) continue; //今iにいるのにiには訪れてないとき
            rep(j,k) {
                if(s>>j&1) continue; //今からjに行くのにjに既に訪れているとき※重要な頂点cは二回訪れるとループになるのでおかしい
                chmin(dp[s|1<<j][j], dp[s][i]+dist[i][j]);
            }
        }
    }
    int ans = INF;
    rep(i,k) chmin(ans, dp[(1<<k)-1][i]);
    if (ans == INF) ans = -1;
    cout << ans << endl;
    return 0;
}