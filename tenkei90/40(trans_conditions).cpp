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

const int MOD = 1e9 + 7;

int main() {
    int k;
    cin >> k;
    vector<ll> dp(k + 10);
    if (k % 9 != 0) {
        cout << 0 << endl;
        return 0;
    }
    dp[0] = 1;
    for (int i = 1 ; i <= k; i++) {
        for (int j = 1; j <= min(i, 9); j++) {
            dp[i] += dp[i - j];
            dp[i] %= MOD;
        }
    }
    cout << dp[k] << endl;
    return 0;
}