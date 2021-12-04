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
const int MOD = 1e9 + 7;

ll binpower(ll n, ll m, ll p) {
    ll ret = 1;
    while (m > 0) {
        if (m % 2 == 1) ret = ((n % p) * ret) % p;
        n = ((n % p) * (n % p)) % p;
        m /= 2;
    }
    return ret % p;
}
int main() {
    ll n, k;
    cin >> n >> k;
    if (k == 1) {
        cout << (n == 1? 1 : 0) << endl;
    } else if (n == 1) {
        cout << k % MOD << endl;
    } else if (n == 2) {
        cout << k * (k - 1) % MOD << endl;
    } else {
        cout << k * (k - 1) % MOD * binpower(k - 2, n - 2, MOD) % MOD << endl;
    }
    return 0;
}