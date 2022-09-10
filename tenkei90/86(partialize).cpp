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
#define rep(i, n) for (ll i=0; i < (n); i++)
#define rep1(i, n, w) for (ll i=0; i < (n); i+=j)
#define rep2(i, s, e, w) for (ll i=s; i < (e); i += w)
using ll = long long;
using P = pair<int, int>;

const ll mod = 1000000007;
const int B = 60;
ll n, q;
int x[100], y[100], z[100];
ll w[100], wb[100];
// wb -> w-binarized

ll bit_ex_search() {
    ll ret = 0;
    rep(i, (1 << n)) {
        // A[j + 1]の今見ているbit目が立っている
        int bit[14];
        rep(j, n) bit[j + 1] = (i / (1 << j)) % 2;

        bool flag = true;
        rep(j, q) {
          	// (bit[x[j]] | bit[y[j]] | bit[z[j]] != wb[j]) flag = false;はWA
            if (((bit[x[j]] | bit[y[j]]) | bit[z[j]]) != wb[j]) flag = false;
        }
        if (flag) ret++;
    }
    return ret;
}

int main() {
    cin >> n >> q;
    rep(i, q) cin >> x[i] >> y[i] >> z[i] >> w[i];

    ll ans = 1;
    rep(i, B) {
        // 条件jにおけるi + 1ビット目を取り出し
        // repの中の文字をつかって計算するときは型に注意(LL化させている)
        rep(j, q) wb[j] = (w[j] / (1LL << i)) % 2;
        ans *= bit_ex_search();
        ans %= mod;
    }
    cout << ans << endl;
    return 0;
}