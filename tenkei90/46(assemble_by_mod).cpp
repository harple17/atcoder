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

const int MOD = 46;

int main() {
    int n;
    cin >> n;
    vector<int> a(MOD), b(MOD), c(MOD);
    rep(i, n) {
        int t;
        cin >> t;
        a[t % MOD]++;
    }
    rep(i, n) {
        int t;
        cin >> t;
        b[t % MOD]++;
    }
    rep(i, n) {
        int t;
        cin >> t;
        c[t % MOD]++;
    }
    ll ans = 0;
    rep(i, MOD)rep(j, MOD)rep(k, MOD) {
        if ((i + j + k) % MOD == 0) ans += (ll)(a[i]) * b[j] * c[k];
        //最初にll型にしないとint型がオーバーフローする
    }
    cout << ans << endl;
    return 0;
}