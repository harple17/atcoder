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

int main() {
    int n, q;
    cin >> n >> q;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];
    vector<ll> E(n);
    ll ans = 0;
    rep(i, n - 1) {
        E[i] = a[i] - a[i + 1];
        ans += abs(E[i]);
    }

    rep(i, q) {
        int l, r;
        cin >> l >> r;
        l--; r--;
        ll v;
        cin >> v;
        ll pre = abs(E[l - 1]) + abs(E[r]);
        if (l > 0) E[l - 1] -= v;
        if (r < n - 1) E[r] += v;
        ll nex = abs(E[l - 1]) + abs(E[r]);
        ans += (nex - pre);
        cout << ans << endl;
    }
    
    return 0;
}