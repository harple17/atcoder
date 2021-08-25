//include libraxes
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

class UnionFind {
    public:
    vector<int> par;

    void init(int size) {
        par.resize(size, -1);
    }

    int root(int node) {
        if (par[node] == -1) return node;
        par[node] = root(par[node]);
        return par[node];
    }

    void unite(int u, int v) {
        u = root(u);
        v = root(v);
        if (u==v) return;
        par[v] = u;
    }

    bool same(int u, int v) {
        if (root(u)==root(v)) return true;
        else return false;
    }
};

/**
 * @brief 問題のx,y座標の設定に注意
 * 今回は普通のx,y軸と設定が逆(縦:x軸, 横:y軸)
 * 
 */

bool Visited[2010][2010];
int h,w;
UnionFind UF;

void q1(int x, int y) {
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, -1, 0, 1};
    rep(i,4) {
        //受け取った四方のマスのうち、赤に塗られたものを結合
        int px = x + dx[i], py = y + dy[i];
        if (Visited[px][py] == false) continue;
        int h1 = px * w + py;
        int h2 = x * w + y;
        if (h1 > h*w - 1 || h2 > h*w - 1 || px < 0 || py < 0) continue;
        UF.unite(h1, h2);
    }
    Visited[x][y] = true;
}

bool q2(int x1, int y1, int x2, int y2) {
    if (Visited[x1][y1] == false || Visited[x2][y2] == false) return false;
    int h1 = x1 * w + y1;
    int h2 = x2 * w + y2;
    if (UF.same(h1, h2)) return true;
    else return false;
}

int main() {
    cin >> h >> w;
    int q;
    cin >> q;

    UF.init(h*w);

    rep(i,q) {
        int query;
        cin >> query;
        if (query == 1) {
            int x, y;
            cin >> x >> y;
            q1(x-1,y-1);
        } else {
            int x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;
            if (q2(x1-1, y1-1, x2-1, y2-1)) cout << "Yes" << endl;
            else cout << "No" << endl;
        }
    }
    return 0;
}