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
using P = pair<ll, int>;

struct Elm {
    int to; ll cost;
    Elm(int to, ll cost): to(to), cost(cost) {}
};

int main() {
    int n,m;
    cin >> n >> m;
    vector<vector<Elm>> G(n);
    rep(i,m) {
        int a,b,c;
        cin >> a >> b >> c;
        a--; b--;
        G[a].emplace_back(b,c);
        G[b].emplace_back(a,c);
    }

    //pair型は最初からoperatorが定義されているので
    //greaterがそのまま使用可能
    priority_queue<P, vector<P>, greater<P>> PQ;
    const ll INF = 1e9+7;
    vector<ll> dist1(n, INF), dist2(n, INF);

    //vectorは配列と異なり、デフォルトで値渡し(コピー)
    //参照渡しされない
    auto push = [&](int v, ll c, vector<ll> &dist) {
        //cout << "v:" << v << " " << "c:" << c << endl;
        if (dist[v] <= c) return;
        dist[v] = c;
        PQ.emplace(c, v);
    }; 

    push(0, 0, dist1);
    while (!PQ.empty()) {
        auto [c, t] = PQ.top(); PQ.pop();
        if (dist1[t] != c) continue;
        for (Elm& e: G[t]) {
            push(e.to, c + e.cost, dist1);
        }
    }
    push(n-1, 0, dist2);
    while (!PQ.empty()) {
        auto [c, t] = PQ.top(); PQ.pop();
        if (dist2[t] != c) continue;
        for (Elm& e: G[t]) {
            push(e.to, c + e.cost, dist2);
        }
    }

    rep(i,n) cout << dist1[i] + dist2[i] << endl;

    return 0;
}