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
using ull = unsigned long long;
using ll = long long;
using P = pair<int, int>;

const ull MOD = 1e9+7;
ull l, r;
ull pow10[22];

void init() {
    pow10[0] = 1;
    rep(i, 20) pow10[i + 1] = pow10[i] * 10; 
}

ull modpow(ull a, ull b) {
    ull ret = 1;
    while (b > 0) {
        if (b % 2 == 1) {
            ret = ret * (a % MOD) % MOD;
        }
        a = (a % MOD) * (a % MOD) % MOD;;
        b /= 2;
    }
    return ret % MOD;
}

ull Div(ull a, ull b, ull m) {
    return (a * modpow(b, m - 2)) % MOD;
}

ull f(ull x) {
    return Div(((x % MOD) * ((x + 1) % MOD) % MOD), 2, MOD);
}

int main() {
    init();
    cin >> l >> r;
    
    ull ans = 0;
    /**WA
    rep(i, r - l + 1) {
        ans += to_string(i + l).size() * (i + l);
        ans %= MOD;
    }**/

    for (ull i = 1; i <= 19; i++) {
        ull vl = max(l, pow10[i - 1]);
        ull vr = min(r, pow10[i] - 1);
        if (vl > vr) continue;
        //cout << "ok" << endl;
        ans += i * (f(vr) - f(vl - 1) + MOD) % MOD;
        ans %= MOD;
    }
    
    cout << ans << endl;
    return 0;
}