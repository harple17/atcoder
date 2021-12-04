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
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];
    
    ll l = 0, r = 3e17 / k;
    //ll l = 0, r = 1e18;
    //だとオーバーフローする
    //プロジェクト数のmaxはp = (sigma(a[i]))/k <= 2 * 10 ^5 * 10 ^12 /k
    while (r - l > 1) {
        ll mid = (l + r) / 2;
        ll s = 0;
        for(auto e: a) s += min(mid, e);
        if (s >= mid * k) l = mid;
        else r = mid;
    }
    cout << l << endl;
    return 0;
}