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
#define rep2(i, s, e, w) for (int i=s; i < (e); i += w)
using ll = long long;
using P = pair<int, int>;
const ll N_MAX = 45;

ll n, p, k, A[N_MAX][N_MAX];
const ll COST_MAX = 40*1e8;

ll dist[N_MAX][N_MAX];

ll count_number(ll x) {
    rep(i, n)rep(j, n) {
        if (A[i][j] == -1) dist[i][j] = x;
        else dist[i][j] = A[i][j];
    }
    // Floyd-Warshall Algorithm
    rep(i, n)rep(j, n)rep(k, n) {
        dist[j][k] = min(dist[j][k], dist[j][i] + dist[i][k]);
    }
    ll ret = 0;
    rep(i, n)for(int j = i + 1; j < n; j++) {
        if (dist[i][j] <= p) ret++;
    }
    return ret;
}

ll get_border(ll cnt) {
    ll l = 1, r = 5e9;
    // 普通のにぶたんと同じくl-r > 1にすると、
    // やりすぎる
    rep(i, 40) {
        ll mid = (l + r) / 2;
        ll pth = count_number(mid);
        if (pth <= cnt) r = mid;
        else l = mid; 
    }
    return r;
}

int main() {
    cin >> n >> p >> k;
    rep(i, n)rep(j, n) cin >> A[i][j];

    ll xl = get_border(k);
    ll xr = get_border(k - 1);
    if (xr - xl >= COST_MAX) cout << "Infinity" << endl;
    else cout << xr - xl << endl;
    return 0;
}