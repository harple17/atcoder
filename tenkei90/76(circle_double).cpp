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
    // 連続する部分→累積和sumを作って
    // sum[j]-sum[i - 1]でi~jまでの和がわかる
    int n;
    cin >> n;
    vector<ll> a(2 * n);
    rep(i, n) {
        ll t;
        cin >> t;
        a[i] = a[i + n] = t;
    }
    rep(i, 2 * n - 1) a[i + 1] += a[i];
    bool ans = false;
    if (a[n - 1] % 10 != 0) ans = false;
    else {
        rep(l, n) {
            int r = lower_bound(a.begin(), a.end(), a[l] + a[n - 1] / 10) - a.begin();
            if (10 * a[r] == 10 * a[l] + a[n - 1]) ans = true;
        }
    }
    cout << (ans ? "Yes" : "No") << endl;
    return 0;
}