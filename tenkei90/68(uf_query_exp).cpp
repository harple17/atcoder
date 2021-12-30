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
#define rep(i, n) for (int i=0; i < (n); i++)
#define rep1(i, n, w) for (int i=0; i < (n); i+=j)
#define rep2(i, n, w) for (int i=(n); i > 0; i-=j)
#define rep3(i, s, e, j) for (int i=s; i < (e); i += j)
using ll = long long;
using P = pair<int, int>;

class union_find {
private:
    int N;
    vector<int> par;
public:
    union_find(): N(0), par() {}
    union_find(int _N) : N(_N) {
        par.resize(N);
        rep(i, N) par[i] = i;
    }
    int root(int x) {
        if (x == par[x]) return x;
        return par[x] = root(par[x]);
    }
    void link(int x, int y) {
        par[root(x)] = root(y);
    }
    bool connected(int x, int y) {
        return root(x) == root(y);
    }
};

int main() {
    int n, q;
    cin >> n >> q;
    vector<int> t(q), x(q), y(q), v(q);
    rep(i, q) {
        cin >> t[i] >> x[i] >> y[i] >> v[i];
        x[i]--; y[i]--;
    }

    vector<int> sumOfTwo(n - 1);
    rep(i, q) if(t[i] == 0)sumOfTwo[x[i]] = v[i];

    // a[0] = 0とした場合にとる値
    // v[i] <= 2e9なのでlong longじゃないと後の足し算でオーバーフローする
    vector<ll> ptntl(n);
    rep(i, n - 1) ptntl[i + 1] = sumOfTwo[i] - ptntl[i];

    union_find uf(n);

    rep(i, q) {
        if (t[i] == 0) uf.link(x[i], y[i]);
        else {
            if (!uf.connected(x[i], y[i])) cout << "Ambiguous" << endl;
            // 偶奇が同じなら同じように足し引き去れるので差が不変
            else if ((x[i] + y[i]) % 2 == 0) cout << v[i] + (ptntl[y[i]] - ptntl[x[i]]) << endl; 
            // 偶奇が異なるなら足した分引かれるので和が不変
            // int型のオーバーフローに注意
            else cout << (ptntl[y[i]] + ptntl[x[i]]) - v[i] << endl; 
        }
    }

    return 0;
}