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
    int n;
    cin >> n;
    vector<vector<int>> A(n, vector<int>(6, 0));
    rep(i, n)rep(j, 6) cin >> A[i][j];

    const ll MOD = 1e9 + 7;

    ll ans = 1;
    rep(i, n) {
        ll tmp = 0;
        rep(j, 6) {
            tmp += A[i][j];
            tmp %= MOD;
        }
        ans *= tmp;
        ans %= MOD;
    }
    cout << ans << endl;
    return 0;
}