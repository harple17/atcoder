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
    ll n;
    cin >> n;
    // 素因数分解は√n近くの約数で割ることで二分木にできる
    vector<ll> prime;
    for (ll i = 2; i * i <= n; i++) {
        while (n % i == 0) {
            n /= i;
            prime.push_back(i);
        }
    }
    if (n != 1) prime.push_back(n);
    int ans = 0;
    while((1 << ans) < prime.size()) ans++;
    cout << ans << endl;
    return 0;
}