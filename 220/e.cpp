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


int main() {
    ll n, d;
    const int MOD = 998244353;
    cin >> n >> d;

    //pre calc
    vector<ll> pow2;
    pow2.push_back(1);
    for (int i = 1; i <= 2 * n + 1; i++) pow2.push_back(pow2[i-1]*2 % MOD);

    ll ans = 0, sum = 0;
    for (int i = n; i >= 1; i--) {
        int dep = n - i;
        if (dep * 2 < d) continue;
        if (dep <= d) {
            if (dep == d) (sum += pow2[d]) %= MOD;
            else if (dep * 2 == d) (sum += pow2[d - 2]) %= MOD;
            else (sum += pow2[d - 1]) %= MOD;
        }
        ans = (ans + sum * pow2[i - 1]) % MOD;
    }
    cout << ans * 2 % MOD << endl;
    return 0;
}